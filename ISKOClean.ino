#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <Adafruit_WS2801.h>
#include <SPI.h>

#include "ISKOJsonClient.h"

#define USE_SERIAL Serial
#define BOX_NAME "ISKO-MONITOR"

ISKOJsonClient ISKOClient;
uint8_t dataPin  = 4;    // Red wire (other red is 5V - Be Careful!)
uint8_t clockPin = 5;    // Green wire
Adafruit_WS2801 strip = Adafruit_WS2801(32, dataPin, clockPin);

void setup() {
  USE_SERIAL.begin(115200);
  USE_SERIAL.flush();

  strip.begin();
  strip.show();

  WiFi.hostname(BOX_NAME);
  
  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  wifiManager.autoConnect(BOX_NAME, "iskomagic");
  
}

void loop() {
  // is configuration portal requested?
  USE_SERIAL.println("IP address: ");
  USE_SERIAL.println(WiFi.localIP());
  ISKOClient.parseISKOJson();
  USE_SERIAL.println("Index v Libusi: ");
  USE_SERIAL.println(ISKOClient.getIndex());  
  indexShow(ISKOClient.getIndex());
  delay(900000);

}

void indexShow(int index) {
  int i;
  switch (index) {
      case 0:
        strip.setPixelColor(0, Color(255, 0, 0));
        for (i=1; i < 11; i++) {
          strip.setPixelColor(i, Color(0, 0, 255));
        }
        for (i=11; i < 21; i++) {
          strip.setPixelColor(i, Color(255, 255, 255));
        }
        for (i=21; i < 31; i++) {
          strip.setPixelColor(i, Color(0, 255, 0));
        }                    
        strip.setPixelColor(31, Color(255, 0, 0));
        strip.show();
        break;
      case 1:
        for (i=0; i < 10; i++) {
          strip.setPixelColor(i, Color(40, 255, 185));
        }
        for (i=10; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(0, 0, 0));
        }        
        strip.show();
        break;        
      case 2:
        for (i=0; i < 16; i++) {
          strip.setPixelColor(i, Color(10, 2, 255));
        }
        for (i=16; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(0, 0, 0));
        }        
        strip.show();
        break;   
      case 3:
        for (i=0; i < 22; i++) {
          strip.setPixelColor(i, Color(255, 0, 245));
        }
        for (i=22; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(0, 0, 0));
        }        
        strip.show();
        break;
      case 4:
        for (i=0; i < 28; i++) {
          strip.setPixelColor(i, Color(255, 0, 45));
        }
        for (i=28; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(0, 0, 0));
        }        
        strip.show();
        break;                 
      case 5:
        for (i=0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(255, 0, 0));
        }        
        strip.show();
        break;
      case 6:
        for (i=0; i < 3; i++) {
          strip.setPixelColor(i, Color(255, 0, 245));
        }      
        for (i=3; i < 29; i++) {
          strip.setPixelColor(i, Color(255, 0, 0));
        }        
        for (i=29; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, Color(255, 0, 245));
        }        
        strip.show();
        break;        
      case -1:
        strip.setPixelColor(0, Color(255, 0, 0));
        for (i=1; i < 11; i++) {
          strip.setPixelColor(i, Color(15, 15, 15));
        }
        for (i=11; i < 21; i++) {
          strip.setPixelColor(i, Color(7, 7, 7));
        }
        for (i=21; i < 31; i++) {
          strip.setPixelColor(i, Color(1, 1, 1));
        }                    
        strip.setPixelColor(31, Color(255, 0, 0));
        strip.show();
        break;
      case -2:
        strip.setPixelColor(0, Color(255, 0, 0));
        for (i=1; i < 31; i=i+2) {
          strip.setPixelColor(i, Color(255, 75, 0));
          strip.setPixelColor(i, Color(0, 0, 0));
        }
        strip.setPixelColor(31, Color(255, 0, 0));
        strip.show();
        break;                
      default: 
        strip.setPixelColor(0, Color(255, 0, 0));      
        for (i=1; i < strip.numPixels()-1; i++) {
          strip.setPixelColor(i, Color(random(0, 256), random(0, 256), random(0, 256)));
        }        
        strip.setPixelColor(31, Color(255, 0, 0));        
        strip.show();
      break;
    }
  }

uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
  
