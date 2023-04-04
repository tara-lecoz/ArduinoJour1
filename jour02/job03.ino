byte smiley[8] = {
 B00000,
 B01010,
 B01010,
 B00000,
 B10001,
 B10001,
 B01110,
 B00000
};

#include <LiquidCrystal.h>

// Définition des broches auxquelles est connecté l'écran LCD
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialise l'écran LCD avec 16 colonnes et 2 lignes
  lcd.begin(16, 2);

  // Définition du caractère personnalisé
  lcd.createChar(0, smiley);
}

void loop() {
  // Affichage du smiley sur l'écran LCD à la position 0,0
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
}