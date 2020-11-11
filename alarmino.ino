#include "Ultrasonic.h" 

const int echoPin = 7; 
const int trigPin = 6; 
int buzzerPin = 8;
Ultrasonic ultrasonic(trigPin,echoPin); 
int s;  
 
void setup(){
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  Serial.begin(9600); 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  }
void loop(){
  
  hcsr04(); 
 
  
}

void hcsr04(){
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 
    
    s = (ultrasonic.Ranging(CM)); 
    delay(300); 
    if (s >= 100) {
      digitalWrite (12, 0);
      digitalWrite (13, 0);
      digitalWrite (11, 1);
    }
    else{
    if (s < 100 && s >= 60){
      digitalWrite (11, 0);
      digitalWrite (13,0);
      digitalWrite (12, 1);
      }
    else{
      digitalWrite (11, 0);
      digitalWrite (12, 0);
      digitalWrite(13, 1);
      tone(buzzerPin, 700);
      
      
      }
    }
    delay(100);
 }
