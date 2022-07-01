#include <Arduino.h>
#define triggerPin D3
#define echoPin D4
#define buzzer  D2

void setup() {
  Serial.begin (115200);
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(BUILTIN_LED, OUTPUT);
   pinMode(buzzer, OUTPUT);
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
   // Serial.print(jarak);
   // Serial.println(" cm");
   // delay(2000);

   if (jarak <= 2) {
      Serial.print(jarak);
      Serial.println(" cm");
      Serial.println("Buzzer on");
      // digitalWrite(buzzer, LOW);
      delay(2000); 
   }
   else if (jarak >= 10) {
      Serial.print(jarak);
      Serial.println(" cm");
      Serial.println("Buzzer off");
      // digitalWrite(buzzer, HIGH);
      delay(2000);
   }
   else {
      Serial.print(jarak);
   }
   delay(2000);
}