unsigned int returnData;
unsigned int Display_Selector()
{
   HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;
    http.begin("http://api.thingspeak.com/channels/304420/feeds.json?api_key=Q4C0YU46IFR7W8KM&results=1");

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
                          
              String Selector = feeds1["field1"];
              returnData = Selector.toInt();
              return returnData;
              
              }
}
