from ultralytics import YOLO
import serial
import time

model = YOLO("best_model.pt")
results = model.predict(source=0, show=True, save=True, stream=True)

arduino = serial.Serial('COM7', 9600, timeout=1)  # Windows
time.sleep(2)  
print("Connected to Arduino!")
arduino.write(b'1')

# for r in results:
#     if len(r.boxes) > 0:  # Fire detected (at least one bounding box)
#         arduino.write(b'1')  # Send "1" to Arduino
#         print("Fire detected! 🔥")
#     else:
#         arduino.write(b'0')  # Send "0" to Arduino
#         print("No fire.")
#     time.sleep(0.1)  # Small delay to avoid flooding serial