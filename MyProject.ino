#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include "SSD1306.h"
SSD1306  display(0x3C, 4, 5);
MDNSResponder mdns;
ESP8266WebServer server(80);

 int i=0;
 String tempSymbol=" *C |";
 String sep=" | UV:";
 
void setup() {
   Serial.begin(115200);
  display.init();         
 // display.flipScreenVertically();
 
  display.setColor(WHITE);
  display.clear();

  WiFi.begin("K R SONI", "krsoni2568");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.print(".");

  }
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   Serial.println("WiFi Connected....");
   for (int16_t i=0; i<DISPLAY_HEIGHT; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, 0, i);
    display.display();
    delay(10);
  }
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, i, DISPLAY_HEIGHT-1);
    display.display();
    delay(10);
  }
  delay(1000);
   display.clear();
   display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_24);
    display.drawString(15,15,"Welcome");
    display.display();
    delay(1500);
    display.clear();
    display.drawString(45,15,"To");
    display.display();
    delay(1500);
    display.clear();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,20,"AccuWeather API");
    display.display();
    delay(1500);
  }
else{
  Serial.println("Wifi Not Connected!");
}
 if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
    

  }
 
    server.begin();
}
void loop() { 
  server.handleClient();
 // getTrainData();
 getWeather();
  delay(20000);
  
}


