#include <SoftwareSerial.h>

const int motorPin = 9;     //��� ���� : ���Ϳ� ����� �� ��ȣ ����
SoftwareSerial mySerial(2, 3); //��������� Tx, Rx���� 2�� 3�������� ����
bool flag;
char signal;

void setup() {
  // �ø��� ����� �ӵ��� 9600���� ����
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(motorPin, OUTPUT);      //9������ ��¿����� ����
  
  while (!Serial) {
    ; //�ø�������� ������� �ʾҴٸ� �ڵ� ������ ���߰� ���� �ݺ�
  }
  Serial.println("connected");

  //��������� �Ƶ��̳��� ��żӵ��� 9600���� ����
  mySerial.begin(9600);
}

void loop() { //�ڵ带 ���ѹݺ��մϴ�.
  
  if (mySerial.available()) { //����������� �Ѿ�� �����Ͱ� �ִٸ�
    signal = mySerial.read();
    Serial.println(signal); //�ø������Ϳ� �����͸� ���
    if(signal == '0')
      flag = false;
    else{
      flag = true;
    }
    spiningMotor(flag);
  }
  else{
    //Serial.write("waiting\n");
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

