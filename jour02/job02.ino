#include <LiquidCrystal.h>

// Initialise l'écran LCD avec les broches appropriées
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const float REFERENCE_VOLTAGE = 5.0; // La tension de référence est de 5 volts

void setup() {
  lcd.begin(16, 2); // Initialise l'écran LCD avec 16 colonnes et 2 lignes
}

void loop() {
  // Lecture de la valeur de tension sur l'entrée analogique A0
  int valeurAnalogique = analogRead(A0);

  // Conversion de la valeur analogique en tension
  float tension = (valeurAnalogique / 1023.0) * REFERENCE_VOLTAGE;

  // Affichage de la valeur de tension sur l'écran LCD à la position 0,0
  lcd.setCursor(0, 0);
  lcd.print("Tension : ");
  lcd.print(String(tension, 2)); // Affiche la tension avec 2 décimales
  lcd.print(" V");
}