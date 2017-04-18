# ISKO-Monitor

ESP-8266 Software for Parsing [JSON information](http://portal.chmi.cz/files/portal/docs/uoco/web_generator/aqindex_cze.json) of Air Quality Index from [Czech Hydrometeorological Institute ISKO2 Project](http://portal.chmi.cz/files/portal/docs/uoco/web_generator/actual_hour_data_CZ.html) and displaying the results on a 32 Pixel WS2801 Programmable Led Strip in a light bar style.

## Dependencies

#### [Adafruit-WS2801-Library](https://github.com/adafruit/Adafruit-WS2801-Library)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![Adafruit Industries](https://avatars1.githubusercontent.com/u/181069?s=48 "Adafruit Industries")](https://github.com/adafruit) | Arduino library for controlling strips/pixels using WS2801 driver chips. | [43ca5e0](https://github.com/adafruit/Adafruit-WS2801-Library/tree/43ca5e0bc78e51722418eb1f5099eba972e6fa95) | BSD license |

#### [json-streaming-parser](https://github.com/squix78/json-streaming-parser)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![Daniel Eichhorn](https://avatars2.githubusercontent.com/u/716822?s=48 "Daniel Eichhorn")](https://github.com/squix78) | Arduino library for parsing potentially huge json streams<br>on devices with scarce memory. | [531870a](https://github.com/squix78/json-streaming-parser/tree/531870ac432e5c240706fc854e28d4b3222d4926) | MIT license |

#### [WiFiManager](https://github.com/tzapu/WiFiManager)
| Author  | Description    | Used Commit   | License   |
| ------- | -------------- | ------------- | --------- |
| [![tzapu](https://avatars2.githubusercontent.com/u/2983312?s=48 "tzapu")](https://github.com/tzapu) | ESP8266 WiFi Connection manager with web captive portal. | [04d4788](https://github.com/tzapu/WiFiManager/commit/04d47882a7d662b46bb1b1dbecfe786e5bc9efa4) | MIT license |

## Legend
![LED Strip Legend](/Docs/images/legend.png?raw=true "LED Strip Legend")