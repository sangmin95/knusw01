#include "CO2Sensor.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
CO2Sensor co2Sensor(A0, 0.99, 100);

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("=== Initialized ===");

  co2Sensor.calibrate();

}
void loop() {

  int val = co2Sensor.read();

  Serial.print("CO2 value: ");

  Serial.println(val);
  if(mySerial.available() > 0){
    Serial.println("mySerial available()");
    if(val > 600){
    Serial.println("turn on");
    mySerial.write("1");
    }
  }
  
  delay(500);

}
