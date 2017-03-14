#include "ISKOJsonClient.h"


ISKOJsonClient::ISKOJsonClient() {}


void ISKOJsonClient::parseISKOJson() {
  JsonStreamingParser parser;
  parser.setListener(this);
  WiFiClient client;

  // http://portal.chmi.cz/files/portal/docs/uoco/web_generator/aqindex_cze.json
  const char host[] = "portal.chmi.cz";
  String url = "/files/portal/docs/uoco/web_generator/aqindex_cze.json";

  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }


  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  int retryCounter = 0;
  while(!client.available()) {
    Serial.println(".");
    delay(1000);
    retryCounter++;
    if (retryCounter > 10) {
      noNewData = true;
      return;
    }
  }

  noNewData = true;
  char c;
  int size = 0;
  client.setNoDelay(false);
  while(client.connected()) {
    while((size = client.available()) > 0) {
      c = client.read();
       parser.parse(c);
    }
  }
}

int ISKOJsonClient::getIndex() {
  if (noNewData == true) {
    return -1;
  } else if (finIndex == "0") {
    return 0;
  } else {
    int indexValue = finIndex.toInt();
    if (indexValue == 0) {
      return -2;
    } else {
      return indexValue;
    } 
  }
}

void ISKOJsonClient::whitespace(char c) {
  //Serial.println("whitespace");
}

void ISKOJsonClient::startDocument() {
  //Serial.println("start document");
}

void ISKOJsonClient::key(String key) {
  currentKey = key;
  //Serial.println("key: " + key);
}

void ISKOJsonClient::value(String value) {
  if (currentKey == "Code" && ignore == false) {
      code = value;
    }
    
  if (currentKey == "Ix" && ignore == false) {
      ix = value;
    }

  if (currentKey == "Actualized") {
      Serial.println("Aktualizovano: " + value);
    }    

    
  //Serial.println("value: " + value);
}

void ISKOJsonClient::endArray() {
  ignore = false;
}

void ISKOJsonClient::endObject() {
  if (code == "ALIBA" && ignore == false) {
    Serial.println("Index je v Libusi " + ix);
    noNewData = false;
    finIndex = ix;
  }
  //Serial.println("end object. ");
}

void ISKOJsonClient::endDocument() {
  //Serial.println("end document. ");
}

void ISKOJsonClient::startArray() {
     if (currentKey == "Components") {
      ignore = true;
    }
   //Serial.println("start array. ");
}

void ISKOJsonClient::startObject() {
   if (ignore == false) {
    code = "";
    ix = "";
   }
   //Serial.println("start object. ");
}
