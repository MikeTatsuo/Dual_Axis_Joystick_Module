#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define VRX A0
#define VRY A1
#define BUTTON 2

int x_value;
int y_value;

void setup() {
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" Dual Axis Joystick ");

  lcd.setCursor(0, 1);
  lcd.print("X:");

  lcd.setCursor(0, 2);
  lcd.print("Y:");

  lcd.setCursor(0, 3);
  lcd.print("Button:");
}

void loop() {
  lcd.setCursor(8, 3);
  lcd.print("       ");

  lcd.setCursor(3, 1);
  lcd.print("    ");
  x_value = analogRead(VRX);
  lcd.setCursor(3, 1);
  lcd.print(x_value);

  lcd.setCursor(3, 2);
  lcd.print("    ");
  y_value = analogRead(VRY);
  lcd.setCursor(3, 2);
  lcd.print(y_value);

  if (!digitalRead(BUTTON)) {
    lcd.setCursor(8, 3);
    lcd.print("Pressed");
  }

  delay(250);
}