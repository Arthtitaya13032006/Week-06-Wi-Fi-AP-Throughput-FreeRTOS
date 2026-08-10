## 5. ตารางบันทึกผลการทดลอง (Experiment Results)

### 5.1 ตารางบันทึกการเช็กชื่อผ่าน RF Proximity

| ลำดับที่ | ชื่อสมาร์ตโฟน / MAC Address | ระดับ RSSI (dBm) | ระยะทางประเมิน (Near/Far) | ผลการลงชื่อ (Passed/Rejected) |
| :---: | :--- | :---: | :---: | :---: |
| **1** | `1A:CA:3D:B0:AA:01` | -45 | NEAR | Passed |
| **2** | `C2:F5:E7:CC:77:D6` | -45 | NEAR | Passed |
| **3** | `02:F5:21:53:45:12` | -45 | NEAR | Passed |

---

### output log
```
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 11:00:33
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
I (422) app_init: App version:      b66270d-dirty
I (427) app_init: Compile time:     Aug 10 2026 10:57:19
I (432) app_init: ELF file SHA256:  b14dafa6f...
I (436) app_init: ESP-IDF:          v6.0.2
I (440) efuse_init: Min chip rev:     v0.0
I (444) efuse_init: Max chip rev:     v3.99 
I (448) efuse_init: Chip rev:         v3.1
I (452) heap_init: Initializing. RAM available for dynamic allocation:
I (458) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (463) heap_init: At 3FFB8AA0 len 00027560 (157 KiB): DRAM
I (468) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (473) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (479) heap_init: At 4009562C len 0000A9D4 (42 KiB): IRAM
W (485) spi_flash: Detected boya flash chip but using generic driver. For optimal functionality, enable `SPI_FLASH_SUPPORT_BOYA_CHIP` in menuconfig
I (497) spi_flash: detected chip: generic
I (501) spi_flash: flash io: dio
W (504) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (518) main_task: Started on CPU0
I (518) main_task: Calling app_main()
I (568) wifi:wifi driver task: 3ffc057c, prio:23, stack:6656, core=0
I (588) wifi:wifi firmware version: 00ad238
I (588) wifi:wifi certification version: v7.0
I (588) wifi:config NVS flash: enabled
I (588) wifi:config nano formatting: disabled
I (588) wifi:Init data frame dynamic rx buffer num: 32
I (598) wifi:Init static rx mgmt buffer num: 5
I (598) wifi:Init management short buffer num: 32
I (598) wifi:Init dynamic tx buffer num: 32
I (608) wifi:Init static rx buffer size: 1600
I (608) wifi:Init static rx buffer num: 10
I (618) wifi:Init dynamic rx buffer num: 32
I (618) wifi_init: rx ba win: 6
I (618) wifi_init: accept mbox: 6
I (628) wifi_init: tcpip mbox: 32
I (628) wifi_init: udp mbox: 6
I (628) wifi_init: tcp mbox: 6
I (628) wifi_init: tcp tx win: 5760
I (638) wifi_init: tcp rx win: 5760
I (638) wifi_init: tcp mss: 1440
I (638) wifi_init: WiFi IRAM OP enabled
I (648) wifi_init: WiFi RX IRAM OP enabled
I (658) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (748) phy_init: Saving new calibration data due to checksum failure or outdated calibration data, mode(0)
I (768) wifi:mode : softAP (88:57:21:ae:1d:89)
I (778) wifi:Total power save buffer number: 16
I (778) wifi:Init max length of beacon: 752/752
I (778) wifi:Init max length of beacon: 752/752
I (778) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (788) SMART_ATTENDANCE: Attendance Web Server Started at http://192.168.4.1
I (788) main_task: Returned from app_main()
I (21708) wifi:new:<1,0>, old:<1,1>, ap:<1,1>, sta:<255,255>, prof:1, snd_ch_cfg:0x0
I (21708) wifi:station: 1a:ca:3d:b0:aa:01 join, AID=1, bgn, 20
I (21798) SMART_ATTENDANCE: [PROXIMITY DETECTED]: New student device connected!
I (21928) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.2
I (22108) wifi:<ba-add>idx:2 (ifx:1, 1a:ca:3d:b0:aa:01), tid:0, ssn:16, winSize:64
W (35908) httpd_uri: httpd_uri: URI '/checkin' not found
W (35908) httpd_txrx: httpd_resp_send_err: 404 Not Found - Nothing matches the given URI
I (61388) wifi:station: 1a:ca:3d:b0:aa:01 leave, AID = 1, reason = 3, bss_flags is 691299, bss:0x3ffb9e54
I (61388) wifi:<ba-del>idx:2, tid:0
I (61388) wifi:new:<1,1>, old:<1,0>, ap:<1,1>, sta:<255,255>, prof:1, snd_ch_cfg:0x0
```

---

### รูปภาพตอนเข้าเว็บ
![alt text](/report/img/image3.png)

---

## 6. คำถามท้ายการทดลอง (Post-Lab Questions)

1. การใช้ **RF Signal Proximity (RSSI)** ร่วมกับ **HTTP Web Server** บน ESP32 แก้ปัญหาการฝากเช็กชื่อแทนกันในห้องเรียนได้อย่างไร?
```
การใช้ RSSI ร่วมกับระบบ Web Server ที่ทำงานแบบเครือข่ายท้องถิ่น ทำให้ระบบสามารถยืนยัน "ระยะห่างทางกายภาพ" ของผู้เรียนได้จริง หากนักศึกษาพยายามส่งลิงก์ให้เพื่อนกดเช็กชื่อจากระยะไกล ระดับสัญญาณ RSSI จะอ่อนกว่าเกณฑ์ที่กำหนดไว้ ระบบจะตรวจจับได้ว่าอุปกรณ์อยู่ไกลเกินไป และปฏิเสธการลงชื่อทันที เป็นการบังคับให้นักศึกษาต้องนำอุปกรณ์ของตนเองเข้ามาอยู่ในระยะทำการของห้องเรียนเพื่อแสดงตัวตน
```

2. เหตุใดระดับเกณฑ์ RSSI ที่ `-55 dBm` จึงเหมาะสมสำหรับการระบุตำแหน่งอุปกรณ์ให้อยู่ภายในรัศมีโต๊ะปฏิบัติการ?
```
ระดับสัญญาณ -55 dBm เป็นค่าความแรงที่บ่งบอกถึงระยะห่างที่ใกล้มาก การใช้เกณฑ์นี้จะช่วยกรองอุปกรณ์ที่อยู่บริเวณโถงทางเดิน นอกห้องเรียน หรือโต๊ะกลุ่มอื่นออกไปได้อย่างมีประสิทธิภาพ เนื่องจากสัญญาณวิทยุจะถูกลดทอน ทั้งจากระยะทางและสิ่งกีดขวาง ทำให้ผู้ที่ไม่ได้อยู่ใกล้โต๊ะปฏิบัติการจะมีค่า RSSI ต่ำกว่า -55 dBm อย่างแน่นอน
```

3. หากต้องการต่อยอดมินิโปรเจกต์นี้ในอนาคต ให้สามารถบันทึกข้อมูลการเข้าเรียนลงระบบ Cloud (เช่น Google Sheets หรือ Firebase) จะต้องเพิ่มส่วนเชื่อมต่อใดบ้าง?
```
เนื่องจากในปัจจุบันระบบทำงานแบบ Local  เท่านั้น หากต้องการส่งข้อมูลขึ้น Cloud จะต้องเพิ่มการทำงาน 2 ส่วนหลัก ได้แก่:
1. ปรับโหมดการทำงานของ Wi-Fi : เปลี่ยนจาก WIFI_MODE_AP เป็น WIFI_MODE_APSTA เพื่อให้ ESP32 สามารถปล่อยสัญญาณให้นักศึกษาเชื่อมต่อได้ พร้อมๆ กับการไปเกาะเครือข่าย Wi-Fi ของมหาวิทยาลัยเพื่อเชื่อมต่ออินเทอร์เน็ต
2. เพิ่มไลบรารี HTTP Client / MQTT : ใช้ `esp_http_client` สำหรับการส่ง HTTP POST Request หรือใช้โปรโตคอล MQTT เพื่อส่งข้อมูล MAC Address และเวลา ของผู้ที่ผ่านการเช็กชื่อขึ้นไปยังเซิร์ฟเวอร์ Cloud หรือ Webhook ของ Google Sheets
```
