#define BUTTON_PIN 2
#define LED_PIN 11

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);  


}

void loop() {
  Serial.println(digitalRead(BUTTON_PIN));
  if (digitalRead(BUTTON_PIN) == HIGH) {  
    Serial.println("button is pressed");
    digitalWrite(LED_PIN, HIGH);
  } else {  
    Serial.println("button is NOT pressed");
    digitalWrite(LED_PIN, LOW);
  }
  //delay(100);

}
