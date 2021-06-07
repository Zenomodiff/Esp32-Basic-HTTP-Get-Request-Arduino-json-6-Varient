/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 12:09 AM - date 08 june 2021
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
http.begin("https://api.coronatracker.com/v3/stats/worldometer/country?countryCode=IN");
int httpCode = http.GET();                                        
if (httpCode > 0) { 
String payload = http.getString();
StaticJsonDocument<768> doc;
DeserializationError error = deserializeJson(doc, payload);

JsonObject root_0 = doc[0];
const char* root_0_countryCode = root_0["countryCode"];
const char* root_0_country = root_0["country"]; 
double root_0_lat = root_0["lat"]; 
float root_0_lng = root_0["lng"];
long root_0_totalConfirmed = root_0["totalConfirmed"];
long root_0_totalDeaths = root_0["totalDeaths"];
long root_0_totalRecovered = root_0["totalRecovered"]; 
int root_0_dailyConfirmed = root_0["dailyConfirmed"];
int root_0_dailyDeaths = root_0["dailyDeaths"]; 
long root_0_activeCases = root_0["activeCases"]; 
int root_0_totalCritical = root_0["totalCritical"]; 
int root_0_totalConfirmedPerMillionPopulation = root_0["totalConfirmedPerMillionPopulation"]; 
int root_0_totalDeathsPerMillionPopulation = root_0["totalDeathsPerMillionPopulation"]; 
const char* root_0_FR = root_0["FR"]; 
const char* root_0_PR = root_0["PR"]; 
const char* root_0_lastUpdated = root_0["lastUpdated"];

Serial.println();
Serial.print("Country : "); Serial.println(root_0_country);
Serial.print("Total Confirmed : "); Serial.println(root_0_totalConfirmed);
Serial.print("Total Deaths : "); Serial.println(root_0_totalDeaths);
Serial.print("Total Recovered : "); Serial.println(root_0_totalRecovered);
Serial.print("Conformed Today : "); Serial.println(root_0_dailyConfirmed);
Serial.print("Deaths Today : "); Serial.println(root_0_dailyDeaths);
Serial.print("Active Cases : "); Serial.println(root_0_activeCases);
Serial.print("Critical : "); Serial.println(root_0_totalCritical);
Serial.print("Last Updated : "); Serial.println(root_0_lastUpdated);

    }

    else {
      Serial.println("Error on HTTP request");
    }

    http.end();
    }

  delay(10000);

}
