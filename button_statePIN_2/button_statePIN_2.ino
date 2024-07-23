#define BUTTON_PIN 2


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);


}

void loop() {
  Serial.println(digitalRead(BUTTON_PIN));
  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("button is pressed");
  } else {
    Serial.println("button is NOT pressed");
  }
  delay(100);

}
