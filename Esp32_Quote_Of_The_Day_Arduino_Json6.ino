/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 12:19 AM - date 09 june 2021
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

http.begin("https://zenquotes.io/api/random");

int httpCode = http.GET();                                        
if (httpCode > 0) { 
String payload = http.getString();
StaticJsonDocument<1024> doc;
DeserializationError error = deserializeJson(doc, payload);

JsonObject root_0 = doc[0];

const char* root_0_q = root_0["q"];
const char* root_0_a = root_0["a"];

Serial.println();

Serial.print("Author : "); Serial.println(root_0_a);
Serial.print("Quote : "); Serial.println(root_0_q);

    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end();
    }

  delay(10000);

}
