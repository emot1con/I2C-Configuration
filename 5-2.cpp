#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ldrValue = 0;
float tempValue = 0;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);

  lcd.init();
  lcd.backlight();
}

void loop() {
  static bool tampilLDR = true;

  lcd.clear();

  if (tampilLDR) {
    lcd.setCursor(0, 0);
    lcd.print("LDR:");
    lcd.print(ldrValue);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("TMP:");
    lcd.print(tempValue);
    lcd.print(" C");
  }

  tampilLDR = !tampilLDR;
  delay(1000);
}

void receiveEvent(int bytes) {
  if (Wire.available() >= 3) {
    int id = Wire.read();
    int high = Wire.read();
    int low  = Wire.read();

    int value = (high << 8) | low;

    if (id == 1) {
      ldrValue = value;
    } else if (id == 2) {
      tempValue = value / 100.0;
    }
  }
}