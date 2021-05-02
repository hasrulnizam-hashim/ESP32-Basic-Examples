#include <LiquidCrystal.h>

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Suhu bilik: ");
  lcd.setCursor(0, 1);
  int temp = analogRead(A0)/2;
  lcd.print(temp);
  lcd.print((char) 223);      //utk degree symbol
  lcd.print("C");
  delay(100);
}
