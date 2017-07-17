void getTrainData(void){
  HTTPClient http;    //Declare object of class HTTPClient
   DynamicJsonBuffer jsonBuffer;
   
   http.begin("http://api.railwayapi.com/live/train/12010/doj/20170716/apikey/dx8s8oak/");
   /* This is Train data for Indian trains. 
    * This particular is for Shatabdi Train which runs between Ahemdabad and Mumbai daily.
   
   http://api.football-api.com/2.0/matches?comp_id=1399&team_id=16110&from_date=20170101&to_date=20170505&Authorization=565ec012251f932ea4000001fa542ae9d994470e73fdb314a8a56d76
   */
   http.addHeader("Content-Type", "application/json");  //Specify content-type header
   delay(200);
   int httpCode = http.GET(); //Send the request
   String payload = http.getString();   
   Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
   Serial.println(payload);    //Print request response payload
   JsonObject& root = jsonBuffer.parseObject(payload);
   
       if(!root.success()){
             Serial.println("Nope");
              }
  
            else{
              
                JsonArray& route = root["route"];
                for(i=0;i<=90;i++)
                {
                     JsonObject& route1=route[i];
                      String det = route1["has_arrived"];
                      if(det!="true"){
                            JsonObject& last = route1["station_"];
                            String Next_station = last["name"];
                            Serial.print(Next_station);
                      }
                }
                
                }
}
