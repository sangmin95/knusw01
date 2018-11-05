#include <SoftwareSerial.h>

const int motorPin = 9;     //상수 선언 : 모터와 연결된 핀 번호 저장
SoftwareSerial mySerial(2, 3); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정

void setup() {
  // 시리얼 통신의 속도를 9600으로 설정
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);      //9번핀을 출력용으로 설정
  
  while (!Serial) {
    ; //시리얼통신이 연결되지 않았다면 코드 실행을 멈추고 무한 반복
  }


  Serial.println("Hello World!");

  //블루투스와 아두이노의 통신속도를 9600으로 설정
  mySerial.begin(9600);
}

void loop() { //코드를 무한반복합니다.
  spiningMotor();              //모터 작동시키는 함수 호출
  if (mySerial.available()) { //블루투스에서 넘어온 데이터가 있다면
    Serial.write(mySerial.read()); //시리얼모니터에 데이터를 출력
    spiningMotor();
  }
  if (Serial.available()) {    //시리얼모니터에 입력된 데이터가 있다면
    mySerial.write(Serial.read());  //블루투스를 통해 입력된 데이터 전달
    spiningMotor();
  }
}

void spiningMotor(bool flag)
{
    if(flag){
     analogWrite(motorPin, 200); 
     Serial.println("on");
    }
    else{
     analogWrite(motorPin, 0); 
     Serial.println("off"); 
   }
 }
