import serial
import time
import re

arduinoData = serial.Serial('COM4', 115200)
time.sleep(1)

while (1==1):
    while (arduinoData.inWaiting() == 0):
        pass
    dataPacket = arduinoData.readline()

    dataPacket = str(dataPacket,'utf-8')
    splitPacket = dataPacket.split('\t')

    Pitch = float(splitPacket[3].strip())
    Roll = float(splitPacket[4].strip())
    Yaw = float(splitPacket[5].strip())
    
    print("Pitch", Pitch, "Roll", Roll, "Yaw", Yaw)
