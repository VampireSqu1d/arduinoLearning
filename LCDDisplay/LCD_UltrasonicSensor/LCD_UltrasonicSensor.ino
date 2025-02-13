#include <LiquidCrystal.h>

#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
int cursorLine = 0;
String lastText = "";

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonictriggerDelay = 500;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile double previousDistnce = 400.0;
volatile bool newDistanceAvailable = false;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO_PIN), 
                  echoPinInterupt, 
                  CHANGE);

  lcd.begin(16,2);
}

void loop() {

  unsigned long timeNow = millis();

  if (timeNow - lastTimeUltrasonicTrigger > ultrasonictriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonictriggerDelay;
    // trigger sensor
    triggerUltrasonicSensor();
  }

  if (newDistanceAvailable) {
    newDistanceAvailable = false;
    lcd.clear();
    double distance = getUltrasonicDistance();
    lcd.setCursor(0, 1);
    lcd.print("Distance:");
    lcd.print(distance);
    lcd.print("cm");
  }
}


void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}


double getUltrasonicDistance() {
  double duration =  pulseInTimeEnd - pulseInTimeBegin;// you canprint this value if you want to know the duration of the pulse
  
  lcd.print("Rate: ");
  lcd.print(ultrasonictriggerDelay);
  lcd.print("ms");
  double distance = duration / 58.0; // distance in cm
  if( distance > 400.0) {
    return previousDistnce;
  }
  distance = (0.7 * previousDistnce) + (0.3 * distance); // this is a complementary filter
  previousDistnce = distance;
  return distance;
}


void echoPinInterupt() {
  if (digitalRead(ECHO_PIN) == HIGH) {
    // rising
    pulseInTimeBegin = micros();
  } else {
    // falling
    pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }
}

void printUserTextOnDisplay(String text) {
  
  if (text.length() > 16) {
    text = "text too long";
  }

  if (text.equals("clear")) {
    lcd.clear();
    return;
  }
  
  for(int i = text.length(); i < 16; i++) {
    text = text + " ";
  }

  lcd.setCursor(0, 0);
  lcd.print(lastText);
  lcd.setCursor(0, 1);
  lcd.print(text);

  lastText = text;
  /*this code is for line toggle
  lcd.setCursor(0, cursorLine);
  lcd.print(text);
  if (cursorLine == 1) cursorLine = 0;
  else cursorLine = 1;
  */
}



