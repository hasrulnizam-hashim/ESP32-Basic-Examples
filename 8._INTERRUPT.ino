#include <LiquidCrystal.h>

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int count = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),counter,FALLING);
  Serial.begin(115200);
}

void loop() {
  Serial.println(count);
  delay(5000);
}

void counter(){
  count++;
}
