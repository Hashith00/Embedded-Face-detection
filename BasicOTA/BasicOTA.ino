#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change to your I2C address if needed

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200); // Initialize Serial for communication with ESP32
  lcd.print("Waiting for data");
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Message:");
    lcd.setCursor(0, 1);
    lcd.print(message);
  }
}
