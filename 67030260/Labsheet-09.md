# ใบงานที่ 6.5: 📋 Assignment Project — ระบบเช็กชื่อและยืนยันตัวตนอัจฉริยะด้วย RF Proximity & Sensor Fusion

> [!IMPORTANT]
> **งานมอบหมาย (Assignment Project)**
> ใบงานนี้เป็น **มินิโปรเจกต์ส่งงาน** ที่ต่อยอดจากใบงาน 6.1–6.4 นักศึกษาต้องบูรณาการความรู้ทั้งหมดของสัปดาห์ที่ 6 และส่งรายงานพร้อมสาธิตการทำงานของระบบ

## 5. ตารางบันทึกผลการทดลอง (Experiment Results)

### 5.1 ตารางบันทึกการเช็กชื่อผ่าน RF Proximity

| ลำดับที่ | ชื่อสมาร์ตโฟน / MAC Address | ระดับ RSSI (dBm) | ระยะทางประเมิน (Near/Far) | ผลการลงชื่อ (Passed/Rejected) |
| :---: | :--- | :---: | :---: | :---: |
| **1** |50:FE:0C:00:AB:D9 |-45 |Near |Passed (Valid) |
| **2** |96:2E:48:7A:99:39 |-45 |Near |Passed (Valid) |

---
output log

```
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 17:32:44
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
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1c0e0h (114912) map
I (127) esp_image: segment 1: paddr=0002c108 vaddr=3ffb0000 size=03f10h ( 16144) load
I (134) esp_image: segment 2: paddr=00030020 vaddr=400d0020 size=8e31ch (582428) map
I (341) esp_image: segment 3: paddr=000be344 vaddr=3ffb3f10 size=00618h (  1560) load
I (342) esp_image: segment 4: paddr=000be964 vaddr=40080000 size=1562ch ( 87596) load
I (381) esp_image: segment 5: paddr=000d3f98 vaddr=50000000 size=00028h (    40) load
I (392) boot: Loaded app from partition at offset 0x10000
I (392) boot: Disabling RNG early entropy source...
I (403) cpu_start: Multicore app
I (411) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (411) cpu_start: Pro cpu start user code
I (411) cpu_start: cpu freq: 160000000 Hz
I (413) app_init: Application information:
I (417) app_init: Project name:     proximity_attendance
I (422) app_init: App version:      1
I (426) app_init: Compile time:     Aug 10 2026 17:32:22
I (431) app_init: ELF file SHA256:  8adf17b2e...
I (435) app_init: ESP-IDF:          v6.0.2
I (439) efuse_init: Min chip rev:     v0.0
I (443) efuse_init: Max chip rev:     v3.99 
I (447) efuse_init: Chip rev:         v3.1
I (451) heap_init: Initializing. RAM available for dynamic allocation:
I (457) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (462) heap_init: At 3FFB8AA0 len 00027560 (157 KiB): DRAM
I (467) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (472) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (478) heap_init: At 4009562C len 0000A9D4 (42 KiB): IRAM
I (485) spi_flash: detected chip: generic
I (487) spi_flash: flash io: dio
W (490) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (504) main_task: Started on CPU0
I (504) main_task: Calling app_main()
I (554) wifi:wifi driver task: 3ffc057c, prio:23, stack:6656, core=0
I (574) wifi:wifi firmware version: 00ad238
I (574) wifi:wifi certification version: v7.0
I (574) wifi:config NVS flash: enabled
I (574) wifi:config nano formatting: disabled
I (574) wifi:Init data frame dynamic rx buffer num: 32
I (584) wifi:Init static rx mgmt buffer num: 5
I (584) wifi:Init management short buffer num: 32
I (584) wifi:Init dynamic tx buffer num: 32
I (594) wifi:Init static rx buffer size: 1600
I (594) wifi:Init static rx buffer num: 10
I (604) wifi:Init dynamic rx buffer num: 32
I (604) wifi_init: rx ba win: 6
I (604) wifi_init: accept mbox: 6
I (614) wifi_init: tcpip mbox: 32
I (614) wifi_init: udp mbox: 6
I (614) wifi_init: tcp mbox: 6
I (614) wifi_init: tcp tx win: 5760
I (624) wifi_init: tcp rx win: 5760
I (624) wifi_init: tcp mss: 1440
I (624) wifi_init: WiFi IRAM OP enabled
I (634) wifi_init: WiFi RX IRAM OP enabled
I (644) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (714) wifi:mode : softAP (84:1f:e8:39:90:29)
I (724) wifi:Total power save buffer number: 16
I (724) wifi:Init max length of beacon: 752/752
I (724) wifi:Init max length of beacon: 752/752
I (734) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (744) SMART_ATTENDANCE: Attendance Web Server Started at http://192.168.4.1
I (744) main_task: Returned from app_main()
I (5114) wifi:station: 50:fe:0c:00:ab:d9 join, AID=1, bgn, 40U
I (5204) SMART_ATTENDANCE: [PROXIMITY DETECTED]: New student device connected!
I (5264) wifi:<ba-add>idx:2 (ifx:1, 50:fe:0c:00:ab:d9), tid:0, ssn:19, winSize:64
I (5324) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.2
I (22034) wifi:station: 96:2e:48:7a:99:39 join, AID=2, bgn, 20
I (22064) SMART_ATTENDANCE: [PROXIMITY DETECTED]: New student device connected!
I (22664) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.3
I (22964) wifi:<ba-add>idx:3 (ifx:1, 96:2e:48:7a:99:39), tid:0, ssn:16, winSize:64
```
---
## รูปภาพ
<img width="1907" height="580" alt="image" src="https://github.com/user-attachments/assets/55dec670-844c-471b-9779-e8d24c6bb7eb" />



---
## 6. คำถามท้ายการทดลอง (Post-Lab Questions)

1. การใช้ **RF Signal Proximity (RSSI)** ร่วมกับ **HTTP Web Server** บน ESP32 แก้ปัญหาการฝากเช็กชื่อแทนกันในห้องเรียนได้อย่างไร?
> บังคับให้ตัวเครื่องมือถือต้องอยู่ใกล้บอร์ด ESP32 ในระยะที่กำหนดถึงจะเช็คชื่อผ่าน ต่อให้เพื่อนก๊อปปี้ลิงก์ส่งไปให้กดจากนอกห้องเรียนหรือที่บ้าน ก็กดเช็คชื่อไม่ได้อยู่ดี เพราะสัญญาณ Wi-Fi ส่งมาไม่ถึงหรืออ่อนเกินไป
2. เหตุใดระดับเกณฑ์ RSSI ที่ `-55 dBm` จึงเหมาะสมสำหรับการระบุตำแหน่งอุปกรณ์ให้อยู่ภายในรัศมีโต๊ะปฏิบัติการ?
> เพราะค่านี้คือระดับความแรงสัญญาณระยะประชิด (ประมาณ 1-2 เมตร) ซึ่งครอบคลุมแค่บริเวณรอบๆ โต๊ะพอดี ถ้าเดินออกไปไกลกว่านี้ หรือนั่งอยู่โต๊ะกลุ่มอื่น สัญญาณจะตกและไม่ผ่านเกณฑ์ทันที
3. หากต้องการต่อยอดมินิโปรเจกต์นี้ในอนาคต ให้สามารถบันทึกข้อมูลการเข้าเรียนลงระบบ Cloud (เช่น Google Sheets หรือ Firebase) จะต้องเพิ่มส่วนเชื่อมต่อใดบ้าง?
> ต้องให้ ESP32 ไปเกาะ Wi-Fi ที่มีอินเทอร์เน็ตด้วย (ทำโหมด Station) จากนั้นก็เพิ่มโค้ดส่วน HTTP/HTTPS Client เข้าไป เพื่อใช้วิธียิง API ส่งข้อมูลที่เช็คชื่อแล้วขึ้นไปเก็บบน Cloud อีกที
