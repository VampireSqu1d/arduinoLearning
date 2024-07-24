#define POTENCIOMETER_PIN A2
#define LED_PIN 11
void setup() {
  pinMode(LED_PIN, OUTPUT); 

}

void loop() {
  int potenciometer_value = analogRead(POTENCIOMETER_PIN);
  int LED_brightness = potenciometer_value * 0.25;

  analogWrite(LED_PIN, LED_brightness);

  delay(50);
}
