#define LED_PIN LED_BUILTIN  


unsigned long previousTimeLEDBlink = millis();
unsigned long blinkDelay = 480;

int LEDState = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long timeNow = millis();
  if( Serial.available() > 0) {
    int data = Serial.parseInt();
    if (data >= 100 && data <=3000) {
      blinkDelay = data;
      Serial.print("updated blink delay to: ");
      Serial.println(blinkDelay);
    } else {
      Serial.println("value not valid, provide a value between 100 and 1000");
    }
  }

  if (timeNow - previousTimeLEDBlink > blinkDelay) {
    if(LEDState == LOW) {
    LEDState = HIGH;
    } else {
      LEDState = LOW;
    }
    digitalWrite(LED_PIN, LEDState);
    previousTimeLEDBlink += blinkDelay;
  }
  
}
