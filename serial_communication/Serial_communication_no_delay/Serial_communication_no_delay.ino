#define LED_PIN_1 12
#define LED_PIN_2 13

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
  
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow -previousTimeLED1Blink > timeIntervalLED1Blink ) {
    if(LED1State == LOW) {
      LED1State = HIGH;
    } else {
      LED1State = LOW;
    }
    digitalWrite( LED_PIN_1, LED1State);

    previousTimeLED1Blink += timeIntervalLED1Blink;
  }
  
  if (timeNow -previousTimeLED2Blink > timeIntervalLED2Blink ) {
    if(LED2State == LOW) {
      LED2State = HIGH;
    } else {
      LED2State = LOW;
    }
    digitalWrite( LED_PIN_2, LED2State);

    previousTimeLED2Blink += timeIntervalLED2Blink;
  }


}
