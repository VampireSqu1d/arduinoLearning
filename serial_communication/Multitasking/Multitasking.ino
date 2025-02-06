#define LED_PIN_1 12
#define LED_PIN_2 11
#define LED_PIN_3 10

#define BUTTON_PIN 2
#define POTENCIOMETER_PIN A2


unsigned long previousTimeLED1Blink = millis();
unsigned long timeIntervalLED1Blink = 480;
int LED1State = LOW;

unsigned long previousTimeLED2Blink = millis();
unsigned long timeIntervalLED2Blink = 5000;
int LED2State = LOW;


void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  unsigned long timeNow = millis();

  // Action 1
  if (timeNow -previousTimeLED1Blink > timeIntervalLED1Blink ) {
    if(LED1State == LOW) {
      LED1State = HIGH;
    } else {
      LED1State = LOW;
    }
    digitalWrite( LED_PIN_1, LED1State);

    previousTimeLED1Blink += timeIntervalLED1Blink;
  }
  // Action 2
  if (timeNow -previousTimeLED2Blink > timeIntervalLED2Blink ) {
    if(LED2State == LOW) {
      LED2State = HIGH;
    } else {
      LED2State = LOW;
    }
    digitalWrite( LED_PIN_2, LED2State);

    previousTimeLED2Blink += timeIntervalLED2Blink;
  }

  // Action 3
  int potenciometerValue = analogRead(POTENCIOMETER_PIN);
  int intensity = potenciometerValue * 0.25;
  analogWrite(LED_PIN_2, intensity);


  // Action 4
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN_3, HIGH);
    
  } else {
    digitalWrite(LED_PIN_3, LOW);
    
  }

}
