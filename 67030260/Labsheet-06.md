# ใบงานที่ 6.2: การประเมินความสัมพันธ์ RSSI vs Throughput ด้วย Software Tx-Power Control (Pair Work 👥)
## 5. ตารางบันทึกผลการทดลอง (Experiment Results)

ให้นักศึกษาบันทึกค่าที่ได้จากการทดสอบในระดับ Tx Power ต่างๆ:

| การทดลองที่ | ค่า Tx Power ที่ตั้ง (dBm) | ค่า RSSI ที่อ่านได้จริง (dBm) | เวลาที่ใช้ (Seconds) | ความเร็วที่วัดได้ Throughput (Kbps) |
| :---: | :---: | :---: | :---: | :---: |
| **1** | 20 dBm (Max) | | | |
| **2** | 15 dBm | | | |
| **3** | 10 dBm | | | |
| **4** | 5 dBm | | | |
| **5** | 2 dBm (Min) | | | |

---

## 6. งานวิเคราะห์ข้อมูลเชิงสถิติ (Data Science & Regression Task)

ให้นักศึกษานำค่า **RSSI (x-axis)** และ **Throughput (y-axis)** จากตารางทดลองไปสร้างแผนภาพใน Excel หรือ Python (Jupyter Notebook):

1. สร้างแผนภาพ **Scatter Plot** แสดงจุดข้อมูลระหว่าง RSSI กับ Speed
2. สร้างเส้นแนวโน้ม **Trendline / Regression Curve** (เช่น Logarithmic Regression: $y = a \cdot \ln(x) + b$)
3. คำนวณค่า **$R^2$ (Coefficient of Determination)** เพื่อประเมินความแม่นยำของสมการ
4. ระบุจุด **Threshold RSSI (dBm)** ที่ความเร็วเริ่มลดลงมากกว่า 50% จากระดับสูงสุด

---

## 7. คำถามท้ายการทดลอง (Post-Lab Questions)

1. เมื่อลดระดับ Tx Power ลงจาก 20 dBm เหลือ 2 dBm ค่า RSSI ลดลงกี่ dBm และส่งผลต่อความเร็ว Throughput อย่างไร?
2. เหตุใดในระดับ RSSI ที่อ่อนกว่า `-80 dBm` ความเร็ว Throughput ถึงตกลงอย่างกะทันหันในโปรโตคอล TCP?
3. สมการ Regression ที่ได้จากการทดลองสามารถนำไปประยุกต์ใช้ทำนายคุณภาพการเชื่อมต่อในแอปพลิเคชัน IoT ได้อย่างไร?
