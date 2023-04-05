#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Initialisation de l'afficheur LCD

int progress = 0; // Initialisation du pourcentage de progression à 0
int a = 0;
byte rectangle[] = { // Création du caractère personnalisé représentant un rectangle plein
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

void setup() {
  lcd.begin(16, 2); // Activation de l'afficheur LCD
  lcd.createChar(1, rectangle); // Déclaration du caractère personnalisé
}

void loop() {
  lcd.setCursor(0, 0); // Positionnement du curseur sur la première ligne
  lcd.print("Progression: "); // Affichage du texte "Progression: "
  lcd.setCursor(13, 0); // Positionnement du curseur à la fin du texte
  lcd.print(progress); // Affichage du pourcentage de progression
  lcd.print("%"); // Affichage du symbole %

  lcd.setCursor(0, 1); // Positionnement du curseur sur la deuxième ligne

  int filled_blocks = map(progress, 0, 100, 0, 17); // Calcul du nombre de blocs remplis à afficher
  for (int i = 0; i < filled_blocks; i++) { // Boucle pour afficher les blocs remplis
    lcd.write(byte(1)); // Affichage du caractère personnalisé
  }

  for (int i = filled_blocks; i < (100/16); i++) { // Boucle pour afficher les blocs vides
    lcd.print(" "); // Affichage d'un espace pour représenter un bloc vide
  }

  delay(3000); // Attente de 3 secondes avant de continuer

  a+= 1;
  progress = a * 100 / 16 ; // Incrémentation du pourcentage de progression de 10%
  if (progress > 100) { // Si le pourcentage de progression dépasse 100
    lcd.clear();
    a = 0;
    progress = 0; // Réinitialisation du pourcentage de progression
  }
}