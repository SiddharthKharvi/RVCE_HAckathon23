#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>


Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Adafruit_MPU6050 mpu;
RF24 radio(7, 8); // CE, CSN

#define Buzzer 6
const byte address[6] = "00001";
String text;

void setup() {
  mlx.begin();

  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, HIGH);
  delay(200);
  digitalWrite(Buzzer, LOW);
  delay(200);
  digitalWrite(Buzzer, HIGH);
  delay(100);
  digitalWrite(Buzzer, LOW);
}

void loop() {
  //const char text[] = "Hello World";
  //radio.write(&text, sizeof(text));
  //delay(1000);
  Accelrometer();
  GasSensor();
  IRTempSens();

}

void Accelrometer() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.println("AX" + String(a.acceleration.x) + "Y" + String(a.acceleration.y) + "Z" + a.acceleration.z);
  text = "AX" + String(a.acceleration.x) + "Y" + String(a.acceleration.y) + "Z" + a.acceleration.z;
  radio.write(&text, sizeof(text));

}

void GasSensor() {
  int Gas = map(analogRead(A6), 250, 600, 0, 100);
  Serial.println("G" + String(Gas));

  if (Gas >= 50) {
    digitalWrite(Buzzer, HIGH);
    Serial.println("A1");

  }
  text = "A";
  radio.write(&text, sizeof(text));
  radio.write(Gas, sizeof(Gas));

}

void IRTempSens() {
  float temp = mlx.readObjectTempC();
  Serial.println("T" + String(temp));

  text = "T" + String(temp);
  radio.write(&text, sizeof(text));

  if (temp >= 35) {
    digitalWrite(Buzzer, HIGH);
    Serial.println("A1");

    text = "A1";
    radio.write(&text, sizeof(text));

  }


}
