#include <TimeLib.h>
int hour1 = 0;
int minute1 = 0;
int seconds1 = 0;
String outputHour = "";
String outputMinute = "";
String outputSecond = "";
boolean check = true;
int daychecker = 0;
String Day="";
String DayDate="";
void watch(int H, int M, String S) {
  for (hour1 = H; hour1 <= 23; hour1++) {
    for (minute1 = M; minute1 <=59; minute1++) {
      for (int seconds2 = 0; seconds2 <=59; seconds2++) {
        display.clear();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_10);
        display.drawString(0,0, DayDate);
        outputHour = String((int)hour1) + ": ";
        outputMinute = String((int)minute1) + " ";
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_24);
        display.drawString(25, 22, outputHour);
        display.setFont(ArialMT_Plain_16);
        display.drawString(57,29,outputMinute);
        display.setFont(ArialMT_Plain_16);
        display.drawString(73,29," " + S);
        display.display();
        delay(1000);
      }

    }
  }
}

void WATCH_display(){
daychecker = weekday();
if(daychecker == 1){
  Day = "Sun";
}
else if(daychecker == 2){
  Day = "Mon";
}
else if(daychecker == 3){
  Day = "Tue";
}
else if(daychecker == 4){
  Day = "Wed";
}
else if(daychecker == 5){
  Day = "Thu";
}
else if(daychecker == 6){
  Day = "Fri";
}
else{
  Day = "Sat";
}
DayDate = Day + ",  " + __DATE__ ;
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
              String S = feeds1["field3"];
              int Ho = H.toInt();
              int Mi = M.toInt();              
              watch(Ho,Mi,S);
    }
    
    }
}


