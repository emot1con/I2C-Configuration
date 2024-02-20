#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define SOIL_PIN A0

BlynkTimer timer;

void sendSoil() {

  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  Blynk.virtualWrite(V0, soilValue);
}

void setup() {

  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendSoil);
}

void loop() {

  Blynk.run();
  timer.run();
}