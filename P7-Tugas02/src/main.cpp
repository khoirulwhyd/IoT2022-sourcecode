#include <Arduino.h>
#define triggerPin D5
#define echoPin D6
#define RED_LED D0
#define GREEN_LED D1
#define BLUE_LED D2


int distance;

void setup() {
   Serial.begin (115200);
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(RED_LED,OUTPUT);
   pinMode(GREEN_LED,OUTPUT);
   pinMode(BLUE_LED,OUTPUT);
}

void loop() {
  long duration, jarak;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = duration * 0.034 / 2;

  if (jarak==1)
  {
    Serial.print(jarak);
    Serial.println(" cm");
    Serial.println("LED MENYALA BIRU");
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
   }
   else if(jarak==2){
     Serial.print(jarak);
     Serial.println(" cm");
     Serial.println("LED MENYALA HIJAU");
     digitalWrite(BLUE_LED,LOW);
     digitalWrite(RED_LED,LOW);
     digitalWrite(GREEN_LED,HIGH);
   }
   else if(jarak==3){
     Serial.print(jarak);
     Serial.println(" cm");
     Serial.println("LED MENYALA MERAH");
     digitalWrite(BLUE_LED,LOW);
     digitalWrite(RED_LED,HIGH);
     digitalWrite(GREEN_LED,LOW);
   }
   else{
     Serial.print(jarak);
     Serial.println(" cm");
     Serial.println("LED MENYALA SEMUA BERGANTIAN SELAMA 1 DETIK");
     digitalWrite(BLUE_LED,LOW);
     digitalWrite(RED_LED,HIGH);
     digitalWrite(GREEN_LED,LOW);
     delay(400);
     digitalWrite(BLUE_LED,LOW);
     digitalWrite(RED_LED,LOW);
     digitalWrite(GREEN_LED,HIGH);
     delay(400);
     digitalWrite(BLUE_LED,HIGH);
     digitalWrite(RED_LED,LOW);
     digitalWrite(GREEN_LED,LOW);
     delay(400);
   }
   delay(2000);
}