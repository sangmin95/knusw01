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
<<<<<<< HEAD
  if(val > 400){
    Serial.println("turn on");
    mySerial.write("1");
   
  }
  else
    mySerial.write("0");
    
//  delay(500);
=======
  if(mySerial.available() > 0){
    Serial.println("mySerial available()");
    if(val > 600){
    Serial.println("turn on");
    mySerial.write("1");
    }
  }
  
  delay(500);

>>>>>>> b167d58bc94cfd29986398c0f361c158c561720c
}
