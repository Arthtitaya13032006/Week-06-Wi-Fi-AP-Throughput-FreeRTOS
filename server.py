import socket

HOST = '0.0.0.0'  # เปิดรับการเชื่อมต่อจากทุก IP ในเครือข่าย
PORT = 8080       # พอร์ตต้องตรงกับที่ตั้งไว้ใน ESP32

print(f"Starting Python TCP Server on port {PORT}...")
print("Waiting for ESP32 to connect...")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    
    while True:
        conn, addr = s.accept()
        with conn:
            print(f"\n[+] Connected by ESP32 at {addr}")
            total_bytes = 0
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                total_bytes += len(data)
            print(f"[-] Connection closed. Total data received: {total_bytes} bytes.")