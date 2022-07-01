#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7
#define RED_LED D0
#define GREEN_LED D1
#define BLUE_LED D2
#define sensorLDR A0

    byte temperature = 0;
    byte humidity = 0;
    int nilaiSensor;

    SimpleDHT11 dht11(D7); //instan sensor dht11

    void KelembabanSuhuCahaya()
    {
        int err = SimpleDHTErrSuccess;

        if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
        {
            Serial.print("Pembacaan DHT11 gagal, err=");
            Serial.println(err);
            delay(1000);
            return;
        }

        nilaiSensor = analogRead(sensorLDR);
        Serial.print("Nilai Sensor: ");
        Serial.println(nilaiSensor);
        Serial.print("Suhu: ");
        Serial.print((int)temperature);

        Serial.print(" *C, ");

        if (temperature<=25 || nilaiSensor>=1000){
          Serial.println("Suhu dingin Cahaya Redup");
          Serial.println("LED MENYALA BIRU");
          digitalWrite(GREEN_LED,LOW);
          digitalWrite(BLUE_LED,HIGH);
          digitalWrite(RED_LED,LOW);
        }
        else if (temperature>=30 || nilaiSensor<=800){
          Serial.println("Suhu Panas Cahaya Terang");
          Serial.println("LED MENYALA MERAH");
          digitalWrite(GREEN_LED,LOW);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(RED_LED,HIGH);
        }
        delay(1500);
    }

    void setup()
    {
      Serial.begin(115200);
      Serial.println("Simple DHT");
      pinMode(GREEN_LED,OUTPUT);
      pinMode(BLUE_LED,OUTPUT);
      pinMode(RED_LED,OUTPUT);
      delay(1000);
    }

    void loop()
    {
      KelembabanSuhuCahaya();
    }