bool kirimLDR = true;

void setup() {

  Serial.begin(9600);
}

void loop() {

  if (kirimLDR) {

    int ldrValue = analogRead(A0);

    Serial.print("LDR:");
    Serial.println(ldrValue);

  } else {

    int tempRaw = analogRead(A1);

    float voltage = tempRaw * (5.0 / 1023.0);

    float tempC = voltage * 100;

    Serial.print("TMP:");
    Serial.println(tempC);
  }

  kirimLDR = !kirimLDR;

  delay(1000);
}