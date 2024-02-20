#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String data = "";

int ldrValue = 0;
float tempValue = 0;

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {

  while (Serial.available()) {

    char c = Serial.read();

    if (c == '\n') {

      data.trim();

      if (data.startsWith("LDR:")) {

        ldrValue = data.substring(4).toInt();

      }
      else if (data.startsWith("TMP:")) {

        tempValue = data.substring(4).toFloat();
      }

      data = "";
    }
    else {

      data += c;
    }
  }

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