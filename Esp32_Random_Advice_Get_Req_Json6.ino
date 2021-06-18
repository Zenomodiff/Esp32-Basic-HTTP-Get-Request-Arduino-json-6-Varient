/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 08:45 AM - date 17 june 2021
 * Github Link :-- https://github.com/Zenomodiff/Esp32-Basic-HTTP-Get-Request-Arduino-json-6-Varient
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Zeno";
const char* password = "9061116368";

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

http.begin("https://api.adviceslip.com/advice");

int httpCode = http.GET();                                        
if (httpCode > 0) { 
String payload = http.getString();
StaticJsonDocument<1024> doc;
DeserializationError error = deserializeJson(doc, payload);

int slip_id = doc["slip"]["id"];
const char* slip_advice = doc["slip"]["advice"]; 

Serial.println();
Serial.print("ID : "); Serial.println(slip_id);
Serial.print("Slip : "); Serial.println(slip_advice);

    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end();
    }

  delay(10000);

}
