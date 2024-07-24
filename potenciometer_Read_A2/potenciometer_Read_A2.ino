#define POTENCIOMETER_PIN A2
void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(POTENCIOMETER_PIN));
  delay(100);

}
