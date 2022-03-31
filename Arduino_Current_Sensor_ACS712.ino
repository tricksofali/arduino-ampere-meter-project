#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
const int currentPin = A0;
int sensitivity = 100;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
 
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Current Sensor ");
  lcd.setCursor(0,1);
  lcd.print("  TRICS OF ALI  ");
  delay(2000);
}
 
void loop()
{
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  
  Serial.print("Raw Sensor Value = " );
  Serial.print(adcValue);
 

 
  Serial.print("\t Current = ");
  Serial.println(currentValue,3);
 
  lcd.setCursor(0,0);
  lcd.print("Current =       ");
  lcd.setCursor(10,0);
  lcd.print(currentValue,2);
  lcd.setCursor(14,0);
  lcd.print("A");
  delay(2500);
}
