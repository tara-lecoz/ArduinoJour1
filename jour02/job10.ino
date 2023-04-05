#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Initialisation de l'afficheur LCD


const int trigPin =9;
const int echoPin =8;

// Variables utiles
long duree; // Durée de l'echo
int distance;

void setup() {
    lcd.begin(16, 2);
    pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE
    pinMode(echoPin, INPUT); // Configuration du port de l'Echo comme une ENTREE
}
void loop() {
    // Émission d'un signal de durée 10 microsecondes
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Écoute de l'écho
    duree = pulseIn(echoPin, HIGH);
    // Calcul de la distance
    distance = duree*0.034/2;
    // Affichage de la distance dans le Moniteur Série
    lcd.print("Distance en cm :") ;
    lcd.setCursor(0,1);
    lcd.print(distance) ;
    delay(500); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
    lcd.clear();
}