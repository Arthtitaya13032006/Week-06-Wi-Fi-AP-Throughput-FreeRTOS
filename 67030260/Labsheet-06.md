# ใบงานที่ 6.2: การประเมินความสัมพันธ์ RSSI vs Throughput ด้วย Software Tx-Power Control (Pair Work 👥)
## 5. ตารางบันทึกผลการทดลอง (Experiment Results)

ให้นักศึกษาบันทึกค่าที่ได้จากการทดสอบในระดับ Tx Power ต่างๆ:

| การทดลองที่ | ค่า Tx Power ที่ตั้ง (dBm) | ค่า RSSI ที่อ่านได้จริง (dBm) | เวลาที่ใช้ (Seconds) | ความเร็วที่วัดได้ Throughput (Kbps) |
| :---: | :---: | :---: | :---: | :---: |
| **1** | 20 dBm (Max) | -60|0.83 |870.08 |
| **2** | 15 dBm |-60 |0.83 |870.09  |
| **3** | 10 dBm |-57 |0.12 |3557.82 |
| **4** | 5 dBm |-53 |0.10 |3994.55 |
| **5** | 2 dBm (Min) |-58 |0.12 |3381.89 |

---

## 6. งานวิเคราะห์ข้อมูลเชิงสถิติ (Data Science & Regression Task)

ให้นักศึกษานำค่า **RSSI (x-axis)** และ **Throughput (y-axis)** จากตารางทดลองไปสร้างแผนภาพใน Excel หรือ Python (Jupyter Notebook):

1. สร้างแผนภาพ **Scatter Plot** แสดงจุดข้อมูลระหว่าง RSSI กับ Speed
2. สร้างเส้นแนวโน้ม **Trendline / Regression Curve** (เช่น Logarithmic Regression: $y = a \cdot \ln(x) + b$)
3. คำนวณค่า **$R^2$ (Coefficient of Determination)** เพื่อประเมินความแม่นยำของสมการ
4. ระบุจุด **Threshold RSSI (dBm)** ที่ความเร็วเริ่มลดลงมากกว่า 50% จากระดับสูงสุด

## รูปภาพ
<img width="1068" height="502" alt="image" src="https://github.com/user-attachments/assets/37b81c26-8fdb-4c8a-b0aa-6f64a39f5ff9" />

---

## 7. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เมื่อลดระดับ Tx Power ลงจาก 20 dBm เหลือ 2 dBm ค่า RSSI ลดลงกี่ dBm และส่งผลต่อความเร็ว Throughput อย่างไร?
> จากตัวเลขในตาราง ค่า RSSI แกว่งนิดหน่อยแทบไม่ต่างกัน (จาก -60 เป็น -58) แต่ความเร็ว Throughput ร่วงหนักมาก จากประมาณ 870 Kbps ตกมาเหลือแค่ 381 Kbps เพราะกำลังส่งที่อ่อนลงทำให้ข้อมูลหลุดหายกลางทางเยอะขึ้น
2. เหตุใดในระดับ RSSI ที่อ่อนกว่า `-80 dBm` ความเร็ว Throughput ถึงตกลงอย่างกะทันหันในโปรโตคอล TCP?
> เพราะ TCP ซีเรียสเรื่องส่งข้อมูลให้ถึงแบบชัวร์ๆ พอสัญญาณอ่อนจนแพ็กเก็ตเริ่มหลุด TCP จะนึกว่าเครือข่ายแน่น เลยดึงเบรกชะลอการส่งข้อมูลลงฮวบๆ (ลด Window Size) เพื่อรอให้ฝั่งรับส่งสัญญาณยืนยัน (ACK) กลับมาก่อน
3. สมการ Regression ที่ได้จากการทดลองสามารถนำไปประยุกต์ใช้ทำนายคุณภาพการเชื่อมต่อในแอปพลิเคชัน IoT ได้อย่างไร?
> เอาค่า RSSI ที่อุปกรณ์รับได้ไปเสียบในสมการเพื่อประเมินความเร็วล่วงหน้าได้เลย ช่วยให้ระบบ IoT ตัดสินใจได้เองว่าตอนนั้นเน็ตแรงพอจะส่งไฟล์ใหญ่ๆ (เช่น อัปเดตเฟิร์มแวร์) หรือควรบีบอัดข้อมูลส่งแค่ข้อความสั้นๆ ไปก่อน

---

output log ฝั่ง AP ของ นายธนบดี บุญภมร 67030298

```
I (27) boot: ESP-IDF v6.0.2-dirty 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 10:56:37
I (27) boot: Multicore bootloader
I (29) boot: chip revision: v3.1
I (32) boot.esp32: SPI Speed      : 40MHz
I (36) boot.esp32: SPI Mode       : DIO
I (39) boot.esp32: SPI Flash Size : 2MB
I (43) boot: Enabling RNG early entropy source...
I (47) boot: Partition Table:
I (50) boot: ## Label            Usage          Type ST Offset   Length
I (56) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (63) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (69) boot:  2 factory          factory app      00 00 00010000 00100000
I (76) boot: End of partition table
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1a260h (107104) map
I (125) esp_image: segment 1: paddr=0002a288 vaddr=3ffb0000 size=04528h ( 17704) load
I (132) esp_image: segment 2: paddr=0002e7b8 vaddr=40080000 size=01860h (  6240) load
I (135) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=87ea4h (556708) map
I (335) esp_image: segment 4: paddr=000b7ecc vaddr=40081860 size=13da8h ( 81320) load
I (368) esp_image: segment 5: paddr=000cbc7c vaddr=50000000 size=00028h (    40) load
I (379) boot: Loaded app from partition at offset 0x10000
I (379) boot: Disabling RNG early entropy source...
I (390) cpu_start: Multicore app
I (398) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (398) cpu_start: Pro cpu start user code
I (398) cpu_start: cpu freq: 160000000 Hz
I (400) app_init: Application information:
I (404) app_init: Project name:     main
I (408) app_init: App version:      8d6867b
I (412) app_init: Compile time:     Aug 10 2026 10:55:28
I (417) app_init: ELF file SHA256:  0620e2b0c...
I (421) app_init: ESP-IDF:          v6.0.2-dirty
I (425) efuse_init: Min chip rev:     v0.0
I (429) efuse_init: Max chip rev:     v3.99 
I (433) efuse_init: Chip rev:         v3.1
I (437) heap_init: Initializing. RAM available for dynamic allocation:
I (443) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (448) heap_init: At 3FFB8A20 len 000275E0 (157 KiB): DRAM
I (454) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (459) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (464) heap_init: At 40095608 len 0000A9F8 (42 KiB): IRAM
I (471) spi_flash: detected chip: generic
I (473) spi_flash: flash io: dio
W (476) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (490) main_task: Started on CPU0
I (490) main_task: Calling app_main()
I (490) LAB_SOFTAP: [FORENSIC]: Call nvs_flash_init()
I (530) LAB_SOFTAP: [FORENSIC]: Call esp_netif_init()
I (530) LAB_SOFTAP: [FORENSIC]: Call esp_event_loop_create_default()
I (530) LAB_SOFTAP: [FORENSIC]: Call esp_netif_create_default_wifi_ap()
I (540) LAB_SOFTAP: [FORENSIC]: SoftAP Interface created at 0x3ffbdd78 (Default IP: 192.168.4.1)
I (540) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_init(&cfg)
I (560) wifi:wifi driver task: 3ffc04fc, prio:23, stack:6656, core=0
I (580) wifi:wifi firmware version: 00ad238
I (580) wifi:wifi certification version: v7.0
I (580) wifi:config NVS flash: enabled
I (580) wifi:config nano formatting: disabled
I (580) wifi:Init data frame dynamic rx buffer num: 32
I (590) wifi:Init static rx mgmt buffer num: 5
I (590) wifi:Init management short buffer num: 32
I (590) wifi:Init dynamic tx buffer num: 32
I (600) wifi:Init static rx buffer size: 1600
I (600) wifi:Init static rx buffer num: 10
I (610) wifi:Init dynamic rx buffer num: 32
I (610) wifi_init: rx ba win: 6
I (610) wifi_init: accept mbox: 6
I (610) wifi_init: tcpip mbox: 32
I (620) wifi_init: udp mbox: 6
I (620) wifi_init: tcp mbox: 6
I (620) wifi_init: tcp tx win: 5760
I (630) wifi_init: tcp rx win: 5760
I (630) wifi_init: tcp mss: 1440
I (630) wifi_init: WiFi IRAM OP enabled
I (640) wifi_init: WiFi RX IRAM OP enabled
I (640) LAB_SOFTAP: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (650) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_AP)
I (650) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_AP, &wifi_config)
I (670) LAB_SOFTAP: [FORENSIC]: Call esp_wifi_start()
I (670) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (770) phy_init: Saving new calibration data due to checksum failure or outdated calibration data, mode(0)
I (790) wifi:mode : softAP (84:1f:e8:39:bd:65)
I (790) wifi:Total power save buffer number: 16
I (790) wifi:Init max length of beacon: 752/752
I (800) wifi:Init max length of beacon: 752/752
I (800) LAB_SOFTAP: ==================================================================
I (800) esp_netif_lwip: DHCP server started on interface WIFI_AP_DEF with IP: 192.168.4.1
I (810) LAB_SOFTAP:   ESP32 SoftAP Running! SSID: "ESP32_AP_PlengInwza007", Channel: 1
I (820) LAB_SOFTAP: ==================================================================
I (830) LAB_SOFTAP: [TCP SERVER]: Listening on 192.168.4.1:8080
I (830) main_task: Returned from app_main()
                                                                (41060) wifi:station: 84:1f:e8:39:90:28 join, AID=1, bgn, 40U
I (41100) LAB_SOFTAP: =======================================================
I (41100) LAB_SOFTAP: [FORENSIC EVENT]: Client Connected to ESP32 SoftAP!
I (41100) LAB_SOFTAP:   -> Client MAC Address : 84:1F:E8:39:90:28
I (41110) LAB_SOFTAP:   -> Assigned AID       : 1
I (41110) LAB_SOFTAP: =======================================================
I (41130) esp_netif_lwip: DHCP server assigned IP to a client, IP is: 192.168.4.2
I (42180) wifi:<ba-add>idx:2 (ifx:1, 84:1f:e8:39:90:28), tid:0, ssn:0, winSize:64
I (42580) LAB_SOFTAP: =======================================================
I (42580) LAB_SOFTAP: [TCP SERVER SESSION 1]: Client connected from 192.168.4.2:60395
I (45650) LAB_SOFTAP: [TCP SERVER SESSION 1]: Transfer complete
I (45650) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (45650) LAB_SOFTAP: =======================================================
I (47710) LAB_SOFTAP: =======================================================
I (47720) LAB_SOFTAP: [TCP SERVER SESSION 2]: Client connected from 192.168.4.2:60396
I (48810) LAB_SOFTAP: [TCP SERVER SESSION 2]: Transfer complete
I (48810) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (48810) LAB_SOFTAP: =======================================================
I (50790) LAB_SOFTAP: =======================================================
I (50790) LAB_SOFTAP: [TCP SERVER SESSION 3]: Client connected from 192.168.4.2:60397
I (52320) LAB_SOFTAP: [TCP SERVER SESSION 3]: Transfer complete
I (52320) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (52320) LAB_SOFTAP: =======================================================
I (54340) LAB_SOFTAP: =======================================================
I (54340) LAB_SOFTAP: [TCP SERVER SESSION 4]: Client connected from 192.168.4.2:60398
I (54690) LAB_SOFTAP: [TCP SERVER SESSION 4]: Transfer complete
I (54700) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (54700) LAB_SOFTAP: =======================================================
I (56730) LAB_SOFTAP: =======================================================
I (56730) LAB_SOFTAP: [TCP SERVER SESSION 5]: Client connected from 192.168.4.2:60399
I (57340) LAB_SOFTAP: [TCP SERVER SESSION 5]: Transfer complete
I (57340) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (57340) LAB_SOFTAP: =======================================================
I (59370) LAB_SOFTAP: =======================================================
I (59370) LAB_SOFTAP: [TCP SERVER SESSION 6]: Client connected from 192.168.4.2:60400
I (59850) LAB_SOFTAP: [TCP SERVER SESSION 6]: Transfer complete
I (59860) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (59860) LAB_SOFTAP: =======================================================
I (61880) LAB_SOFTAP: =======================================================
I (61880) LAB_SOFTAP: [TCP SERVER SESSION 7]: Client connected from 192.168.4.2:60401
I (62260) LAB_SOFTAP: [TCP SERVER SESSION 7]: Transfer complete
I (62260) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (62260) LAB_SOFTAP: =======================================================
I (64280) LAB_SOFTAP: =======================================================
I (64280) LAB_SOFTAP: [TCP SERVER SESSION 8]: Client connected from 192.168.4.2:60402
I (64830) LAB_SOFTAP: [TCP SERVER SESSION 8]: Transfer complete
I (64830) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (64830) LAB_SOFTAP: =======================================================
I (66860) LAB_SOFTAP: =======================================================
I (66860) LAB_SOFTAP: [TCP SERVER SESSION 9]: Client connected from 192.168.4.2:60403
I (67180) LAB_SOFTAP: [TCP SERVER SESSION 9]: Transfer complete
I (67180) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (67180) LAB_SOFTAP: =======================================================
I (69210) LAB_SOFTAP: =======================================================
I (69210) LAB_SOFTAP: [TCP SERVER SESSION 10]: Client connected from 192.168.4.2:60404
I (69430) LAB_SOFTAP: [TCP SERVER SESSION 10]: Transfer complete
I (69430) LAB_SOFTAP:   -> Total Received : 51200 Bytes
I (69430) LAB_SOFTAP: =======================================================

```
---
output log ฝั่ง Client

```
art.c:27
I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
I (27) boot: compile time Aug 10 2026 10:30:17
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
I (79) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1a35ch (107356) map
I (124) esp_image: segment 1: paddr=0002a384 vaddr=3ffb0000 size=04528h ( 17704) load
I (132) esp_image: segment 2: paddr=0002e8b4 vaddr=40080000 size=01764h (  5988) load
I (134) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=87620h (554528) map
I (333) esp_image: segment 4: paddr=000b7648 vaddr=40081764 size=13ea4h ( 81572) load
I (367) esp_image: segment 5: paddr=000cb4f4 vaddr=50000000 size=00028h (    40) load
I (378) boot: Loaded app from partition at offset 0x10000
I (378) boot: Disabling RNG early entropy source...
I (389) cpu_start: Multicore app
I (397) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (397) cpu_start: Pro cpu start user code
I (397) cpu_start: cpu freq: 160000000 Hz
I (399) app_init: Application information:
I (403) app_init: Project name:     rssi_speed_profiler
I (408) app_init: App version:      1
I (411) app_init: Compile time:     Aug 10 2026 10:29:57
I (416) app_init: ELF file SHA256:  0722c2dcf...
I (421) app_init: ESP-IDF:          v6.0.2
I (424) efuse_init: Min chip rev:     v0.0
I (428) efuse_init: Max chip rev:     v3.99 
I (432) efuse_init: Chip rev:         v3.1
I (436) heap_init: Initializing. RAM available for dynamic allocation:
I (443) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (447) heap_init: At 3FFB8A40 len 000275C0 (157 KiB): DRAM
I (453) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (458) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (464) heap_init: At 40095608 len 0000A9F8 (42 KiB): IRAM
I (470) spi_flash: detected chip: generic
I (473) spi_flash: flash io: dio
W (475) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (489) main_task: Started on CPU0
I (489) main_task: Calling app_main()
I (489) CLIENT_PROFILER: [FORENSIC]: Call nvs_flash_init()
I (529) CLIENT_PROFILER: [FORENSIC]: Call esp_netif_init()
I (529) CLIENT_PROFILER: [FORENSIC]: Call esp_event_loop_create_default()
I (529) CLIENT_PROFILER: [FORENSIC]: Call esp_netif_create_default_wifi_sta()
I (539) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_init(&config)
I (559) wifi:wifi driver task: 3ffc04ac, prio:23, stack:6656, core=0
I (579) wifi:wifi firmware version: 00ad238
I (579) wifi:wifi certification version: v7.0
I (579) wifi:config NVS flash: enabled
I (579) wifi:config nano formatting: disabled
I (589) wifi:Init data frame dynamic rx buffer num: 32
I (589) wifi:Init static rx mgmt buffer num: 5
I (589) wifi:Init management short buffer num: 32
I (599) wifi:Init dynamic tx buffer num: 32
I (599) wifi:Init static rx buffer size: 1600
I (609) wifi:Init static rx buffer num: 10
I (609) wifi:Init dynamic rx buffer num: 32
I (619) wifi_init: rx ba win: 6
I (619) wifi_init: accept mbox: 6
I (619) wifi_init: tcpip mbox: 32
I (619) wifi_init: udp mbox: 6
I (629) wifi_init: tcp mbox: 6
I (629) wifi_init: tcp tx win: 5760
I (629) wifi_init: tcp rx win: 5760
I (639) wifi_init: tcp mss: 1440
I (639) wifi_init: WiFi IRAM OP enabled
I (639) wifi_init: WiFi RX IRAM OP enabled
I (649) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_STA)
I (649) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA, &wifi_config)
I (659) CLIENT_PROFILER: [FORENSIC]: Call esp_wifi_start()
I (669) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
I (739) phy_init: Saving new calibration data due to checksum failure or outdated calibration data, mode(0)
I (769) wifi:mode : sta (84:1f:e8:39:90:28)
I (769) wifi:enable tsf
I (769) CLIENT_PROFILER: Client profiler ready: 50 KB x 10 rounds
I (769) CLIENT_PROFILER: [FORENSIC EVENT]: Station started; connecting to ESP32_AP_PlengInwza007
I (779) main_task: Returned from app_main()
W (3199) CLIENT_PROFILER: [FORENSIC EVENT]: Disconnected, reason=201
I (3199) CLIENT_PROFILER: Retrying Wi-Fi connection (1/10)
W (5609) CLIENT_PROFILER: [FORENSIC EVENT]: Disconnected, reason=201
I (5609) CLIENT_PROFILER: Retrying Wi-Fi connection (2/10)
W (8029) CLIENT_PROFILER: [FORENSIC EVENT]: Disconnected, reason=201
I (8029) CLIENT_PROFILER: Retrying Wi-Fi connection (3/10)
I (8039) wifi:new:<1,1>, old:<1,0>, ap:<255,255>, sta:<1,1>, prof:1, snd_ch_cfg:0x0
I (8049) wifi:state: init -> auth (0xb0)
I (8059) wifi:state: auth -> assoc (0x0)
I (8069) wifi:state: assoc -> run (0x10)
I (8099) wifi:connected with ESP32_AP_PlengInwza007, aid = 1, channel 1, 40U, bssid = 84:1f:e8:39:bd:65
I (8109) wifi:security: WPA2-PSK, phy: bgn, rssi: -60, cipher(pairwise:0x3, group:0x3), pmf:1
I (8119) wifi:pm start, type: 1

I (8119) wifi:dp: 1, bi: 102400, li: 3, scale listen interval from 307200 us to 307200 us
I (8149) wifi:AP's beacon interval = 102400 us, DTIM period = 1
I (9149) esp_netif_handlers: sta ip: 192.168.4.2, mask: 255.255.255.0, gw: 192.168.4.1
I (9149) CLIENT_PROFILER: [FORENSIC EVENT]: Connected; IP=192.168.4.2
I (9149) CLIENT_PROFILER: [ROUND 1/10]: Connecting to 192.168.4.1:8080
I (9169) wifi:<ba-add>idx:0 (ifx:0, 84:1f:e8:39:bd:65), tid:0, ssn:0, winSize:64
I (12439) CLIENT_PROFILER: =======================================================
I (12439) CLIENT_PROFILER:  [BENCHMARK RESULT 1/10]
I (12449) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (12449) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (12459) CLIENT_PROFILER:   -> Time Elapsed       : 2.978 Seconds
I (12459) CLIENT_PROFILER:   -> Measured Speed     : 137.53 Kbps
I (12469) CLIENT_PROFILER: =======================================================
I (14479) CLIENT_PROFILER: [ROUND 2/10]: Connecting to 192.168.4.1:8080
I (15669) CLIENT_PROFILER: =======================================================
I (15669) CLIENT_PROFILER:  [BENCHMARK RESULT 2/10]
I (15669) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (15669) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (15679) CLIENT_PROFILER:   -> Time Elapsed       : 1.066 Seconds
I (15679) CLIENT_PROFILER:   -> Measured Speed     : 384.21 Kbps
I (15689) CLIENT_PROFILER: =======================================================
I (17699) CLIENT_PROFILER: [ROUND 3/10]: Connecting to 192.168.4.1:8080
I (19229) CLIENT_PROFILER: =======================================================
I (19229) CLIENT_PROFILER:  [BENCHMARK RESULT 3/10]
I (19229) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (19239) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (19239) CLIENT_PROFILER:   -> Time Elapsed       : 1.434 Seconds
I (19249) CLIENT_PROFILER:   -> Measured Speed     : 285.70 Kbps
I (19249) CLIENT_PROFILER: =======================================================
I (21259) CLIENT_PROFILER: [ROUND 4/10]: Connecting to 192.168.4.1:8080
I (21699) CLIENT_PROFILER: =======================================================
I (21699) CLIENT_PROFILER:  [BENCHMARK RESULT 4/10]
I (21699) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (21699) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (21709) CLIENT_PROFILER:   -> Time Elapsed       : 0.354 Seconds
I (21719) CLIENT_PROFILER:   -> Measured Speed     : 1156.89 Kbps
I (21719) CLIENT_PROFILER: =======================================================
I (23729) CLIENT_PROFILER: [ROUND 5/10]: Connecting to 192.168.4.1:8080
I (24339) CLIENT_PROFILER: =======================================================
I (24339) CLIENT_PROFILER:  [BENCHMARK RESULT 5/10]
I (24339) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (24349) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (24349) CLIENT_PROFILER:   -> Time Elapsed       : 0.606 Seconds
I (24359) CLIENT_PROFILER:   -> Measured Speed     : 675.81 Kbps
I (24359) CLIENT_PROFILER: =======================================================
I (26369) CLIENT_PROFILER: [ROUND 6/10]: Connecting to 192.168.4.1:8080
I (26839) CLIENT_PROFILER: =======================================================
I (26849) CLIENT_PROFILER:  [BENCHMARK RESULT 6/10]
I (26849) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (26849) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (26859) CLIENT_PROFILER:   -> Time Elapsed       : 0.470 Seconds
I (26859) CLIENT_PROFILER:   -> Measured Speed     : 871.11 Kbps
I (26869) CLIENT_PROFILER: =======================================================
I (28879) CLIENT_PROFILER: [ROUND 7/10]: Connecting to 192.168.4.1:8080
I (29249) CLIENT_PROFILER: =======================================================
I (29249) CLIENT_PROFILER:  [BENCHMARK RESULT 7/10]
I (29249) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (29259) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (29269) CLIENT_PROFILER:   -> Time Elapsed       : 0.365 Seconds
I (29269) CLIENT_PROFILER:   -> Measured Speed     : 1121.89 Kbps
I (29279) CLIENT_PROFILER: =======================================================
I (31279) CLIENT_PROFILER: [ROUND 8/10]: Connecting to 192.168.4.1:8080
I (31829) CLIENT_PROFILER: =======================================================
I (31829) CLIENT_PROFILER:  [BENCHMARK RESULT 8/10]
I (31829) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (31829) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (31839) CLIENT_PROFILER:   -> Time Elapsed       : 0.536 Seconds
I (31839) CLIENT_PROFILER:   -> Measured Speed     : 763.75 Kbps
I (31849) CLIENT_PROFILER: =======================================================
I (33859) CLIENT_PROFILER: [ROUND 9/10]: Connecting to 192.168.4.1:8080
I (34179) CLIENT_PROFILER: =======================================================
I (34179) CLIENT_PROFILER:  [BENCHMARK RESULT 9/10]
I (34179) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (34189) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (34189) CLIENT_PROFILER:   -> Time Elapsed       : 0.315 Seconds
I (34199) CLIENT_PROFILER:   -> Measured Speed     : 1301.36 Kbps
I (34209) CLIENT_PROFILER: =======================================================
I (36209) CLIENT_PROFILER: [ROUND 10/10]: Connecting to 192.168.4.1:8080
I (36419) CLIENT_PROFILER: =======================================================
I (36419) CLIENT_PROFILER:  [BENCHMARK RESULT 10/10]
I (36419) CLIENT_PROFILER:   -> Current RSSI       : -60 dBm
I (36419) CLIENT_PROFILER:   -> Total Transferred  : 51200 Bytes
I (36429) CLIENT_PROFILER:   -> Time Elapsed       : 0.205 Seconds
I (36439) CLIENT_PROFILER:   -> Measured Speed     : 2002.62 Kbps
I (36439) CLIENT_PROFILER: =======================================================
I (38449) CLIENT_PROFILER: All benchmark rounds completed

```
