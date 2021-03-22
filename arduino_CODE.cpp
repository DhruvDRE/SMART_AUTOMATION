#include <Servo.h>
const int temp=A0;
const int light=A1;
const int fan=6;
const int ledPin=9;
Servo myservo;//fan
int pos =0;
void setup() {
   pinMode(5, INPUT);//pir
   pinMode(4, OUTPUT);//bulb
  pinMode(temp, INPUT);
  pinMode(light, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(ledPin,OUTPUT);
  myservo.attach(6);
}
int lightint(int value){
if (value >=0 && value < 200){
    analogWrite(ledPin, 255);  //Turn led on brightest
	
}
  else if(value >200 && value<400){
    analogWrite(ledPin, 127);  //Turn led on 50%
  }
  else if(value >400 && value<600){
    analogWrite(ledPin, 64); //Turn led on
  }
  else{
  
    analogWrite(ledPin, 0);} 
  
}

int temper(int temp1){
  if(temp1>28){
  for(pos=0;pos<=180;pos+=1){
  myservo.write(pos); // change position of the servo
  delay(5);
  }
  // for closing the gate
  for(pos=180;pos>=0;pos-=1){
  myservo.write(pos); // change position of the servo
  delay(5);
  }
  }}

int inter(int interact){
  if(interact==1){
  digitalWrite(4,HIGH);
  delay(10000);
  digitalWrite(4,LOW);  
  }else{digitalWrite(4,LOW);}
}
void loop() {
  int interact=digitalRead(5);
  int value = analogRead(A1);// light intensity 
  int temp1= map(analogRead(A0),20,358,-40,125);
  lightint(value);
  temper(temp1); 
  inter(interact);
}
 
