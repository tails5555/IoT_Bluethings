#include<Servo.h> //Servo 라이브러리를 추가
#include <SoftwareSerial.h>

int blueTx=6;   //Tx (보내는핀 설정)at
int blueRx=7;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

int buttonState =0;
int button =3;
int count=0;

int state = LOW;      // LED 상태
int reading;          // 터치센서 상태
int previous = LOW;   // 터치센서 이전 상태


Servo servo;      //Servo 클래스로 servo객체 생성
int value = 0;    // 각도를 조절할 변수 value

int onAngle=80;
int offAngle=170;

void setup() {
  
  pinMode(button,INPUT);
  servo.attach(2);     //맴버함수인 attach : 핀 설정
  Serial.begin(9600); //시리얼 모니터 사용 고고
  mySerial.begin(9600); //블루투스 시리얼
}

void loop() {

  
       
    while(mySerial.available())  //mySerial에 전송된 값이 있으면
      {
    
        char myChar = (char)mySerial.read();  //mySerial int 값을 char 형식으로 변환
        Serial.write(myChar);
        delay(5);           //수신 문자열 끊김 방지
    
        if(myChar=='1')
            servo.write(onAngle); 
        
        
        else if(myChar=='2')
            servo.write(offAngle); 
    
      } 

  
    buttonState = digitalRead(button);


   if(buttonState==HIGH){

    
      count=count+1;

           if(count==1){
              servo.write(onAngle); 
           }
        
           else if(count==2){
              servo.write(offAngle); 
              count=0;
           }
   }

  

  delay(700);


}
