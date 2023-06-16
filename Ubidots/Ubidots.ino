/****************************************
  Include Libraries
****************************************/

#include "Ubidots.h"

/****************************************
  Define Instances and Constants
****************************************/

const char* UBIDOTS_TOKEN = "BBFF-wl093FoDvxxYBtqoeFpLIECPB7duu7";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Bbnl 2.4 G";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "22222222";      // Put here your Wi-Fi password

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
  Auxiliar Functions
****************************************/

// Put here your auxiliar functions

/****************************************
  Main Functions
****************************************/

void setup() {

  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug  messages
}

void loop() {

  int temprature = 30;
  int Vibration = 10;
  int Gas = 10;
  int Alarms = 0;
  int WaterLevel = 10;
  int FlameLevel = 0;


  ubidots.add("Ambient Temprature", temprature);// Change for your variable name
  ubidots.add("Earthquake Magnitude", Vibration );
  ubidots.add("Gas Level", Gas);
  ubidots.add("Alarm Status", Alarms);
  ubidots.add("Water Level", WaterLevel);
  ubidots.add("Moisture", WaterLevel);
  ubidots.add("Flame level", FlameLevel);
  ubidots.add("Oil Contamination", FlameLevel);
  ubidots.add("Macine1 Status", FlameLevel);
  ubidots.add("Macine2 Status", FlameLevel);
  ubidots.add("Macine1 Temprature", temprature);
  ubidots.add("Macine2 Temprature", temprature);




  bool bufferSent = false;
  bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
  delay(5000);
}
