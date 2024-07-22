
#define LED_PIN 12

void setup() {
  //Serial.begin(9600);
  //Serial.println("Hello world!");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  //Serial.println("LED On");
  delay(2000);
  digitalWrite(LED_PIN, LOW);
  //Serial.println("LED Off");
  delay(1000);
}
