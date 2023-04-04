#define pinX    A2
#define pinY    A1
#define swPin    9
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
}

void loop() {

  int X = analogRead(pinX);
  int Y = analogRead(pinY);

  if(490 < X < 530 && 490 < Y < 530)
  {
    if(X < 490){
      lcd.setCursor(0, 0);
      lcd.print("Gauche");
    } else if (X > 530) {
      lcd.setCursor(0, 0);
      lcd.print("Droite");
    }

    if(Y < 490){
      lcd.setCursor(0, 1);
      lcd.print("Haut");      
    } else if (Y > 530){
      lcd.setCursor(0,1);
      lcd.print("Bas");      
    }
  }

  delay(300);
  lcd.clear();
}