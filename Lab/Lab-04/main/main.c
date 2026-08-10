// =============================================================
//  Lab 6-4: IoT Sensor Dashboard
//  ESP32 SoftAP + FreeRTOS Queue + HTTP Web Server
//
//  Architecture:
//    vSensorTask   → xQueueSend()    → FreeRTOS Queue
//    vNetworkTask  ← xQueueReceive() ← FreeRTOS Queue
//    vNetworkTask  → Mutex Lock → update g_latest_data → Mutex Unlock
//    HTTP Handler  → Mutex Lock → read  g_latest_data → Mutex Unlock
//    Browser       ← GET /           ← HTML Dashboard (Auto-refresh 2s)
//    Browser       ← GET /api/data   ← JSON response
// =============================================================

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "esp_event.h"
#include "esp_http_server.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_random.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

// =============================================================
//  Tags (แยก Tag เพื่อให้อ่าน Log ได้ง่าย)
// =============================================================
static const char *TAG_AP     = "SOFTAP";
static const char *TAG_SENS   = "SENSOR_TASK";
static const char *TAG_NET    = "NETWORK_TASK";
static const char *TAG_HTTP   = "HTTP_SERVER";
static const char *TAG_STACK  = "FORENSIC_STACK";

// =============================================================
//  Configuration
// =============================================================
#define AP_SSID            "ESP32_AP_0323"
#define AP_PASS            "12345678"
#define AP_MAX_CONN        4
#define SENSOR_INTERVAL_MS 1500

// =============================================================
//  Sensor Data Structure (เหมือนกับ Lab 6-3)
// =============================================================
typedef struct {
    float    temperature;
    float    humidity;
    uint32_t light_lux;
    uint32_t timestamp_ms;
} sensor_data_t;

// =============================================================
//  Shared State — ป้องกันด้วย Mutex
// =============================================================
static sensor_data_t    g_latest_data = {0};
static SemaphoreHandle_t g_data_mutex  = NULL;

// =============================================================
//  FreeRTOS Queue Handle
// =============================================================
static QueueHandle_t xSensorQueue = NULL;

// =============================================================
//  Wi-Fi Event Handler (SoftAP)
// =============================================================
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                                int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT) {
        if (event_id == WIFI_EVENT_AP_STACONNECTED) {
            wifi_event_ap_staconnected_t *event = event_data;
            ESP_LOGI(TAG_AP, "=======================================================");
            ESP_LOGI(TAG_AP, "[FORENSIC EVENT]: Client Connected to SoftAP!");
            ESP_LOGI(TAG_AP, "  -> Client MAC : %02X:%02X:%02X:%02X:%02X:%02X",
                     event->mac[0], event->mac[1], event->mac[2],
                     event->mac[3], event->mac[4], event->mac[5]);
            ESP_LOGI(TAG_AP, "  -> AID        : %d", event->aid);
            ESP_LOGI(TAG_AP, "=======================================================");
        } else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) {
            wifi_event_ap_stadisconnected_t *event = event_data;
            ESP_LOGW(TAG_AP, "=======================================================");
            ESP_LOGW(TAG_AP, "[FORENSIC EVENT]: Client Disconnected from SoftAP!");
            ESP_LOGW(TAG_AP, "  -> Client MAC : %02X:%02X:%02X:%02X:%02X:%02X",
                     event->mac[0], event->mac[1], event->mac[2],
                     event->mac[3], event->mac[4], event->mac[5]);
            ESP_LOGW(TAG_AP, "  -> AID        : %d", event->aid);
            ESP_LOGW(TAG_AP, "=======================================================");
        }
    }
}

// =============================================================
//  HTTP Handler: GET /api/data  →  JSON
// =============================================================
static esp_err_t api_data_handler(httpd_req_t *req)
{
    ESP_LOGI(TAG_HTTP, "[FORENSIC]: GET /api/data requested");

    sensor_data_t snapshot;

    // --- Critical Section: อ่าน g_latest_data อย่างปลอดภัย ---
    if (xSemaphoreTake(g_data_mutex, pdMS_TO_TICKS(100)) == pdTRUE) {
        snapshot = g_latest_data;
        xSemaphoreGive(g_data_mutex);
        ESP_LOGI(TAG_HTTP, "[FORENSIC]: Mutex acquired & released for /api/data");
    } else {
        ESP_LOGW(TAG_HTTP, "[FORENSIC]: Mutex timeout! Sending stale/zero data");
        memset(&snapshot, 0, sizeof(snapshot));
    }

    char json_buf[256];
    snprintf(json_buf, sizeof(json_buf),
             "{\"temperature\":%.2f,\"humidity\":%.2f,"
             "\"light_lux\":%lu,\"timestamp_ms\":%lu}",
             snapshot.temperature, snapshot.humidity,
             snapshot.light_lux, snapshot.timestamp_ms);

    httpd_resp_set_type(req, "application/json");
    httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
    httpd_resp_send(req, json_buf, HTTPD_RESP_USE_STRLEN);

    ESP_LOGI(TAG_HTTP, "[FORENSIC]: Response sent: %s", json_buf);
    return ESP_OK;
}

// =============================================================
//  HTTP Handler: GET /  →  HTML Dashboard
// =============================================================
static esp_err_t dashboard_handler(httpd_req_t *req)
{
    ESP_LOGI(TAG_HTTP, "[FORENSIC]: GET / (Dashboard) requested");

    // HTML หน้า Dashboard — Auto-refresh ทุก 2 วินาทีผ่าน JavaScript fetch()
    const char *html =
        "<!DOCTYPE html><html lang='th'>"
        "<head>"
        "<meta charset='UTF-8'>"
        "<meta name='viewport' content='width=device-width,initial-scale=1'>"
        "<title>ESP32 Sensor Dashboard</title>"
        "<style>"
        "  *{box-sizing:border-box;margin:0;padding:0}"
        "  body{font-family:'Segoe UI',sans-serif;background:#0f172a;color:#e2e8f0;min-height:100vh;display:flex;align-items:center;justify-content:center;}"
        "  .container{width:100%;max-width:480px;padding:20px;}"
        "  h1{text-align:center;font-size:1.4rem;color:#38bdf8;margin-bottom:4px;}"
        "  .subtitle{text-align:center;font-size:.8rem;color:#64748b;margin-bottom:24px;}"
        "  .cards{display:grid;grid-template-columns:1fr 1fr;gap:14px;}"
        "  .card{background:#1e293b;border-radius:16px;padding:20px;text-align:center;border:1px solid #334155;}"
        "  .card .icon{font-size:2rem;margin-bottom:8px;}"
        "  .card .label{font-size:.75rem;color:#94a3b8;text-transform:uppercase;letter-spacing:.05em;}"
        "  .card .value{font-size:2rem;font-weight:700;color:#f1f5f9;margin:4px 0;}"
        "  .card .unit{font-size:.85rem;color:#64748b;}"
        "  .ts{text-align:center;margin-top:16px;font-size:.75rem;color:#475569;}"
        "  .dot{display:inline-block;width:8px;height:8px;border-radius:50%;background:#22c55e;margin-right:6px;animation:blink 1s infinite;}"
        "  @keyframes blink{0%,100%{opacity:1}50%{opacity:.3}}"
        "</style>"
        "</head>"
        "<body>"
        "<div class='container'>"
        "  <h1>🌐 ESP32 Sensor Dashboard</h1>"
        "  <p class='subtitle'><span class='dot'></span>Lab 6-4 · FreeRTOS Queue + HTTP Server</p>"
        "  <div class='cards'>"
        "    <div class='card'><div class='icon'>🌡️</div><div class='label'>Temperature</div>"
        "      <div class='value' id='temp'>--</div><div class='unit'>°C</div></div>"
        "    <div class='card'><div class='icon'>💧</div><div class='label'>Humidity</div>"
        "      <div class='value' id='hum'>--</div><div class='unit'>%</div></div>"
        "    <div class='card'><div class='icon'>☀️</div><div class='label'>Light</div>"
        "      <div class='value' id='lux'>--</div><div class='unit'>lux</div></div>"
        "    <div class='card'><div class='icon'>⏱️</div><div class='label'>Uptime</div>"
        "      <div class='value' id='ts'>--</div><div class='unit'>ms</div></div>"
        "  </div>"
        "  <p class='ts' id='updated'>Waiting for data...</p>"
        "</div>"
        "<script>"
        "function refresh(){"
        "  fetch('/api/data').then(r=>r.json()).then(d=>{"
        "    document.getElementById('temp').textContent=d.temperature.toFixed(1);"
        "    document.getElementById('hum').textContent=d.humidity.toFixed(1);"
        "    document.getElementById('lux').textContent=d.light_lux;"
        "    document.getElementById('ts').textContent=d.timestamp_ms;"
        "    document.getElementById('updated').textContent='Last updated: '+new Date().toLocaleTimeString();"
        "  }).catch(()=>{document.getElementById('updated').textContent='Connection error...';});"
        "}"
        "refresh();setInterval(refresh,2000);"
        "</script>"
        "</body></html>";

    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, html, HTTPD_RESP_USE_STRLEN);

    ESP_LOGI(TAG_HTTP, "[FORENSIC]: HTML Dashboard sent (%d bytes)", strlen(html));
    return ESP_OK;
}

// =============================================================
//  Start HTTP Server
// =============================================================
static void start_http_server(void)
{
    ESP_LOGI(TAG_HTTP, "[FORENSIC]: Call httpd_start()");
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    if (httpd_start(&server, &config) != ESP_OK) {
        ESP_LOGE(TAG_HTTP, "[FORENSIC]: httpd_start() FAILED");
        return;
    }

    httpd_uri_t uri_dashboard = {
        .uri     = "/",
        .method  = HTTP_GET,
        .handler = dashboard_handler,
    };
    httpd_uri_t uri_api = {
        .uri     = "/api/data",
        .method  = HTTP_GET,
        .handler = api_data_handler,
    };
    httpd_register_uri_handler(server, &uri_dashboard);
    httpd_register_uri_handler(server, &uri_api);

    ESP_LOGI(TAG_HTTP, "=======================================================");
    ESP_LOGI(TAG_HTTP, "[HTTP SERVER]: Started successfully");
    ESP_LOGI(TAG_HTTP, "  -> Dashboard : http://192.168.4.1/");
    ESP_LOGI(TAG_HTTP, "  -> JSON API  : http://192.168.4.1/api/data");
    ESP_LOGI(TAG_HTTP, "=======================================================");
}

// =============================================================
//  Task 1: Sensor Collector Task
//  จำลองการอ่านค่าเซนเซอร์ และส่งเข้า FreeRTOS Queue ทุก 1.5 วินาที
// =============================================================
static void vSensorTask(void *pvParameters)
{
    sensor_data_t data;
    ESP_LOGI(TAG_SENS, "[FORENSIC]: Sensor Collector Task started on Core %d", xPortGetCoreID());

    while (1) {
        // จำลองค่าเซนเซอร์
        data.temperature  = 25.0f + (esp_random() % 100) / 10.0f;
        data.humidity     = 50.0f + (esp_random() % 200) / 10.0f;
        data.light_lux    = 200   + (esp_random() % 500);
        data.timestamp_ms = xTaskGetTickCount() * portTICK_PERIOD_MS;

        ESP_LOGI(TAG_SENS, "[SENSOR TASK]: Pushing -> Temp: %.1f C, Hum: %.1f %%, Lux: %lu",
                 data.temperature, data.humidity, data.light_lux);

        // ส่งเข้า Queue (timeout 100ms)
        if (xQueueSend(xSensorQueue, &data, pdMS_TO_TICKS(100)) != pdPASS) {
            ESP_LOGW(TAG_SENS, "[QUEUE WARNING]: Queue Full! Data dropped.");
        }

        // Forensic Stack Monitor
        UBaseType_t hwm = uxTaskGetStackHighWaterMark(NULL);
        ESP_LOGI(TAG_STACK, "  -> SensorTask Stack Remaining: %u words (%u bytes)",
                 hwm, hwm * sizeof(StackType_t));

        vTaskDelay(pdMS_TO_TICKS(SENSOR_INTERVAL_MS));
    }
}

// =============================================================
//  Task 2: Network Task
//  รับข้อมูลจาก Queue → อัพเดต g_latest_data ด้วย Mutex
// =============================================================
static void vNetworkTask(void *pvParameters)
{
    sensor_data_t rx_data;
    ESP_LOGI(TAG_NET, "[FORENSIC]: Network Task started on Core %d", xPortGetCoreID());

    while (1) {
        // บล็อกรอข้อมูลจาก Queue (ไม่จำกัดเวลา)
        if (xQueueReceive(xSensorQueue, &rx_data, portMAX_DELAY) == pdTRUE) {
            ESP_LOGI(TAG_NET, "=======================================================");
            ESP_LOGI(TAG_NET, "[NETWORK TASK]: Data Received from Queue!");
            ESP_LOGI(TAG_NET, "  -> Timestamp   : %lu ms", rx_data.timestamp_ms);
            ESP_LOGI(TAG_NET, "  -> Temperature : %.2f degC", rx_data.temperature);
            ESP_LOGI(TAG_NET, "  -> Humidity    : %.2f %%",   rx_data.humidity);
            ESP_LOGI(TAG_NET, "  -> Light Lux   : %lu lux",   rx_data.light_lux);

            // --- Critical Section: เขียน g_latest_data อย่างปลอดภัย ---
            if (xSemaphoreTake(g_data_mutex, pdMS_TO_TICKS(100)) == pdTRUE) {
                g_latest_data = rx_data;
                xSemaphoreGive(g_data_mutex);
                ESP_LOGI(TAG_NET, "[NETWORK TASK]: g_latest_data updated (Mutex OK)");
            } else {
                ESP_LOGW(TAG_NET, "[NETWORK TASK]: Mutex timeout! Data NOT updated.");
            }
            ESP_LOGI(TAG_NET, "=======================================================");
        }

        // Forensic Stack Monitor
        UBaseType_t hwm = uxTaskGetStackHighWaterMark(NULL);
        ESP_LOGI(TAG_STACK, "  -> NetworkTask Stack Remaining: %u words (%u bytes)",
                 hwm, hwm * sizeof(StackType_t));
    }
}

// =============================================================
//  SoftAP Initialization
// =============================================================
static void wifi_init_softap(void)
{
    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_netif_init()");
    ESP_ERROR_CHECK(esp_netif_init());

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_event_loop_create_default()");
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_netif_create_default_wifi_ap()");
    esp_netif_t *ap_netif = esp_netif_create_default_wifi_ap();
    ESP_LOGI(TAG_AP, "[FORENSIC]: SoftAP netif created at %p (IP: 192.168.4.1)", ap_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_wifi_init()");
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)");
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL, NULL));

    wifi_config_t wifi_config = {
        .ap = {
            .ssid           = AP_SSID,
            .ssid_len       = strlen(AP_SSID),
            .password       = AP_PASS,
            .max_connection = AP_MAX_CONN,
            .authmode       = WIFI_AUTH_WPA2_PSK,
            .channel        = 1,
        },
    };
    if (strlen(AP_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_AP)");
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_wifi_set_config(WIFI_IF_AP)");
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_config));

    ESP_LOGI(TAG_AP, "[FORENSIC]: Call esp_wifi_start()");
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG_AP, "=======================================================");
    ESP_LOGI(TAG_AP, "  SoftAP Running! SSID: \"%s\", Channel: %d",
             AP_SSID, wifi_config.ap.channel);
    ESP_LOGI(TAG_AP, "  -> Connect your phone to: %s", AP_SSID);
    ESP_LOGI(TAG_AP, "  -> Then open browser:      http://192.168.4.1");
    ESP_LOGI(TAG_AP, "=======================================================");
}

// =============================================================
//  app_main
// =============================================================
void app_main(void)
{
    // --- 1. NVS Flash Init ---
    ESP_LOGI("MAIN", "[FORENSIC]: Call nvs_flash_init()");
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // --- 2. Print Banner ---
    ESP_LOGI("MAIN", "=======================================================");
    ESP_LOGI("MAIN", "  Lab 6-4: IoT Sensor Dashboard");
    ESP_LOGI("MAIN", "  SoftAP + FreeRTOS Queue + HTTP Server");
    ESP_LOGI("MAIN", "=======================================================");

    // --- 3. Mutex for Shared Data ---
    ESP_LOGI("MAIN", "[FORENSIC]: Call xSemaphoreCreateMutex()");
    g_data_mutex = xSemaphoreCreateMutex();
    ESP_ERROR_CHECK(g_data_mutex == NULL ? ESP_ERR_NO_MEM : ESP_OK);
    ESP_LOGI("MAIN", "[FORENSIC]: Mutex created at %p", g_data_mutex);

    // --- 4. FreeRTOS Queue (10 items) ---
    ESP_LOGI("MAIN", "[FORENSIC]: Call xQueueCreate(10, sizeof(sensor_data_t))");
    xSensorQueue = xQueueCreate(10, sizeof(sensor_data_t));
    ESP_ERROR_CHECK(xSensorQueue == NULL ? ESP_ERR_NO_MEM : ESP_OK);
    ESP_LOGI("MAIN", "[FORENSIC]: Queue created at %p", xSensorQueue);

    // --- 5. SoftAP ---
    wifi_init_softap();

    // --- 6. HTTP Server ---
    start_http_server();

    // --- 7. FreeRTOS Tasks ---
    ESP_LOGI("MAIN", "[FORENSIC]: Call xTaskCreate(vSensorTask)  Stack=3072");
    xTaskCreate(vSensorTask,  "SensorTask",  3072, NULL, 5, NULL);

    ESP_LOGI("MAIN", "[FORENSIC]: Call xTaskCreate(vNetworkTask) Stack=4096");
    xTaskCreate(vNetworkTask, "NetworkTask", 4096, NULL, 4, NULL);

    ESP_LOGI("MAIN", "=======================================================");
    ESP_LOGI("MAIN", "  System Ready! Open browser at http://192.168.4.1");
    ESP_LOGI("MAIN", "=======================================================");
}