import serial 
from time import sleep 

arduino = serial.Serial('/dev/ttyACM0', 9600) # object creation
sleep(1.55)
while True: 
arduino.write(b" ") 
# write position to serial port
horpos = str(arduino.read(6)) 
# read serial port for arduino echo
verpos = str(arduino.read(6))
print(horpos,",",verpos) # print arduino echo to consoles