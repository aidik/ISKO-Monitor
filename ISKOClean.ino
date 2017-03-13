#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include "ISKOJsonClient.h"

#define USE_SERIAL Serial
#define BOX_NAME "ISKO-MONITOR"

ISKOJsonClient ISKOClient;

void setup() {
  USE_SERIAL.begin(115200);
  USE_SERIAL.flush();

  WiFi.hostname(BOX_NAME);
  
  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  wifiManager.autoConnect(BOX_NAME, "iskomagic");
  
  
  
  //WiFiManager wifiManager;
  

  


}

void loop() {
  // is configuration portal requested?
  USE_SERIAL.println("IP address: ");
  USE_SERIAL.println(WiFi.localIP());
  ISKOClient.parseISKOJson();
  USE_SERIAL.println("Index v Libusi: ");
  USE_SERIAL.println(ISKOClient.getIndex());  
  delay(900000);

}
