/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 07:19 PM - date 20 june 2021
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
http.begin("http://api.open-notify.org/iss-now.json");
int httpCode = http.GET();                                        
if (httpCode > 0) { 
String payload = http.getString();


StaticJsonDocument<755> doc;

DeserializationError error = deserializeJson(doc, payload);

long timestamp = doc["timestamp"];
const char* message = doc["message"]; 

const char* iss_position_latitude = doc["iss_position"]["latitude"]; 
const char* iss_position_longitude = doc["iss_position"]["longitude"];


Serial.println();
Serial.print("Lalitude : "); Serial.println(iss_position_latitude);
Serial.print("Longitude : "); Serial.println(iss_position_longitude);

}

    else {
      Serial.println("Error on HTTP request");
}

    http.end();
}

  delay(10000);

}
