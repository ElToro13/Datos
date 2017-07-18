void reminder()
{
   HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;
   
    //http.begin("http://dataservice.accuweather.com/currentconditions/v1/202439?apikey=GYpocjiLIX4Vb9RLeArUSc9jsDXY5Bku&details=true");
    //http.begin("http://dataservice.accuweather.com/locations/v1/cities/search?apikey=GYpocjiLIX4Vb9RLeArUSc9jsDXY5Bku&q=Mumbai");
    http.begin("http://api.thingspeak.com/channels/304393/feeds.json?api_key=ZPF6VN52HG3P01IH&results=1");

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
                          
              String reminderData = feeds1["field1"];
              
              display.setTextAlignment(TEXT_ALIGN_LEFT);
              display.setFont(ArialMT_Plain_10);
              display.drawString(30,15,"** Reminder **");
              display.display();
              
              display.setTextAlignment(TEXT_ALIGN_LEFT);
              display.setFont(ArialMT_Plain_10);
              display.drawString(0,30,reminderData);
              display.display();
              
              }
}

