#define LED_PIN_1 12
#define LED_PIN_2 11
#define LED_PIN_3 10

#define BUTTON_PIN 2
//#define POTENCIOMETER_PIN A2

// LED 1 setup
unsigned long previousTimeLED1Blink = millis();
unsigned long timeIntervalLED1Blink = 5000;
byte LED1State = LOW;
// LED 2 setup
unsigned long previousTimeLED2Blink = millis();
unsigned long timeIntervalLED2Blink = 5000;
byte LED2State = LOW;

// LED 3 setup
unsigned long previousTimeLED3Blink = millis();
unsigned long timeIntervalLED3Blink = 500;
byte LED3State = LOW;

// Button setup
unsigned long lastTimeButtonPressed = millis();
unsigned long debounceDelay = 40;
byte buttonState = LOW;
byte toggleLEDState = 1;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT);
  buttonState = digitalRead(BUTTON_PIN);
}

void loop() {
  unsigned long timeNow = millis();

  // Action 1 Blink LED 1
  if (timeNow -previousTimeLED1Blink > timeIntervalLED1Blink ) {
    
    blinkLED( LED_PIN_1, LED1State);

    previousTimeLED1Blink += timeIntervalLED1Blink;
  }
  // Action 2 Blink LED 2
  if (timeNow -previousTimeLED2Blink > timeIntervalLED2Blink ) {
    
    blinkLED(LED_PIN_2, LED2State);

    previousTimeLED2Blink += timeIntervalLED2Blink;
  }

  // Action 3 Blink LED 3
  if (timeNow -previousTimeLED3Blink > timeIntervalLED3Blink ) {
    
    blinkLED(LED_PIN_3, LED3State);

    previousTimeLED3Blink += timeIntervalLED3Blink;
  }


  // Action 4 toggle LEDs
  if (timeNow - lastTimeButtonPressed > debounceDelay) {
    byte newButtonState = digitalRead(BUTTON_PIN);
    if (newButtonState != buttonState) {
      lastTimeButtonPressed = timeNow;
      buttonState = newButtonState;

      if(buttonState == HIGH) {
        toggleLEDs1and2();
      }
    }
  }

}

void blinkLED(byte LED_PIN, byte LEDState) {
  if(LEDState == LOW) {
      LEDState = HIGH;
    } else {
      LEDState = LOW;
    }
    digitalWrite( LED_PIN, LEDState);
}

void toggleLEDs1and2() {
  if( toggleLEDState == 1) {
    toggleLEDState = 2;
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
  } else {
    toggleLEDState = 1;
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, HIGH);
  }
}

