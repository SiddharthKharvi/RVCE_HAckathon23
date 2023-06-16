# RVCE_HAckathon23
RVCE night hackthion

The project consists of one master node which will be contacting the sensor node and updating the data on IoT and a robot will be made which will help in the rescue of people during any disaster.

2) Features
Real-time monitoring: The system utilizes sensors, drones, and satellite imagery to gather real-time data on disasters, enabling continuous monitoring of affected areas.
Rapid decision-making: The system generates accurate alerts and notifications, enabling emergency response teams to make informed decisions quickly.
Super visor and Node based Star Toplolgy

3) Node Discription:
The system uses remote nodes to get sensor data in distance and connected to a master node in a star topology. The data are encrypted with a code such no third party could decode the data. 

The data is received and decoded by gateway controller, data is then analysed by master controller, the data is shown in HMI display, user input can be directed to launch a  rescue operation or the alarm trigger.

Rescue rover is linked by a long range RF module that autonomously activated by master, and manually controlled by the user. The rover scans for any casualty trapped between debris through its sensors. 

4) Communication Protocol
  Address 000001
  I2c between Sesnor and Node
  SPI between Radio and Controller
  UART between HMI and Master Node
  ESP8266 as Gateway Node
  
5) SSID: INTERNET1 PASSWD: PASSWORD

Circuit Pin number of respective codes can be found in program
Happy Programming...>!
Thank You.

