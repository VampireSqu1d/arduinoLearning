#define RED_LED 11
#define YELLOW_LED 10
#define GREEN_LED 9

#define BUTTON_PIN 2

int light_delay = 1000;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if(digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(RED_LED, HIGH);
    delay(light_delay);
    digitalWrite(RED_LED, LOW);
  }
  
  if(digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(GREEN_LED, HIGH);
    delay(light_delay);
    digitalWrite(GREEN_LED, LOW);
  }

  if(digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(YELLOW_LED, HIGH);
    delay(light_delay);
    digitalWrite(YELLOW_LED, LOW);
  }
}
