/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 08:45 AM - date 17 june 2021
 * Github Link :-- https://github.com/Zenomodiff/Esp32-Basic-HTTP-Get-Request-Arduino-json-6-Varient
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "PASTE SSID NAME";
const char* password = "PASTE SSID PASSWORD";

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
StaticJsonDocument<1024> doc;
DeserializationError error = deserializeJson(doc, payload);

const char* activity = doc["activity"]; 
const char* type = doc["type"];
int participants = doc["participants"]; 
float price = doc["price"]; 
const char* link = doc["link"]; 
const char* key = doc["key"]; 
float accessibility = doc["accessibility"]; 

Serial.println();
Serial.print("Activity : "); Serial.println(activity);
Serial.print("Participants : "); Serial.println(participants);
Serial.print("Link : "); Serial.println(link);

    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end();
    }

  delay(10000);

}
