#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "PASTE WIFI SSID";
const char* password = "PASTE WIFI PASSWORD";

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.print("Connected");
  Serial.println();

}

void loop() {

  if ((WiFi.status() == WL_CONNECTED)) { 

    HTTPClient http;

    http.begin("https://api.coronatracker.com/v3/stats/worldometer/country?countryCode=IN");
    int httpCode = http.GET();                                        

    if (httpCode > 0) { 

      String payload = http.getString();
      Serial.println(payload);

    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end();
    }

  delay(10000);

}
