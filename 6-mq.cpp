#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define MQ_PIN A0

BlynkTimer timer;

void sendGas() {

  int gasValue = analogRead(MQ_PIN);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Blynk.virtualWrite(V0, gasValue);
}

void setup() {

  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendGas);
}

void loop() {

  Blynk.run();
  timer.run();
}