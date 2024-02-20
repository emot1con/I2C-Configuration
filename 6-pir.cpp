#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define PIR_PIN D5

BlynkTimer timer;

void checkMotion() {

  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Gerakan Terdeteksi");
    Blynk.virtualWrite(V0, 1);
  } else {
    Serial.println("Tidak Ada Gerakan");
    Blynk.virtualWrite(V0, 0);
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, checkMotion);
}

void loop() {

  Blynk.run();
  timer.run();
}