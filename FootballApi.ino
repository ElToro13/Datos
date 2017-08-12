
void Live_score()
{
    HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;   
    http.begin("http://api.football-api.com/2.0/matches/2212909?Authorization=565ec012251f932ea4000001fa542ae9d994470e73fdb314a8a56d76");
     delay(200);
     int httpCode = http.GET(); //Send the request
     String payload = http.getString();   
     //Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
     Serial.println(payload);    //Print request response payload
     JsonObject& root = jsonBuffer.parseObject(payload);
   
       if(!root.success()){
             Serial.println("Nope");
              }
           else{
        
        String LocalTeamScore = root["localteam_score"];
        String AwayTeamScore = root["visitorteam_score"];
        String Display = LocalTeamScore + " - " + AwayTeamScore;
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_24);
        display.drawString(50,15,Display);
        display.display();
        
       }
  
}

