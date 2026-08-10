## 6. ตารางบันทึกผลการทดลอง (Experiment Results)

### 6.1 บันทึกข้อมูล Client ที่เชื่อมต่อเข้ากับ ESP32 SoftAP

| อุปกรณ์ที่ใช้ทดสอบ (เช่น iPhone/Android) | MAC Address ที่ดักจับได้ | Association ID (AID) | หมายเลข IP Address ที่ได้ (ถ้าทราบ) |
| :--- | :--- | :---: | :---: |
| **อุปกรณ์ที่ 1** | 1A:CA:3D:B0:AA:01 | 1 | 192.168.4.2 |
| **อุปกรณ์ที่ 2** | C2:F5:E7:CC:77:D6 | 2 | 192.168.4.3 |

---

### output log
```
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 09:20:25
I (27) boot: Multicore bootloader
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
I (408) app_init: App version:      9d99085-dirty
I (413) app_init: Compile time:     Aug 10 2026 09:18:32
I (418) app_init: ELF file SHA256:  5f5cf84cf...
I (422) app_init: ESP-IDF:          v6.0.2
I (426) efuse_init: Min chip rev:     v0.0
I (430) efuse_init: Max chip rev:     v3.99 
I (434) efuse_init: Chip rev:         v3.1
I (438) heap_init: Initializing. RAM available for dynamic allocation:
I (444) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (449) heap_init: At 3FFB8A20 len 000275E0 (157 KiB): DRAM
I (454) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (460) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (465) heap_init: At 40095608 len 0000A9F8 (42 KiB): IRAM
W (472) spi_flash: Detected boya flash chip but using generic driver. For optimal functionality, enable `SPI_FLASH_SUPPORT_BOYA_CHIP` in menuconfig
I (484) spi_flash: detected chip: generic
I (487) spi_flash: flash io: dio
W (490) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (504) main_task: Started on CPU0
I (504) main_task: Calling app_main()
I (504) LAB_SOFTAP: [FORENSIC]: Call nvs_flash_init()
I (534) LAB_SOFTAP: [FORENSIC]: Call esp_netif_init()
I (534) LAB_SOFTAP: [FORENSIC]: Call esp_event_loop_create_default()
I (534) LAB_SOFTAP: [FORENSIC]: Call esp_netif_create_default_wifi_ap()
I (544) LAB_SOFTAP: [FORENSIC]: SoftAP Interface created at 0x3ffbdd78 (Default IP: 192.168.4.1)
I (544) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_init(&cfg)
I (564) wifi:wifi driver task: 3ffc04fc, prio:23, stack:6656, core=0
I (574) wifi:wifi firmware version: 00ad238
I (574) wifi:wifi certification version: v7.0
I (574) wifi:config NVS flash: enabled
I (574) wifi:config nano formatting: disabled
I (584) wifi:Init data frame dynamic rx buffer num: 32
I (584) wifi:Init static rx mgmt buffer num: 5
I (584) wifi:Init management short buffer num: 32
I (594) wifi:Init dynamic tx buffer num: 32
I (594) wifi:Init static rx buffer size: 1600
I (604) wifi:Init static rx buffer num: 10
I (604) wifi:Init dynamic rx buffer num: 32
I (614) wifi_init: rx ba win: 6
I (614) wifi_init: accept mbox: 6
I (614) wifi_init: tcpip mbox: 32
I (614) wifi_init: udp mbox: 6
I (624) wifi_init: tcp mbox: 6
I (624) wifi_init: tcp tx win: 5760
I (624) wifi_init: tcp rx win: 5760
I (624) wifi_init: tcp mss: 1440
I (634) wifi_init: WiFi IRAM OP enabled
I (634) wifi_init: WiFi RX IRAM OP enabled
I (644) LAB_SOFTAP: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (644) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_AP)
I (664) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_AP, &wifi_config)
I (934) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_start()
I (934) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (1024) phy_init: Saving new calibration data due to checksum failure or outdated calibration data, mode(0)
I (1094) wifi:mode : softAP (88:57:21:ae:1d:89)
I (1094) wifi:Total power save buffer number: 16
I (1094) wifi:Init max length of beacon: 752/752
I (1104) wifi:Init max length of beacon: 752/752
I (1104) LAB_SOFTAP: ==================================================================
I (1104) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (1114) LAB_SOFTAP:   ESP32 SoftAP Running! SSID: "ESP32_AP_0323", Channel: 1
I (1124) LAB_SOFTAP: ==================================================================
I (1134) LAB_SOFTAP: [TCP SERVER]: Listening on 192.168.4.1:8080
I (1134) main_task: Returned from app_main()
I (75434) wifi:new:<1,0>, old:<1,1>, ap:<1,1>, sta:<255,255>, prof:1, snd_ch_cfg:0x0
I (75434) wifi:station: 1a:ca:3d:b0:aa:01 join, AID=1, bgn, 20
I (76704) LAB_SOFTAP: =======================================================
I (76704) LAB_SOFTAP: [FORENSIC EVENT]: Client Connected to ESP32 SoftAP!
I (76704) LAB_SOFTAP:   -> Client MAC Address : 1A:CA:3D:B0:AA:01
I (76704) LAB_SOFTAP:   -> Assigned AID       : 1
I (76714) LAB_SOFTAP: =======================================================
I (77154) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.2
I (77424) wifi:<ba-add>idx:2 (ifx:1, 1a:ca:3d:b0:aa:01), tid:0, ssn:16, winSize:64
I (143644) wifi:station: c2:f5:e7:cc:77:d6 join, AID=2, bgn, 20
I (143744) LAB_SOFTAP: =======================================================
I (143744) LAB_SOFTAP: [FORENSIC EVENT]: Client Connected to ESP32 SoftAP!
I (143744) LAB_SOFTAP:   -> Client MAC Address : C2:F5:E7:CC:77:D6
I (143754) LAB_SOFTAP:   -> Assigned AID       : 2
I (143754) LAB_SOFTAP: =======================================================
I (144014) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.3
I (144104) wifi:<ba-add>idx:3 (ifx:1, c2:f5:e7:cc:77:d6), tid:0, ssn:17, winSize:64
```

---

## 7. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เหตุใด IP Address เริ่มต้นของ ESP32 SoftAP จึงเป็น `192.168.4.1` และ DHCP Server บน ESP32 เริ่มแจกจ่าย IP ที่หมายเลขใด?
```
สาเหตุที่ IP Address เริ่มต้นเป็น 192.168.4.1 เนื่องจากเป็นค่า Configuration มาตรฐานที่ทาง ESP-IDF กำหนดไว้ให้สำหรับอินเทอร์เฟซของ Access Point เพื่อหลีกเลี่ยงการชน กับเร้าเตอร์ตามบ้านทั่วไปที่มักจะใช้ 192.168.1.1 หรือ 192.168.0.1 และ DHCP Server บน ESP32 จะเริ่มแจกจ่าย IP ให้กับ Client ลำดับถัดไป โดยเริ่มที่หมายเลข 192.168.4.2 เป็นต้นไป 
```

2. สมาชิกตัวแปร `mac` ในโครงสร้าง `wifi_event_ap_staconnected_t` สามารถนำไปประยุกต์ใช้ทำระบบความปลอดภัยขั้นสูง (เช่น MAC Filtering) ได้อย่างไร?
```
เราสามารถนำตัวแปร mac ที่ดักจับได้มาสร้างระบบ Whitelist หรือ Blacklist ได้ เมื่อมีอุปกรณ์พยายามเชื่อมต่อและเกิดเหตุการณ์ WIFI_EVENT_AP_STACONNECTED โปรแกรมจะนำค่า mac ของเครื่องนั้นไปเปรียบเทียบกับฐานข้อมูล MAC Address ที่เราอนุญาต หากตรวจสอบแล้วพบว่า MAC Address นั้นไม่อยู่ในรายชื่อที่อนุญาต โปรแกรมสามารถเรียกใช้ฟังก์ชัน esp_wifi_deauth_sta เพื่อสั่งยกเลิกการเชื่อมต่อ อุปกรณ์นั้นได้ทันที ทำให้ได้ระบบรักษาความปลอดภัยแบบ MAC Filtering ที่ทำงานด้วยตัวเองโดยไม่ต้องพึ่งพาระบบภายนอก
```

3. หากมี Client พยายามเชื่อมต่อเป็นเครื่องที่ 5 (เกินค่า `max_connection = 4`) จะเกิดเหตุการณ์ใดขึ้นในระดับสัญญาณวิทยุ?
```
ในระดับสัญญาณวิทยุ เมื่อ ESP32 รับรอง Client จนครบ 4 เครื่องตามที่กำหนดใน max_connection แล้ว หากมีเครื่องที่ 5 พยายามส่งเฟรมขอเชื่อมต่อ เข้ามา ตัว ESP32 จะปฏิเสธคำขอนั้น ระบบจะทำการตอบกลับด้วยเฟรมปฏิเสธการเชื่อมต่อ เช่น Association Response หรือส่งเฟรม Deauthentication / Disassociation กลับไปยังเครื่องที่ 5 พร้อมระบุ Reason Code แจ้งว่า AP ไม่สามารถรับอุปกรณ์เพิ่มได้อีก ทำให้อุปกรณ์เครื่องที่ 5 ไม่สามารถเข้ามาเกาะเครือข่ายและไม่ได้รับ IP Address
```