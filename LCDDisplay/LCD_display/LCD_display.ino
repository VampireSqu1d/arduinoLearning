#include <LiquidCrystal.h>

#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
int cursorLine = 0;
String lastText = "";

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  lcd.begin(16,2);
}

void loop() {

  if(Serial.available()) {
    String text = Serial.readString();
    printUserTextOnDisplay(text);
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



