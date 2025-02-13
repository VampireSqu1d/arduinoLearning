#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define GREEN_LED  12
#define ORANGE_LED 11
#define BLUE_LED 10

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonictriggerDelay = 65;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile double previousDistnce = 400.0;
volatile bool newDistanceAvailable = false;


void setup() {
  Serial.begin(115200);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO_PIN), 
                  echoPinInterupt, 
                  CHANGE);
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
    double distance = getUltrasonicDistance();
    //Serial.print("distance of the object: ");
    Serial.println(distance);

    // toggle LEDs based on distance
    if (distance < 15 && distance > 0) {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(ORANGE_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
    }
    else if (distance >= 15 && distance < 30) {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(ORANGE_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
    }
    else {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(ORANGE_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
    }
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








