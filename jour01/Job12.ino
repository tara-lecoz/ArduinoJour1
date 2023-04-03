#define LED_PIN 11
#define LED_PIN2 10
#define POTENTIOMETER_PIN A1
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}
void loop()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = potentiometerValue / 4;
  analogWrite(LED_PIN, brightness);
  analogWrite(LED_PIN2, brightness*(-1));
}