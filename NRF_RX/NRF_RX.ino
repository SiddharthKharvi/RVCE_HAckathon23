#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Ubidots.h"

const char* UBIDOTS_TOKEN = "BBFF-wl093FoDvxxYBtqoeFpLIECPB7duu7";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Bbnl 2.4 G";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "22222222";

RF24 radio(2, 4); // CE, CSN
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

const byte address[6] = "00001";
int i = 0;
void setup() {
  Serial.begin(9600);

  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
//    if (text[0] == 'A') {
//      Serial.println("Alert");
//      ubidots.add("Alert", i);
//      bool bufferSent = false;
//      bufferSent = ubidots.send();
//      if (bufferSent) {
//        // Do something if values were sent properly
//        Serial.println("Values sent by the device");
//      }
//    }
  }

}
