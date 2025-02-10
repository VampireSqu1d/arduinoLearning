#include <EEPROM.h>

#define LED_PIN 10
#define POTENCIOMETER_PIN A2
#define EEPROM_ADDRESS_MAX_BRIGHTNESS 300
#define MAX_BRIGHTNESS_DEFAULT 255
byte max_brightness;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);


  max_brightness = EEPROM.read(EEPROM_ADDRESS_MAX_BRIGHTNESS);
  if(max_brightness == 0) {
    max_brightness = MAX_BRIGHTNESS_DEFAULT;
  }
}



void loop() {
  if(Serial.available() > 0) {
    int data = Serial.parseInt();

    if(data >= 0 && data <= 255) {
      Serial.println(data);
      EEPROM.write(300, data);
      max_brightness = data;
    }

  }

  byte LEDBrightness = analogRead(POTENCIOMETER_PIN) * 0.25;
  if (LEDBrightness >= max_brightness ) {
    LEDBrightness = max_brightness;
  }


  analogWrite(LED_PIN, LEDBrightness);
}






