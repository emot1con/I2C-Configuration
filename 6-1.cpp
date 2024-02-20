#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "w-4oDskfbf7MKLGTttOiXNF8Vx1bXzvf"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  digitalWrite(D1, pinValue);
}

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  digitalWrite(D2, pinValue);
}

BLYNK_CONNECTED() {
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(D1, OUTPUT); 
  pinMode(D2, OUTPUT);
}

void loop() {
  Blynk.run();
  timer.run();
}