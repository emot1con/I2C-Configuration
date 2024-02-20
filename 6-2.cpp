#define BLYNK_TEMPLATE_ID "TMPL6xp2GFC0C"
#define BLYNK_TEMPLATE_NAME "Ta"
#define BLYNK_AUTH_TOKEN "w-4oDskfbf7MKLGTttOiXNF8Vx1bXzvf"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN D4           
#define DHTTYPE DHT11       

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  Blynk.virtualWrite(V0, t); 
  Blynk.virtualWrite(V1, h);  
}

BLYNK_CONNECTED() {
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  dht.begin();

  timer.setInterval(2000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}