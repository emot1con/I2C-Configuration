#include <Wire.h>

bool kirimLDR = true;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(8);

  if (kirimLDR) {
    int ldrValue = analogRead(A0);

    Wire.write(1); // ID = 1 (LDR)
    Wire.write(ldrValue >> 8);
    Wire.write(ldrValue & 0xFF);

    Serial.print("Kirim LDR: ");
    Serial.println(ldrValue);
  } else {
    int tempRaw = analogRead(A1);
    float voltage = tempRaw * (5.0 / 1023.0);
    float tempC = voltage * 100;
    int tempInt = tempC * 100;

    Wire.write(2); // ID = 2 (TMP)
    Wire.write(tempInt >> 8);
    Wire.write(tempInt & 0xFF);

    Serial.print("Kirim TMP: ");
    Serial.println(tempC);
  }

  Wire.endTransmission();

  kirimLDR = !kirimLDR; // toggle
  delay(1000);
}
