/*
 제목    : I2C LCD에 문자 출력하기
 내용   : I2C LCD에 원하는 문자를 표시해 봅니다.  
 */

// LCD를 쉽게 제어하기 위한 라이브러리를 추가합니다.
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 0x3F I2C 주소를 가지고 있는 16x2 LCD객체를 생성합니다.(I2C 주소는 LCD에 맞게 수정해야 합니다.)
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "CO2Sensor.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
CO2Sensor co2Sensor(A0, 0.99, 100);

void setup() {
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();

  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("=== Initialized ===");

  co2Sensor.calibrate();

}
void loop() {

  int val = co2Sensor.read();
  lcd.setCursor(0,0);
    // 아래의 문장을 출력합니다.
   lcd.print("CO2 :" );
   lcd.print(val);
   if(val % 1000 > 0){
    lcd.print("  ppm"); 
   }
   else if(val % 100 > 0){
    lcd.print("   ppm");
   }
   else if(val % 10 > 0){
    lcd.print("    ppm");
   }
   else{
    lcd.print("ppm");
   }
   

 
  if(val > 400){
    Serial.println("turn on");
    mySerial.write("1");
   
   
   lcd.setCursor(0,1);
    // 아래의 문장을 출력합니다.
   lcd.print("ON ");
   
   
  }
  else{
    mySerial.write("0");
       lcd.setCursor(0,1);
    // 아래의 문장을 출력합니다.
   lcd.print("OFF");
  
  } 
//  delay(500);
}
