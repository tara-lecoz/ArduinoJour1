#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int seconde;
int minute;
int heure;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  seconde++;
  if(seconde == 60)
  {
    seconde = 0;
    minute++;
  }
  if(minute == 60)
  {
    minute = 0;
    heure++;
  }
  if(heure >= 24)
  {
    heure = 0;
  }
  
  if(heure < 10)
  {
    lcd.print("0");
    lcd.print(heure);
    lcd.print(":");
  } else{
    lcd.print(heure);
    lcd.print(":");
  }
  
  if(minute < 10)
  {
    lcd.print("0");
    lcd.print(minute);
    lcd.print(":");
  } else{
    lcd.print(minute);
    lcd.print(":");
  }

  if(seconde < 10)
  {
    lcd.print("0");
    lcd.print(seconde);
  } else{
    lcd.print(seconde);
  }

  delay(1000);
  lcd.clear();
}