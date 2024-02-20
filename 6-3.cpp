#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "w-4oDskfbf7MKLGTttOiXNF8Vx1bXzvf"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 15
#define DHTTYPE DHT22

#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void kirimSensor() {
  
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);

  Serial.print("Temp: ");
  Serial.println(temp);

  Serial.print("Hum: ");
  Serial.println(hum);
}

BLYNK_WRITE(V2) {
  
  int state = param.asInt();

  digitalWrite(LED_PIN, state);
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  Blynk.begin(
    BLYNK_AUTH_TOKEN,
    ssid,
    pass
  );

  timer.setInterval(2000L, kirimSensor);
}

void loop() {

  Blynk.run();

  timer.run();
}