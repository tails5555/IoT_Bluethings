#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueTx=4;   //Tx (보내는핀 설정)at
int blueRx=5;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열
int relay = 8; //릴레이에 5V 신호를 보낼 핀설정
int buttonState =0;
int button =3;
int count=0;

void setup() {
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
  pinMode(13, OUTPUT);  //Pin 13을 OUTPUT으로 설정 (LED ON/OFF)
  pinMode(button,INPUT);
  pinMode(relay, OUTPUT); // relay를 output으로 설정한다
}
void loop(){
  if(count==0){
    digitalWrite(relay, HIGH);
    digitalWrite(13, LOW);
  }
  while(mySerial.available()){ //mySerial 값이 있으면 
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }
  if(!myString.equals("")){  //myString 값이 있다면
    Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
    if(myString[0]=='1')  //myString 값이 'on' 이라면
    {
      digitalWrite(13, HIGH); //LED ON
      digitalWrite (relay, LOW); // 릴레이 OFF
    } else {
      digitalWrite(13, LOW);  //LED OFF
      digitalWrite (relay, HIGH); // 릴레이 ON
    }
    count++;
    myString="";  //myString 변수값 초기화
  }
  buttonState = digitalRead(button);
  if(buttonState==HIGH){
    count=count+1;

    if(count%2==1){
       digitalWrite(13, HIGH); //LED ON 
       digitalWrite (relay, LOW); // 릴레이 OFF
    }

    else if(count%2==0 && count!=0){
       digitalWrite(13, LOW);  //LED OFF
       digitalWrite (relay, HIGH); // 릴레이 ON
    }
  }
  delay(700);
}

