# ใบงานที่ 6.1: การคอนฟิก ESP32 SoftAP และการสกัด Forensic Log ข้อมูล Client (Wi-Fi Access Point Mode)
## 6. ตารางบันทึกผลการทดลอง (Experiment Results)

### 6.1 บันทึกข้อมูล Client ที่เชื่อมต่อเข้ากับ ESP32 SoftAP

| อุปกรณ์ที่ใช้ทดสอบ (เช่น iPhone/Android) | MAC Address ที่ดักจับได้ | Association ID (AID) | หมายเลข IP Address ที่ได้ (ถ้าทราบ) |
| :--- | :--- | :---: | :---: |
| **อุปกรณ์ที่ 1** |50:FE:0C:00:AB:D9 | 1| 192.168.4.2|
| **อุปกรณ์ที่ 2** |EC:2E:98:0B:8F:B9 | 2| 192.168.4.3|

---

## 7. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เหตุใด IP Address เริ่มต้นของ ESP32 SoftAP จึงเป็น `192.168.4.1` และ DHCP Server บน ESP32 เริ่มแจกจ่าย IP ที่หมายเลขใด?
> เพราะมันเป็นค่า Default ที่ระบบตั้งมาเผื่อไว้หนีไม่ให้ IP ไปชนกับเร้าเตอร์บ้าน (ที่มักใช้ 192.168.1.1) ส่วนตัว DHCP จะเริ่มแจก IP ให้เครื่องแรกที่เบอร์ 192.168.4.2 เป็นต้นไป
2. สมาชิกตัวแปร `mac` ในโครงสร้าง `wifi_event_ap_staconnected_t` สามารถนำไปประยุกต์ใช้ทำระบบความปลอดภัยขั้นสูง (เช่น MAC Filtering) ได้อย่างไร?
> พอมีอุปกรณ์มาเกาะปุ๊บ ระบบจะส่ง MAC Address มาให้ เราก็เอามาเช็คเทียบกับรายชื่อ (Whitelist/Blacklist) ที่เราตั้งไว้ได้เลย ถ้าเช็คแล้วเป็นเครื่องแปลกปลอม ก็สั่ง "เตะออก" (Deauth) ไม่ให้เชื่อมต่อได้ทันที
3. หากมี Client พยายามเชื่อมต่อเป็นเครื่องที่ 5 (เกินค่า `max_connection = 4`) จะเกิดเหตุการณ์ใดขึ้นในระดับสัญญาณวิทยุ?
> ตัว ESP32 จะปัดตกคำขอตั้งแต่ในอากาศเลย (ส่งคลื่นตอบกลับไปว่าคิวเต็มแล้ว) ทำให้เครื่องที่ 5 เกาะ Wi-Fi ไม่ติดตั้งแต่แรก และไม่ได้ IP 

output log อุปกรณ์ที่ 1

```
rt.c:27
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 09:15:23
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
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1a240h (107072) map
I (124) esp_image: segment 1: paddr=0002a268 vaddr=3ffb0000 size=04528h ( 17704) load
I (131) esp_image: segment 2: paddr=0002e798 vaddr=40080000 size=01880h (  6272) load
I (134) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=87e08h (556552) map
I (334) esp_image: segment 4: paddr=000b7e30 vaddr=40081880 size=13d88h ( 81288) load
I (368) esp_image: segment 5: paddr=000cbbc0 vaddr=50000000 size=00028h (    40) load
I (379) boot: Loaded app from partition at offset 0x10000
I (379) boot: Disabling RNG early entropy source...
I (389) cpu_start: Multicore app
I (397) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (398) cpu_start: Pro cpu start user code
I (398) cpu_start: cpu freq: 160000000 Hz
I (400) app_init: Application information:
I (403) app_init: Project name:     wifi_softap_tracking
I (408) app_init: App version:      1
I (412) app_init: Compile time:     Aug 10 2026 09:15:05
I (417) app_init: ELF file SHA256:  f11f88cea...
I (421) app_init: ESP-IDF:          v6.0.2
I (425) efuse_init: Min chip rev:     v0.0
I (429) efuse_init: Max chip rev:     v3.99 
I (433) efuse_init: Chip rev:         v3.1
I (437) heap_init: Initializing. RAM available for dynamic allocation:
I (443) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (448) heap_init: At 3FFB8A20 len 000275E0 (157 KiB): DRAM
I (453) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (459) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (464) heap_init: At 40095608 len 0000A9F8 (42 KiB): IRAM
I (471) spi_flash: detected chip: generic
I (473) spi_flash: flash io: dio
W (476) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (490) main_task: Started on CPU0
I (490) main_task: Calling app_main()
I (490) LAB_SOFTAP: [FORENSIC]: Call nvs_flash_init()
I (510) LAB_SOFTAP: [FORENSIC]: Call esp_netif_init()
I (520) LAB_SOFTAP: [FORENSIC]: Call esp_event_loop_create_default()
I (520) LAB_SOFTAP: [FORENSIC]: Call esp_netif_create_default_wifi_ap()
I (520) LAB_SOFTAP: [FORENSIC]: SoftAP Interface created at 0x3ffbdc70 (Default IP: 192.168.4.1)
I (530) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_init(&cfg)
I (540) wifi:wifi driver task: 3ffc03f4, prio:23, stack:6656, core=0
I (550) wifi:wifi firmware version: 00ad238
I (550) wifi:wifi certification version: v7.0
I (550) wifi:config NVS flash: enabled
I (550) wifi:config nano formatting: disabled
I (560) wifi:Init data frame dynamic rx buffer num: 32
I (560) wifi:Init static rx mgmt buffer num: 5
I (570) wifi:Init management short buffer num: 32
I (570) wifi:Init dynamic tx buffer num: 32
I (580) wifi:Init static rx buffer size: 1600
I (580) wifi:Init static rx buffer num: 10
I (580) wifi:Init dynamic rx buffer num: 32
I (590) wifi_init: rx ba win: 6
I (590) wifi_init: accept mbox: 6
I (590) wifi_init: tcpip mbox: 32
I (600) wifi_init: udp mbox: 6
I (600) wifi_init: tcp mbox: 6
I (600) wifi_init: tcp tx win: 5760
I (600) wifi_init: tcp rx win: 5760
I (610) wifi_init: tcp mss: 1440
I (610) wifi_init: WiFi IRAM OP enabled
I (610) wifi_init: WiFi RX IRAM OP enabled
I (620) LAB_SOFTAP: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (630) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_AP)
I (630) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_AP, &wifi_config)
I (650) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_start()
I (650) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (720) wifi:mode : softAP (84:1f:e8:39:90:29)
I (730) wifi:Total power save buffer number: 16
I (730) wifi:Init max length of beacon: 752/752
I (730) wifi:Init max length of beacon: 752/752
I (730) LAB_SOFTAP: ==================================================================
I (730) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (750) LAB_SOFTAP:   ESP32 SoftAP Running! SSID: "MY_ESP32_260", Channel: 1
I (750) LAB_SOFTAP: ==================================================================
I (760) LAB_SOFTAP: [TCP SERVER]: Listening on 192.168.4.1:8080
I (770) main_task: Returned from app_main()
I (15420) wifi:station: 50:fe:0c:00:ab:d9 join, AID=1, bgn, 40U
I (15510) LAB_SOFTAP: =======================================================
I (15510) LAB_SOFTAP: [FORENSIC EVENT]: Client Connected to ESP32 SoftAP!
I (15510) LAB_SOFTAP:   -> Client MAC Address : 50:FE:0C:00:AB:D9
I (15520) LAB_SOFTAP:   -> Assigned AID       : 1
I (15520) LAB_SOFTAP: =======================================================
I (16000) wifi:<ba-add>idx:2 (ifx:1, 50:fe:0c:00:ab:d9), tid:0, ssn:16, winSize:64
I (16040) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.2
```
---

output log อุปกรณ์ที่ 2  ของ  นายธนบดี บุญภมร 67030298

```
I (208410) wifi:station: ec:2e:98:0b:8f:b9 join, AID=2, bgn, 40U
I (208440) LAB_SOFTAP: =======================================================
I (208440) LAB_SOFTAP: [FORENSIC EVENT]: Client Connected to ESP32 SoftAP!
I (208440) LAB_SOFTAP:   -> Client MAC Address : EC:2E:98:0B:8F:B9
I (208450) LAB_SOFTAP:   -> Assigned AID       : 2
I (208450) LAB_SOFTAP: =======================================================
I (208590) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.3
I (211600) wifi:<ba-add>idx:3 (ifx:1, ec:2e:98:0b:8f:b9), tid:0, ssn:90, winSize:64
```
