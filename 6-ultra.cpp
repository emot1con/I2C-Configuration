#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "YOUR_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define TRIG D1
#define ECHO D2

BlynkTimer timer;

void sendDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Blynk.virtualWrite(V0, distance);
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendDistance);
}

void loop() {

  Blynk.run();
  timer.run();
}