#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
int buttonPin = 8; 
int buttonState = 0; 
boolean timerStarted = false; 
unsigned long startTime; 
unsigned long elapsedTime; 
unsigned long pauseTime = 0; 

void setup() {
  lcd.begin(16, 2); 
  lcd.print("Press to start"); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH && !timerStarted) {
    timerStarted = true;
    if (pauseTime == 0) {
      startTime = millis();
    } else {
      startTime = millis() - pauseTime; 
      pauseTime = 0;
    }
    lcd.clear(); 
    lcd.print("Jerome et Lucas"); 
  } else if (buttonState == HIGH && timerStarted) {
    timerStarted = false;
    pauseTime = millis() - startTime; 
    lcd.clear(); 
    lcd.print("Timer paused!"); 
  }
  
  if (timerStarted) {
    elapsedTime = millis() - startTime;
    lcd.setCursor(0, 1); 
    lcd.print("Time: "); 
    lcd.print(elapsedTime / 1000); 
    lcd.print("s");
  }
}