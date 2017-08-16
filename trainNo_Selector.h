#include "trainAPI.h"

extern String returnTrainNo="";
String trainNo_Selector(void)
{
   HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;
    http.begin("http://api.thingspeak.com/channels/305384/feeds.json?api_key=D01XQU7ZO3NZ3CDK&results=1");

     delay(200);
     int httpCode = http.GET(); //Send the request
     String payload = http.getString();   
     //Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
     //Serial.println(payload);    //Print request response payload
     JsonObject& root = jsonBuffer.parseObject(payload);
   
       if(!root.success()){
             Serial.println("Nope");
              }
  
            else{
              JsonArray& feeds = root["feeds"];
              JsonObject& feeds1 = feeds[0];
                          
              String returnTrainNo = feeds1["field1"];
             // getTrainData(returnTrainNo);
              
              }
}
