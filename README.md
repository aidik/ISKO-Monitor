# ISKO-Monitor

ESP-8266 Software for Parsing [JSON information](http://portal.chmi.cz/files/portal/docs/uoco/web_generator/aqindex_cze.json) of Air Quality Index from [Czech Hydrometeorological Institute ISKO2 Project](http://portal.chmi.cz/files/portal/docs/uoco/web_generator/actual_hour_data_CZ.html) and displaying the results on a 32 Pixel WS2801 Programmable Led Strip in a light bar style.

## Dependencies

#### [Arduino core for ESP8266 WiFi chip](https://github.com/esp8266/Arduino)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![ESP8266 Community Forum](https://avatars0.githubusercontent.com/u/8943775?s=48 "ESP8266 Community Forum")](https://github.com/esp8266) | ESP8266 core for Arduino. | [09826c6](https://github.com/esp8266/Arduino/tree/09826c6d87e54c15422da90f060377c9ef188947) | GNU LGPL 2.1 |

#### [json-streaming-parser](https://github.com/squix78/json-streaming-parser)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![Daniel Eichhorn](https://avatars2.githubusercontent.com/u/716822?s=48 "Daniel Eichhorn")](https://github.com/squix78) | Arduino library for parsing potentially huge json streams on devices with scarce memory. | [531870a](https://github.com/squix78/json-streaming-parser/tree/531870ac432e5c240706fc854e28d4b3222d4926) | MIT license |

#### [Adafruit-WS2801-Library](https://github.com/adafruit/Adafruit-WS2801-Library)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![Adafruit Industries](https://avatars1.githubusercontent.com/u/181069?s=48 "Adafruit Industries")](https://github.com/adafruit) | Arduino library for controlling strips/pixels using WS2801 driver chips. | [43ca5e0](https://github.com/adafruit/Adafruit-WS2801-Library/tree/43ca5e0bc78e51722418eb1f5099eba972e6fa95) | BSD license |

#### [WiFiManager](https://github.com/tzapu/WiFiManager)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![tzapu](https://avatars2.githubusercontent.com/u/2983312?s=48 "tzapu")](https://github.com/tzapu) | ESP8266 WiFi Connection manager with web captive portal. | [04d4788](https://github.com/tzapu/WiFiManager/commit/04d47882a7d662b46bb1b1dbecfe786e5bc9efa4) | MIT license |

## Legend
![LED Strip Legend](/Docs/images/legend.png?raw=true "LED Strip Legend")

## Tested on
  * WAVGAT D1 WiFi Uno (WeMos D1 Clone)
  * WS2801 5V Programmable 32 Pixel Digital Led (SMD 5050 RGB) Strip

## Schematics
My Strip arrived from China in protective case and with cables already atached. For some reason both 5V and Data are both red.
![Project Schematics](/Docs/images/schema.png?raw=true "Project Schematics")

## Connection
Thanks to the WiFiManager your device will start in AP mode. Simply connect to the network called *ISKO-MONITOR and use password *iskomagic*.

## Known Issues / To Dos
  * Green and Blue segments are interchanged, either in the used Strip or in Adafruit Library.
  * Libuš (ALIBA Location) is hardcoded into the ISKOJsonClient.
  * Multiple setPixelColor calls on [line 137](/ISKOClean.ino#L137).
  * Data from ISKO are delyed by aproximatly 7 minutes.

## Disclaimer
Pin numbers are different on ESP-8266, pins used in this case are GPIO4 & GPIO05 labeled as D14/SDA & D15/SCL.
My LED Strip was delivered with multiple red cables. Make sure that you know, what connects where.