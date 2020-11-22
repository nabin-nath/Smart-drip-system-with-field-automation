#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int water_pin = 7;
float soilraw = 0.0; 
float soilmoist= 0.0;
int sen_pin = A0; 
int average; int val;
int readval=0;
int serialA=0;
void setup (){
  Serial.begin(9600); 
  pinMode(sen_pin,INPUT);
  pinMode(1,OUTPUT);  
  pinMode(7,OUTPUT);
   lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Motor On!");
   
  } 
  void loop(){
    
   
   
      soilraw = analogRead(sen_pin);
      soilmoist=map(soilraw,1024,0,0,100);
      for (int i=0; i<160; i++)
      { average = average + soilmoist; }
      val = average/160;
      average = 0;
      delay(1200);
      if(val<10)
      { digitalWrite(water_pin,HIGH);
       lcd.setCursor(3,0);
       lcd.print("Motor On!"); 
      }
      if(val>20)
      { digitalWrite(water_pin,LOW);
       lcd.setCursor(3,0);
       lcd.print("Motor off!");} 
}
