# ใบงานที่ 6.4: IoT Sensor Dashboard — แสดงผลค่าเซนเซอร์แบบ Real-Time ผ่าน Web Browser บนมือถือ
## 7. ตารางบันทึกผลการทดลอง (Experiment Results)

### 7.1 บันทึกข้อมูลจาก Dashboard

| ครั้งที่ | Temperature (°C) | Humidity (%) | Light Lux | Timestamp (ms) |
| :------: | :--------------: | :----------: | :-------: | :------------: |
|  **1**   |   29.10          |      61.80   |    516    |    400         |
|  **2**   |   33.40          |      67.70   |    369    |    1910        |
|  **3**   |   33.80          |      54.30   |    627    |    3420        |

### 7.2 ทดสอบ JSON API (`/api/data`)

บันทึก Raw JSON Response จาก Browser:
```
{"temperature":28.00,"humidity":55.00,"light_lux":637,"timestamp_ms":205770}

```
## รูปภาพ

<img width="283" height="610" alt="image" src="https://github.com/user-attachments/assets/8a573581-336d-4c20-81d8-1d14c32de294" />
<img width="275" height="606" alt="image" src="https://github.com/user-attachments/assets/f30cbf91-ddc3-4877-b433-7e4b7308e269" />

---
output log
```
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 16:54:11
I (28) boot: Multicore bootloader
I (29) boot: chip revision: v3.1
I (32) boot.esp32: SPI Speed      : 40MHz
I (35) boot.esp32: SPI Mode       : DIO
I (39) boot.esp32: SPI Flash Size : 2MB
I (42) boot: Enabling RNG early entropy source...
I (47) boot: Partition Table:
I (49) boot: ## Label            Usage          Type ST Offset   Length
I (56) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (62) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (69) boot:  2 factory          factory app      00 00 00010000 00100000
I (75) boot: End of partition table
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1d5a8h (120232) map
I (129) esp_image: segment 1: paddr=0002d5d0 vaddr=3ffb0000 size=02a48h ( 10824) load
I (134) esp_image: segment 2: paddr=00030020 vaddr=400d0020 size=8ef48h (585544) map
I (342) esp_image: segment 3: paddr=000bef70 vaddr=3ffb2a48 size=01ae0h (  6880) load
I (345) esp_image: segment 4: paddr=000c0a58 vaddr=40080000 size=1562ch ( 87596) load
I (382) esp_image: segment 5: paddr=000d608c vaddr=50000000 size=00028h (    40) load
I (393) boot: Loaded app from partition at offset 0x10000
I (393) boot: Disabling RNG early entropy source...
I (404) cpu_start: Multicore app
I (412) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (412) cpu_start: Pro cpu start user code
I (412) cpu_start: cpu freq: 160000000 Hz
I (414) app_init: Application information:
I (418) app_init: Project name:     iot_sensor_dashboard
I (423) app_init: App version:      1
I (426) app_init: Compile time:     Aug 10 2026 16:53:49
I (432) app_init: ELF file SHA256:  82496d32c...
I (436) app_init: ESP-IDF:          v6.0.2
I (440) efuse_init: Min chip rev:     v0.0
I (443) efuse_init: Max chip rev:     v3.99 
I (447) efuse_init: Chip rev:         v3.1
I (452) heap_init: Initializing. RAM available for dynamic allocation:
I (458) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (463) heap_init: At 3FFB8A38 len 000275C8 (157 KiB): DRAM
I (468) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (473) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (479) heap_init: At 4009562C len 0000A9D4 (42 KiB): IRAM
I (486) spi_flash: detected chip: generic
I (488) spi_flash: flash io: dio
W (491) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (505) main_task: Started on CPU0
I (505) main_task: Calling app_main()
I (505) MAIN: [FORENSIC]: Call nvs_flash_init()
I (555) MAIN: =======================================================
I (555) MAIN:   Lab 6-4: IoT Sensor Dashboard
I (555) MAIN:   SoftAP + FreeRTOS Queue + HTTP Server
I (555) MAIN: =======================================================
I (565) MAIN: [FORENSIC]: Call xSemaphoreCreateMutex()
I (565) MAIN: [FORENSIC]: Mutex created at 0x3ffbbe78
I (575) MAIN: [FORENSIC]: Call xQueueCreate(10, sizeof(sensor_data_t))
I (585) MAIN: [FORENSIC]: Queue created at 0x3ffbbed0
I (585) SOFTAP: [FORENSIC]: Call esp_netif_init()
I (595) SOFTAP: [FORENSIC]: Call esp_event_loop_create_default()
I (595) SOFTAP: [FORENSIC]: Call esp_netif_create_default_wifi_ap()
I (605) SOFTAP: [FORENSIC]: SoftAP netif created at 0x3ffbde60 (IP: 192.168.4.1)
I (605) SOFTAP: [FORENSIC]: Call esp_wifi_init()
I (625) wifi:wifi driver task: 3ffc05e4, prio:23, stack:6656, core=0
I (645) wifi:wifi firmware version: 00ad238
I (645) wifi:wifi certification version: v7.0
I (645) wifi:config NVS flash: enabled
I (645) wifi:config nano formatting: disabled
I (645) wifi:Init data frame dynamic rx buffer num: 32
I (655) wifi:Init static rx mgmt buffer num: 5
I (655) wifi:Init management short buffer num: 32
I (665) wifi:Init dynamic tx buffer num: 32
I (665) wifi:Init static rx buffer size: 1600
I (665) wifi:Init static rx buffer num: 10
I (675) wifi:Init dynamic rx buffer num: 32
I (675) wifi_init: rx ba win: 6
I (675) wifi_init: accept mbox: 6
I (685) wifi_init: tcpip mbox: 32
I (685) wifi_init: udp mbox: 6
I (685) wifi_init: tcp mbox: 6
I (695) wifi_init: tcp tx win: 5760
I (695) wifi_init: tcp rx win: 5760
I (695) wifi_init: tcp mss: 1440
I (705) wifi_init: WiFi IRAM OP enabled
I (705) wifi_init: WiFi RX IRAM OP enabled
I (705) SOFTAP: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (715) SOFTAP: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_AP)
I (725) SOFTAP: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_AP)
I (735) SOFTAP: [FORENSIC]: Call esp_wifi_start()
I (735) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (805) wifi:mode : softAP (84:1f:e8:39:90:29)
I (815) wifi:Total power save buffer number: 16
I (815) wifi:Init max length of beacon: 752/752
I (815) wifi:Init max length of beacon: 752/752
I (825) SOFTAP: =======================================================
I (825) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (835) SOFTAP:   SoftAP Running! SSID: "MY_ESP32_SENSOR_AP", Channel: 1
I (835) SOFTAP:   -> Connect your phone to: MY_ESP32_SENSOR_AP
I (845) SOFTAP:   -> Then open browser:      http://192.168.4.1
I (855) SOFTAP: =======================================================
I (855) HTTP_SERVER: [FORENSIC]: Call httpd_start()
I (865) HTTP_SERVER: =======================================================
I (865) HTTP_SERVER: [HTTP SERVER]: Started successfully
I (875) HTTP_SERVER:   -> Dashboard : http://192.168.4.1/
I (875) HTTP_SERVER:   -> JSON API  : http://192.168.4.1/api/data
I (885) HTTP_SERVER: =======================================================
I (895) MAIN: [FORENSIC]: Call xTaskCreate(vSensorTask)  Stack=3072
I (895) SENSOR_TASK: [FORENSIC]: Sensor Collector Task started on Core 0
I (905) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 29.1 C, Hum: 61.8 %, Lux: 516
I (915) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (915) MAIN: [FORENSIC]: Call xTaskCreate(vNetworkTask) Stack=4096
I (925) NETWORK_TASK: [FORENSIC]: Network Task started on Core 0
I (925) NETWORK_TASK: =======================================================
I (935) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (945) NETWORK_TASK:   -> Timestamp   : 400 ms
I (945) NETWORK_TASK:   -> Temperature : 29.10 degC
I (955) NETWORK_TASK:   -> Humidity    : 61.80 %
I (955) NETWORK_TASK:   -> Light Lux   : 516 lux
I (955) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (965) NETWORK_TASK: =======================================================
I (975) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (985) MAIN: =======================================================
I (985) MAIN:   System Ready! Open browser at http://192.168.4.1
I (995) MAIN: =======================================================
I (995) main_task: Returned from app_main()
I (2415) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 33.4 C, Hum: 67.7 %, Lux: 369
I (2415) NETWORK_TASK: =======================================================
I (2415) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (2415) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (2425) NETWORK_TASK:   -> Timestamp   : 1910 ms
I (2435) NETWORK_TASK:   -> Temperature : 33.40 degC
I (2435) NETWORK_TASK:   -> Humidity    : 67.70 %
I (2445) NETWORK_TASK:   -> Light Lux   : 369 lux
I (2445) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (2455) NETWORK_TASK: =======================================================
I (2455) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (3925) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 33.8 C, Hum: 54.3 %, Lux: 627
I (3925) NETWORK_TASK: =======================================================
I (3925) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (3925) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (3935) NETWORK_TASK:   -> Timestamp   : 3420 ms
I (3945) NETWORK_TASK:   -> Temperature : 33.80 degC
I (3945) NETWORK_TASK:   -> Humidity    : 54.30 %
I (3955) NETWORK_TASK:   -> Light Lux   : 627 lux
I (3955) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (3965) NETWORK_TASK: =======================================================
I (3965) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (5435) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 29.0 C, Hum: 64.7 %, Lux: 295
I (5435) NETWORK_TASK: =======================================================
I (5435) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (5435) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (5445) NETWORK_TASK:   -> Timestamp   : 4930 ms
I (5455) NETWORK_TASK:   -> Temperature : 29.00 degC
I (5455) NETWORK_TASK:   -> Humidity    : 64.70 %
I (5465) NETWORK_TASK:   -> Light Lux   : 295 lux
I (5465) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (5475) NETWORK_TASK: =======================================================
I (5475) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (6945) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 27.8 C, Hum: 65.7 %, Lux: 275
I (6945) NETWORK_TASK: =======================================================
I (6945) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (6945) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (6955) NETWORK_TASK:   -> Timestamp   : 6440 ms
I (6965) NETWORK_TASK:   -> Temperature : 27.80 degC
I (6965) NETWORK_TASK:   -> Humidity    : 65.70 %
I (6975) NETWORK_TASK:   -> Light Lux   : 275 lux
I (6975) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (6985) NETWORK_TASK: =======================================================
I (6985) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (8455) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 32.8 C, Hum: 68.6 %, Lux: 610
I (8455) NETWORK_TASK: =======================================================
I (8455) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (8455) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (8465) NETWORK_TASK:   -> Timestamp   : 7950 ms
I (8475) NETWORK_TASK:   -> Temperature : 32.80 degC
I (8475) NETWORK_TASK:   -> Humidity    : 68.60 %
I (8485) NETWORK_TASK:   -> Light Lux   : 610 lux
I (8485) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (8495) NETWORK_TASK: =======================================================
I (8495) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
I (9965) SENSOR_TASK: [SENSOR TASK]: Pushing -> Temp: 25.0 C, Hum: 68.8 %, Lux: 382
I (9965) NETWORK_TASK: =======================================================
I (9965) FORENSIC_STACK:   -> SensorTask Stack Remaining: 2028 words (2028 bytes)
I (9965) NETWORK_TASK: [NETWORK TASK]: Data Received from Queue!
I (9975) NETWORK_TASK:   -> Timestamp   : 9460 ms
I (9985) NETWORK_TASK:   -> Temperature : 25.00 degC
I (9985) NETWORK_TASK:   -> Humidity    : 68.80 %
I (9995) NETWORK_TASK:   -> Light Lux   : 382 lux
I (9995) NETWORK_TASK: [NETWORK TASK]: g_latest_data updated (Mutex OK)
I (10005) NETWORK_TASK: =======================================================
I (10005) FORENSIC_STACK:   -> NetworkTask Stack Remaining: 3080 words (3080 bytes)
```
---
## 8. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เหตุใดจึงต้องใช้ **Mutex** ในการป้องกันการเข้าถึงตัวแปร `g_latest_data` ร่วมกันระหว่าง `vNetworkTask` และ HTTP Handler? ถ้าไม่ใช้จะเกิดอะไรขึ้น?
> เอาไว้ล็อกคิวไม่ให้ต่าง Task เข้ามาแย่งกันอ่านเขียนตัวแปรพร้อมกัน ถ้าไม่ล็อก ข้อมูลมีสิทธิ์พังหรือตีกัน (Race condition) เช่น จังหวะที่ Task นึงกำลังอัปเดตค่าเพิ่งเสร็จไปครึ่งเดียว อีก Task ดันฉกเอาไปอ่านซะแล้ว ข้อมูลที่โชว์ก็จะไม่สมบูรณ์หรือเพี้ยนไปเลย
2. `esp_http_server` รัน Handler บน Thread ใด — เป็น Thread เดียวกับ FreeRTOS Task ของเราหรือไม่?
> รันบน Thread ของตัว HTTP Server ที่ระบบมันสร้างขึ้นมาจัดการเองเลย แยกวงกันชัดเจน ไม่ใช่ Thread หรือ Task เดียวกับที่เราเขียนขึ้นมา
3. การที่ Dashboard ใช้ `<meta http-equiv="refresh" content="2">` แทนที่จะใช้ JavaScript `fetch()` มีข้อดีและข้อเสียอย่างไร?
> ข้อดีของ meta refresh: เขียนง่ายสุดๆ โค้ด HTML บรรทัดเดียวจบ ไม่ต้องวุ่นวายเขียน JavaScript เลย
  ข้อเสีย: หน้าเว็บจะกระพริบโหลดใหม่ทั้งหน้าทุก 2 วินาที ทำให้ดูไม่ลื่นไหลและเปลืองแบนด์วิดท์ สู้ใช้ fetch() ที่แอบไปดึงข้อมูลมาเปลี่ยนเฉพาะตัวเลขไม่ได้ แบบนั้นหน้าจอจะไม่กระพริบเลย
