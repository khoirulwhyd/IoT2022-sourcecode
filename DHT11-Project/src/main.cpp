  #include <Arduino.h>
  #include <SimpleDHT.h>
  #include <LiquidCrystal_I2C.h>

    #define pinDHT 7 // SD3 pin signal sensor DHT
    #define RED_LED D3
    #define GREEN_LED D6
    #define BLUE_LED  D5

    byte temperature = 0;
    byte humidity = 0;

    SimpleDHT11 dht11(D7); //instan sensor dht11
    LiquidCrystal_I2C lcd(0x27, 16, 2);

    void setup()
    {
        Serial.begin(115200);
        pinMode(GREEN_LED,OUTPUT);
        pinMode(BLUE_LED,OUTPUT);
        pinMode(RED_LED,OUTPUT);
        lcd.init(); // initialize the lcd
        lcd.backlight();
        lcd.clear();
        lcd.home();
        delay(1000);
    }

    void loop()
    {
        int err = SimpleDHTErrSuccess;

        if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
        {
            Serial.print("Pembacaan DHT11 gagal, err=");
            Serial.println(err);
            delay(1000);
            return;
        }
        
        Serial.print("Sample OK: ");
        Serial.print((int)temperature);
        Serial.print(" *C, ");

        int fahrenheit = (9.0/5)*temperature + 32 ;
        Serial.print((int)fahrenheit);
        Serial.print(" *F ");

        lcd.setCursor(0, 0);
        lcd.print("T:");
        lcd.print(temperature);
        lcd.print("C");
        lcd.print("|");
        lcd.print(fahrenheit);
        lcd.print("F");

        //menambahkan LED RGB
        if(temperature <= 20){
          Serial.println(" Suhu Dingin ");
          Serial.println(" Led Menyala Hijau ");
          digitalWrite(GREEN_LED,HIGH);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(RED_LED,LOW);
          delay(200);
          digitalWrite(GREEN_LED,LOW);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(RED_LED,LOW);
          delay(200);
        } else if(temperature>21 && temperature<=29){
          Serial.println(" Suhu Normal ");
          Serial.println(" Led Menyala Biru ");
          digitalWrite(BLUE_LED,HIGH);
          digitalWrite(GREEN_LED,LOW);
          digitalWrite(RED_LED,LOW);
          delay(200);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(GREEN_LED,LOW);
          digitalWrite(RED_LED,LOW);
          delay(200);
        } else{
          Serial.println(" Suhu Panas ");
          Serial.println(" Led Menyala Merah ");
          digitalWrite(RED_LED,HIGH);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(GREEN_LED,LOW);
          delay(200);
          digitalWrite(RED_LED,LOW);
          digitalWrite(BLUE_LED,LOW);
          digitalWrite(GREEN_LED,LOW);
          delay(200);
        }
        delay(1500);
    }