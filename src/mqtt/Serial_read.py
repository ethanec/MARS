import serial
import time


# def readlineCR(port):
#     rv = ""
#     while True:
#         ch = port.read()
#         rv += ch
#         if ch=='\r' or ch=='':
#             return rv

port = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=3.0)


while True:
#port.write("\r\nSay something:")
#rcv = readlineCR(port)
#port.write("\r\nAYou sent:" + repr(rcv) +"B")
    data=port.read()
    if data=='A':
        line = []
        dir = port.read()
        for i in range(6):
            line.append(port.read()) 
        last = port.read()
        print(data + dir + "".join(line) + last)