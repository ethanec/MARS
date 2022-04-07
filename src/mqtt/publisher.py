import paho.mqtt.client as mqtt
import datetime 
import time
import serial
import rospy
from std_msgs.msg import String



client = mqtt.Client()


client.username_pw_set("","")


client.connect("broker.hivemq.com", 1883, 60)
port = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=3.0)

pub = rospy.Publisher('chatter', String, queue_size=10)
rospy.init_node('talker', anonymous=True)


while True:
    data=port.read()
    if data=='A':
        dis = []
        hr = []
        dir = port.read()
        for i in range(3):
            dis.append(port.read())
        for i in range(3):
            hr.append(port.read())  
        last = port.read()
        # payload =data + dir + "".join(line) + last
        payload_ros = dir+"".join(dis)
        payload_mqtt ="".join(hr)
        print ("payload_mqtt: "+ payload_mqtt + "  paylaod_ros: " + payload_ros)

        client.publish("Lab506/forLine", payload_mqtt)

        pub.publish(payload_ros)

        time.sleep(1)