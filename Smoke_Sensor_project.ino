#include <dht11.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define DHT11_PIN 6
dht11 DHT;
//int DHT11 = 6;
int SmokeSensor = A0;
int Temp;
int Green = 9;
int Yellow = 10;
int Red = 11;
int Buzzer = 12;
 

void setup() {
  // put your setup code here, to run once:
 // pinMode(dht, INPUT);
  pinMode(SmokeSensor, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT);
  lcd.backlight();
  lcd.init();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Initializing....");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
  



}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
  
  int chk = DHT.read(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
 

  if(DHT.temperature <= 26){
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("Normal");
  digitalWrite(Green, HIGH);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, LOW);
  
  }
  
  else if(DHT.temperature > 26 and DHT.temperature <30){
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("Attention..");
  digitalWrite(Yellow, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(100);
  noTone(Buzzer);
  delay(1000);
  }
  
  else if(DHT.temperature >= 30 or sensorValue >250   ){
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("Danger!!!!!!!!");
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(100);
  noTone(Buzzer);
  delay(100);

  } 
  
  else if(sensorValue >250){
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("Danger!!!!!!!!");
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Buzzer, HIGH);
  delay(100);
  noTone(Buzzer);
  delay(100);
  } 
 
}
