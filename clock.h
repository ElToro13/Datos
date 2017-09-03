#include <TimeLib.h>
boolean check = true;
int daychecker = 0;
int Hou;
int Min;
int Ho;
int Mi;
int seco;
String Day="";
String DayDate="";

void WATCH_display(){
  
  if(check){
      HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;

    //http.begin("http://dataservice.accuweather.com/currentconditions/v1/202439?apikey=GYpocjiLIX4Vb9RLeArUSc9jsDXY5Bku&details=true");
    //http.begin("http://dataservice.accuweather.com/locations/v1/cities/search?apikey=GYpocjiLIX4Vb9RLeArUSc9jsDXY5Bku&q=Mumbai");
    http.begin("http://api.thingspeak.com/channels/324854/feeds.json?api_key=6QQNWSESYKN1IH9I&results=1");

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
              String H = feeds1["field1"];
              String M = feeds1["field2"];
             // String S = feeds1["field3"];
             
              Ho = H.toInt();
              Mi = M.toInt();
              //watch(Ho,Mi);
    }
    check = false;
    }
              Hou = hour();
              Min = minute();
              seco = second();
              Hou = Hou + Ho;
              Min = Min + Mi;
              Serial.print(Hou);
              Serial.print(" : ");
              Serial.print(Min);
              Serial.print(" : ");
              Serial.println(seco);
              delay(1000);
}


