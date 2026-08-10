## 5. ตารางบันทึกผลการทดลอง (Experiment Results)

ให้นักศึกษาบันทึกค่าที่ได้จากการทดสอบในระดับ Tx Power ต่างๆ:

| การทดลองที่ | ค่า Tx Power ที่ตั้ง (dBm) | ค่า RSSI ที่อ่านได้จริง (dBm) | เวลาที่ใช้ (Seconds) | ความเร็วที่วัดได้ Throughput (Kbps) |
| :---: | :---: | :---: | :---: | :---: |
| **1** | 20 dBm (Max) | -21 dBm | 0.237 | 1728.66 |
| **2** | 15 dBm | -22 dBm | 0.259 | 1582.41 |
| **3** | 10 dBm | -27 dBm | 0.287 | 1425.45 |
| **4** | 5 dBm | -50 dBm | 0.743 | 550.95 |
| **5** | 2 dBm (Min) | -55 dBm | 1.073 | 381.71 |

---

## 6. งานวิเคราะห์ข้อมูลเชิงสถิติ (Data Science & Regression Task)

ให้นักศึกษานำค่า **RSSI (x-axis)** และ **Throughput (y-axis)** จากตารางทดลองไปสร้างแผนภาพใน Excel หรือ Python (Jupyter Notebook):

1. สร้างแผนภาพ **Scatter Plot** แสดงจุดข้อมูลระหว่าง RSSI กับ Speed
2. สร้างเส้นแนวโน้ม **Trendline / Regression Curve** (เช่น Logarithmic Regression: $y = a \cdot \ln(x) + b$)
3. คำนวณค่า **$R^2$ (Coefficient of Determination)** เพื่อประเมินความแม่นยำของสมการ
4. ระบุจุด **Threshold RSSI (dBm)** ที่ความเร็วเริ่มลดลงมากกว่า 50% จากระดับสูงสุด
```
ความเร็วสูงสุดในตาราง : 1728.66 Kbps
ความเร็วที่ลดลง : 1728.66 / 2 = 864.33 Kbps
```
![alt text](/report/img/image.png)

---

## 7. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เมื่อลดระดับ Tx Power ลงจาก 20 dBm เหลือ 2 dBm ค่า RSSI ลดลงกี่ dBm และส่งผลต่อความเร็ว Throughput อย่างไร?
```
ในทางทฤษฎี เมื่อกำลังส่ง ถูกลดลง 18 dBm ค่า RSSI ที่อุปกรณ์ฝั่งรับวัดได้จะลดลงในสัดส่วนที่ใกล้เคียงกันคือประมาณ 18 dBm การลดลงของค่า RSSI ทำให้อัตราส่วนสัญญาณต่อสัญญาณรบกวน ต่ำลง ส่งผลให้ฮาร์ดแวร์ Wi-Fi ต้องพยายามรักษาเสถียรภาพของการเชื่อมต่อโดยการปรับลดรูปแบบการมอดูเลตสัญญาณ ลงไปยังระดับที่ทนทานต่อสัญญาณรบกวนได้มากขึ้น ซึ่งแลกมาด้วยอัตราการส่งข้อมูลที่ช้าลง ทำให้ Throughput โดยรวมลดลงตามไปด้วย
```

2. เหตุใดในระดับ RSSI ที่อ่อนกว่า `-80 dBm` ความเร็ว Throughput ถึงตกลงอย่างกะทันหันในโปรโตคอล TCP?
```
เมื่อค่า RSSI อ่อนกว่า -80 dBm สัญญาณจะอยู่ใกล้เคียงกับระดับสัญญาณรบกวนพื้นฐาน มาก ทำให้เกิดความผิดพลาดในการส่งข้อมูลระดับบิตสูง และทำให้แพ็กเก็ตสูญหาย

เนื่องจาก TCP เป็นโปรโตคอลที่รับประกันการส่งข้อมูลถึงปลายทาง เมื่อเกิดแพ็กเก็ตสูญหายและไม่ได้รับสัญญาณตอบรับ ภายในเวลาที่กำหนด กลไกควบคุมความแออัดของ TCP จะมองว่าเครือข่ายกำลังมีปัญหา จึงตอบสนองด้วยการหั่นขนาดหน้าต่างการส่งข้อมูล ลงครึ่งหนึ่งทันที ส่งผลให้ความเร็ว Throughput ร่วงลงอย่างกะทันหันและรุนแรง
```

3. สมการ Regression ที่ได้จากการทดลองสามารถนำไปประยุกต์ใช้ทำนายคุณภาพการเชื่อมต่อในแอปพลิเคชัน IoT ได้อย่างไร?
```
สมการ Regression ที่แสดงความสัมพันธ์ระหว่าง RSSI และ Throughput สามารถนำไปฝังไว้ในซอร์สโค้ดหรือเฟิร์มแวร์ของอุปกรณ์ IoT เพื่อสร้าง "ระบบประเมินตนเองอัตโนมัติ" ได้ 
อุปกรณ์ IoT สามารถอ่านค่า RSSI ในขณะนั้นแล้วนำไปเข้าสมการเพื่อทำนาย Throughput ล่วงหน้า หากพบว่าเครือข่ายช้าเกินกว่าที่คาดการณ์ไว้ อุปกรณ์จะสามารถปรับตัว  ได้ เช่น ตัดสินใจเลื่อนการอัปเดตเฟิร์มแวร์ ออกไปก่อน, บีบอัดภาพถ่ายให้เล็กลงก่อนส่ง, หรือแจ้งเตือนสถานะ "สัญญาณอ่อน" ไปยังหน้าแดชบอร์ดของผู้ดูแลระบบเพื่อป้องกันการทำงานผิดพลาด
```

---

## output log ฝั่ง AP
```
[+] Connected by ESP32 at ('10.241.132.83', 62690)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62691)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62692)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62693)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62694)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62695)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62696)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62697)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62698)
[-] Connection closed. Total data received: 51200 bytes.

[+] Connected by ESP32 at ('10.241.132.83', 62699)
[-] Connection closed. Total data received: 51200 bytes.

```

## output log ฝั่ง Client
```
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 09:39:06
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
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1a3bch (107452) map
I (124) esp_image: segment 1: paddr=0002a3e4 vaddr=3ffb0000 size=04528h ( 17704) load
I (132) esp_image: segment 2: paddr=0002e914 vaddr=40080000 size=01704h (  5892) load
I (134) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=87604h (554500) map
I (333) esp_image: segment 4: paddr=000b762c vaddr=40081704 size=13f04h ( 81668) load
I (367) esp_image: segment 5: paddr=000cb538 vaddr=50000000 size=00028h (    40) load
I (378) boot: Loaded app from partition at offset 0x10000
I (378) boot: Disabling RNG early entropy source...
I (389) cpu_start: Multicore app
I (397) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (397) cpu_start: Pro cpu start user code
I (397) cpu_start: cpu freq: 160000000 Hz
I (399) app_init: Application information:
I (403) app_init: Project name:     rssi_speed_profiler
I (408) app_init: App version:      207fc44-dirty
I (412) app_init: Compile time:     Aug 10 2026 09:38:46
I (417) app_init: ELF file SHA256:  b2bbe4e0e...
I (422) app_init: ESP-IDF:          v6.0.2
I (426) efuse_init: Min chip rev:     v0.0
I (429) efuse_init: Max chip rev:     v3.99 
I (433) efuse_init: Chip rev:         v3.1
I (437) heap_init: Initializing. RAM available for dynamic allocation:
I (444) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (449) heap_init: At 3FFB8A40 len 000275C0 (157 KiB): DRAM
I (454) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (459) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (465) heap_init: At 40095608 len 0000A9F8 (42 KiB): IRAM
W (471) spi_flash: Detected boya flash chip but using generic driver. For optimal functionality, enable `SPI_FLASH_SUPPORT_BOYA_CHIP` in menuconfig
I (483) spi_flash: detected chip: generic
I (487) spi_flash: flash io: dio
W (490) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (504) main_task: Started on CPU0
I (504) main_task: Calling app_main()
I (504) CLIENT_PROFILER: [FORENSIC]: Call nvs_flash_init()
I (544) CLIENT_PROFILER: [FORENSIC]: Call esp_netif_init()
I (544) CLIENT_PROFILER: [FORENSIC]: Call esp_event_loop_create_default()
I (544) CLIENT_PROFILER: [FORENSIC]: Call esp_netif_create_default_wifi_sta()
I (554) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_init(&config)
I (574) wifi:wifi driver task: 3ffc04ac, prio:23, stack:6656, core=0
I (594) wifi:wifi firmware version: 00ad238
I (594) wifi:wifi certification version: v7.0
I (594) wifi:config NVS flash: enabled
I (594) wifi:config nano formatting: disabled
I (604) wifi:Init data frame dynamic rx buffer num: 32
I (604) wifi:Init static rx mgmt buffer num: 5
I (604) wifi:Init management short buffer num: 32
I (614) wifi:Init dynamic tx buffer num: 32
I (614) wifi:Init static rx buffer size: 1600
I (624) wifi:Init static rx buffer num: 10
I (624) wifi:Init dynamic rx buffer num: 32
I (634) wifi_init: rx ba win: 6
I (634) wifi_init: accept mbox: 6
I (634) wifi_init: tcpip mbox: 32
I (634) wifi_init: udp mbox: 6
I (644) wifi_init: tcp mbox: 6
I (644) wifi_init: tcp tx win: 5760
I (644) wifi_init: tcp rx win: 5760
I (654) wifi_init: tcp mss: 1440
I (654) wifi_init: WiFi IRAM OP enabled
I (654) wifi_init: WiFi RX IRAM OP enabled
I (664) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_STA)
I (664) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA, &wifi_config)
I (674) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_start()
I (684) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (774) phy_init: Saving new calibration data due to checksum failure or outdated calibration data, mode(0)
I (794) wifi:mode : sta (88:57:21:ae:1d:88)
I (794) wifi:enable tsf
I (794) CLIENT_PROFILER: Client profiler ready: 50 KB x 10 rounds
I (794) CLIENT_PROFILER: [FORENSIC EVENT]: Station started; connecting to Pornprom
I (804) main_task: Returned from app_main()
I (824) wifi:new:<6,0>, old:<1,0>, ap:<255,255>, sta:<6,0>, prof:1, snd_ch_cfg:0x0
I (824) wifi:state: init -> auth (0xb0)
I (834) wifi:state: auth -> assoc (0x0)
I (844) wifi:state: assoc -> run (0x10)
I (994) wifi:connected with Pornprom, aid = 2, channel 6, BW20, bssid = 2e:fe:61:42:3d:24
I (994) wifi:security: WPA2-PSK, phy: bgn, rssi: -27, cipher(pairwise:0x3, group:0x3), pmf:0
I (1004) wifi:pm start, type: 1

I (1004) wifi:dp: 1, bi: 102400, li: 3, scale listen interval from 307200 us to 307200 us
I (1004) wifi:dp: 2, bi: 102400, li: 4, scale listen interval from 307200 us to 409600 us
I (1014) wifi:AP's beacon interval = 102400 us, DTIM period = 2
I (2054) esp_netif_handlers: sta ip: 10.241.132.83, mask: 255.255.255.0, gw: 10.241.132.54
I (2054) CLIENT_PROFILER: [FORENSIC EVENT]: Connected; IP=10.241.132.83
I (2054) CLIENT_PROFILER: =======================================================
I (2064) CLIENT_PROFILER:  [BENCHMARK ROUND 1/10] Attempting to connect to Server...
I (2064) CLIENT_PROFILER:   -> Current RSSI       : -22 dBm
I (2364) wifi:<ba-add>idx:0 (ifx:0, 2e:fe:61:42:3d:24), tid:0, ssn:16, winSize:64
I (2384) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (2394) CLIENT_PROFILER:   -> Time Elapsed       : 0.259 Seconds
I (2394) CLIENT_PROFILER:   -> Measured Speed     : 1582.41 Kbps
I (2394) CLIENT_PROFILER: =======================================================

I (4404) CLIENT_PROFILER: =======================================================
I (4404) CLIENT_PROFILER:  [BENCHMARK ROUND 2/10] Attempting to connect to Server...
I (4404) CLIENT_PROFILER:   -> Current RSSI       : -27 dBm
I (4934) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (4934) CLIENT_PROFILER:   -> Time Elapsed       : 0.512 Seconds
I (4934) CLIENT_PROFILER:   -> Measured Speed     : 800.08 Kbps
I (4944) CLIENT_PROFILER: =======================================================

I (6944) CLIENT_PROFILER: =======================================================
I (6944) CLIENT_PROFILER:  [BENCHMARK ROUND 3/10] Attempting to connect to Server...
I (6944) CLIENT_PROFILER:   -> Current RSSI       : -22 dBm
I (7354) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (7354) CLIENT_PROFILER:   -> Time Elapsed       : 0.396 Seconds
I (7354) CLIENT_PROFILER:   -> Measured Speed     : 1034.93 Kbps
I (7364) CLIENT_PROFILER: =======================================================

I (9374) CLIENT_PROFILER: =======================================================
I (9374) CLIENT_PROFILER:  [BENCHMARK ROUND 4/10] Attempting to connect to Server...
I (9374) CLIENT_PROFILER:   -> Current RSSI       : -27 dBm
I (9674) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (9674) CLIENT_PROFILER:   -> Time Elapsed       : 0.240 Seconds
I (9674) CLIENT_PROFILER:   -> Measured Speed     : 1704.83 Kbps
I (9684) CLIENT_PROFILER: =======================================================

I (11694) CLIENT_PROFILER: =======================================================
I (11694) CLIENT_PROFILER:  [BENCHMARK ROUND 5/10] Attempting to connect to Server...
I (11694) CLIENT_PROFILER:   -> Current RSSI       : -26 dBm
I (11904) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (11904) CLIENT_PROFILER:   -> Time Elapsed       : 0.195 Seconds
I (11904) CLIENT_PROFILER:   -> Measured Speed     : 2102.19 Kbps
I (11914) CLIENT_PROFILER: =======================================================

I (13914) CLIENT_PROFILER: =======================================================
I (13914) CLIENT_PROFILER:  [BENCHMARK ROUND 6/10] Attempting to connect to Server...
I (13914) CLIENT_PROFILER:   -> Current RSSI       : -27 dBm
I (14254) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (14254) CLIENT_PROFILER:   -> Time Elapsed       : 0.287 Seconds
I (14254) CLIENT_PROFILER:   -> Measured Speed     : 1425.45 Kbps
I (14264) CLIENT_PROFILER: =======================================================

I (16274) CLIENT_PROFILER: =======================================================
I (16274) CLIENT_PROFILER:  [BENCHMARK ROUND 7/10] Attempting to connect to Server...
I (16274) CLIENT_PROFILER:   -> Current RSSI       : -23 dBm
I (16774) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (16774) CLIENT_PROFILER:   -> Time Elapsed       : 0.472 Seconds
I (16774) CLIENT_PROFILER:   -> Measured Speed     : 866.93 Kbps
I (16774) CLIENT_PROFILER: =======================================================

I (18784) CLIENT_PROFILER: =======================================================
I (18784) CLIENT_PROFILER:  [BENCHMARK ROUND 8/10] Attempting to connect to Server...
I (18784) CLIENT_PROFILER:   -> Current RSSI       : -21 dBm
I (19044) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (19044) CLIENT_PROFILER:   -> Time Elapsed       : 0.237 Seconds
I (19044) CLIENT_PROFILER:   -> Measured Speed     : 1728.66 Kbps
I (19044) CLIENT_PROFILER: =======================================================

I (21054) CLIENT_PROFILER: =======================================================
I (21054) CLIENT_PROFILER:  [BENCHMARK ROUND 9/10] Attempting to connect to Server...
I (21054) CLIENT_PROFILER:   -> Current RSSI       : -55 dBm
I (22184) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (22184) CLIENT_PROFILER:   -> Time Elapsed       : 1.073 Seconds
I (22184) CLIENT_PROFILER:   -> Measured Speed     : 381.71 Kbps
I (22184) CLIENT_PROFILER: =======================================================

I (24194) CLIENT_PROFILER: =======================================================
I (24194) CLIENT_PROFILER:  [BENCHMARK ROUND 10/10] Attempting to connect to Server...
I (24194) CLIENT_PROFILER:   -> Current RSSI       : -50 dBm
I (24954) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (24954) CLIENT_PROFILER:   -> Time Elapsed       : 0.743 Seconds
I (24954) CLIENT_PROFILER:   -> Measured Speed     : 550.95 Kbps
I (24964) CLIENT_PROFILER: =======================================================

I (26974) CLIENT_PROFILER: All benchmark rounds completed

```