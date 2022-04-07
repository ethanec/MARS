#include "ros/ros.h" // 加入ROS公用程序
#include "std_msgs/String.h" // 所要publish的message header，在此是std_msgs package底下的String.msg
#include <sstream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

int serial_port = open("/dev/ttyUSB0", O_RDWR);
struct termios tty;


int main(int argc, char **argv)
{
ros::init(argc, argv, "talker"); //一開始必須先初始化，指定node名稱為talker

/* 該node與ROS系統通訊的存取點(handle)，建構子會初始化該node，
當離開此scope，解構子會關閉該node */
ros::NodeHandle n;

/* advertise()會將建立
2ltopic的資訊告訴master node，回傳一個Publisher物件(在此為chatter_pub)
之後可使用該物件的 publish() 方法進行publish
而預計publish的message為std_msgs package的String.msg (std::msgs::String)
指定的topic名稱為chatter
1000指的是message queue，若publish太快，超過1000個message，新publish的message會被捨棄
*/
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);


ros::Rate loop_rate(10); // 10Hz

int count = 0;
while (ros::ok())
{
char read_buf[256];
//memset(&read_buf, '\0', sizeof(read_buf);
int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
if (num_bytes < 0) {
printf("Error reading: %s", strerror(errno));
}
else if(num_bytes == 9){
printf("Read %i bytes. Received message: %s", num_bytes, read_buf);

std_msgs::String msg; // 建立暫存的message，先將資料存入此變數，再進行publish

std::stringstream ss;
ss << read_buf << count;
msg.data = ss.str(); // 寫入msg message中的data欄位

ROS_INFO("%s", msg.data.c_str());

//使用前面建立的Publisher物件chatter_pub的publish()方法，將暫存的msg送出 (publish)
chatter_pub.publish(msg);

ros::spinOnce(); // 呼叫一次 callback function，在subscriber才有用

loop_rate.sleep(); // 等待loop_rate所設定的時間

++count;
}
}
return 0;
}