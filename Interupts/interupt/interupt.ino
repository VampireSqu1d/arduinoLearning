#define LED_PIN 12
#define BUTTON_PIN 2

byte LEDState = LOW;

// Button setup
volatile unsigned long lastTimeButtonReleased = millis();
unsigned long debounceDelay = 40;
byte buttonState = LOW;
byte toggleLEDState = 1;
volatile bool buttonPressed = false;
unsigned int button_counter = 0;


void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(
  digitalPinToInterrupt(BUTTON_PIN), 
    buttonReleasedInterupt, 
    CHANGE);

  //buttonState = digitalRead(BUTTON_PIN);
}

void buttonReleasedInterupt() {
  unsigned long timeNow = millis();

  if (timeNow - lastTimeButtonReleased > debounceDelay) {
    lastTimeButtonReleased = timeNow;
    buttonPressed = true;
  }
}

void toggleLED() {
  if(LEDState == LOW) {
    LEDState = HIGH;
  } else {
    LEDState = LOW;
  }
  digitalWrite(LED_PIN,LEDState);
}


void loop() {
  if (buttonPressed) {
    buttonPressed = false;
    if (buttonState == HIGH) {
      buttonState = LOW;
      button_counter++;

      Serial.println(button_counter);
    } else {
      buttonState = HIGH;
    }
    toggleLED();
  }


  

}
