#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
int buttonPin = 8; 
int buttonState = 0; 
boolean timerStarted = false; 
unsigned long startTime; 
unsigned long elapsedTime; 

void setup() {
  lcd.begin(16, 2); 
  lcd.print("Press to start"); 
  pinMode(buttonPin, INPUT); 
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH && !timerStarted) {
    timerStarted = true;
    startTime = millis(); 
    lcd.clear(); 
    lcd.print("Timer started!"); 
  } else if (buttonState == HIGH && timerStarted) {
    timerStarted = false;
    startTime = 0; 
    elapsedTime = 0; 
    lcd.clear(); 
    lcd.print("Timer reset!"); 
  }
  
  if (timerStarted) {
    elapsedTime = millis() - startTime; 
    lcd.setCursor(0, 1); 
    lcd.print("Time: "); 
    printTime(elapsedTime / 1000); 
  }
}

void printTime(unsigned long timeInSeconds) {
  unsigned int hours = timeInSeconds / 3600;
  unsigned int minutes = (timeInSeconds / 60) % 60;
  unsigned int seconds = timeInSeconds % 60;
  lcd.print(hours < 10 ? "0" : "");
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes < 10 ? "0" : "");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds < 10 ? "0" : "");
  lcd.print(seconds);
}