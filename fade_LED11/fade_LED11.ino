#define LED_PIN 11
#define MIN_VAL 0
#define MAX_VAL 180
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = MIN_VAL; i <= MAX_VAL; i++) {
    analogWrite(LED_PIN, i);
    delay(10);
  }

  for(int i = MAX_VAL; i > MIN_VAL; i--) {
    analogWrite(LED_PIN, i);
    delay(10);
  }
}
