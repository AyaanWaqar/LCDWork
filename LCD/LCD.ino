#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay=3;
int relay2=4;
//int relay3=13;
//int relay4=6;
int sensor3 = A1;
int sensor = A0;
int sensor2 = A2;
const int soundpin=A3;

void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
pinMode(relay2,OUTPUT);
//pinMode(relay3,OUTPUT);
//pinMode(relay4,OUTPUT);
pinMode(sensor, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(soundpin,INPUT);
Serial.begin(9600);
lcd.begin();
lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
 int sensorval = analogRead(sensor);
 int sensorval2 = analogRead(sensor2);
 int sensorval3 = analogRead(sensor3);
 int soundpin = analogRead(soundpin);
 Serial.println(sensorval3);
  
 if (sensorval >500 || sensorval2 >500 || sensorval3 >500 ){
  digitalWrite(relay, LOW); 
  digitalWrite(relay2, LOW); 
 // digitalWrite(relay3, LOW); 
 // digitalWrite(relay4, HIGH); 
  lcd.clear();
  lcd.print("Lights ON");
        //delay(2000);
}
 else {
  //delay(1000);
  digitalWrite(relay, HIGH); 
  digitalWrite(relay2, HIGH); 
  //digitalWrite(relay3, LOW); 
  //digitalWrite(relay4, LOW); 
  lcd.clear();
  lcd.print("No Lights ");

  }
}



  
  
  
