#pragma once

#include <JsonListener.h>
#include <JsonStreamingParser.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

class ISKOJsonClient: public JsonListener {
  private:
    String code;
    String ix;
    String finIndex;
    String currentKey;
    bool ignore = false;
    bool noNewData = true;  
  
  public:
    ISKOJsonClient();
    void parseISKOJson();
    int getIndex();
    
    virtual void whitespace(char c);
  
    virtual void startDocument();

    virtual void key(String key);

    virtual void value(String value);

    virtual void endArray();

    virtual void endObject();

    virtual void endDocument();

    virtual void startArray();

    virtual void startObject();
};
