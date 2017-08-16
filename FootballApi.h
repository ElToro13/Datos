String output1 ="";
void Live_score()
{
    HTTPClient http;    //Declare object of class HTTPClient
    DynamicJsonBuffer jsonBuffer;   
    http.begin("http://api.football-api.com/2.0/matches/2212912?Authorization=565ec012251f932ea4000001fa542ae9d994470e73fdb314a8a56d76");
    delay(5000);  
     int httpCode = http.GET(); //Send the request
     String payload = http.getString();   
     //Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
     //Serial.println(payload);    //Print request response payload
      
     JsonObject& root = jsonBuffer.parseObject(payload);
    
       if(!root.success()){
             Serial.println("Nope");          
              }
           else{       
            
                String LocalTeamScore = root["localteam_score"];
                String AwayTeamScore = root["visitorteam_score"];
                String LocalTeamName = root["localteam_name"];
                String AwayTeamName = root["visitorteam_name"];
                String Display = LocalTeamScore + " - " + AwayTeamScore;
                String NameHome = LocalTeamName + " (H)";
                String NameAway = AwayTeamName + " (A)";
                String Status = root["status"];
                Status = Status + "'";

                JsonArray& events = root["events"];
                 int count = events.size();
                 count=count-1;
                JsonObject& place = events[count];
                String type = place["result"];
                if(type != NULL){
                  String player = place["player"];
                  String minute = place["minute"];
                  String Assist = place["assist"];
                  String output1 = player + " [ " + minute + " ' ]";
                  display.setTextAlignment(TEXT_ALIGN_LEFT);
                display.setFont(ArialMT_Plain_10);
                display.drawString(30,43,output1);
                display.display();   
                }
              
                
                                 
                display.setTextAlignment(TEXT_ALIGN_LEFT);
                display.setFont(ArialMT_Plain_10);
                display.drawString(0,0,NameHome);
                display.setTextAlignment(TEXT_ALIGN_LEFT);
                display.setFont(ArialMT_Plain_10);
                display.drawString(0,14,NameAway);
                display.setTextAlignment(TEXT_ALIGN_LEFT);
                display.setFont(ArialMT_Plain_16);
                display.drawString(47,25,Display);    
                         
                display.setTextAlignment(TEXT_ALIGN_LEFT);
                display.setFont(ArialMT_Plain_10);
                display.drawString(55,53,Status);
                display.display();  
                   
                }
  
}
