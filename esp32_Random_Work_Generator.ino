/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 01:39 PM - date 12 june 2021
 * Github Link :-- https://github.com/Zenomodiff/Esp32-Basic-HTTP-Get-Request-Arduino-json-6-Varient
 */

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

    http.begin("https://www.boredapi.com/api/activity");
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

  delay(1000);

}
