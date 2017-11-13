from time import sleep
import serial
ser = serial.Serial('/dev/ttyACM2', 9600) # Establish the connection on a specific port
#counter = 32 # Below 32 everything in ASCII is gibberish
while True:
 #    ser.write(str(chr(counter))) # Convert the decimal number to ASCII then send it to the Arduino
     print(ser.readline().rstrip()) # Read the newest output from the Arduino
     sleep(.1) # Delay for one tenth of a second

