// String pre = "http://api.railwayapi.com/v2/live/train/";
// String post = "/date/23-07-2017/apikey/dx8s8oak/";
// String search ="";
int loop1=0, loopCounter=0;
boolean Next_Station = false;
String SN="";
String SNo="";
String RESPONSE="";
void getTrainData(){
  HTTPClient http;    //Declare object of class HTTPClient
   DynamicJsonBuffer jsonBuffer;
 //  search = pre + no + post;
 //  http.begin(search);
   http.begin("http://api.railwayapi.com/v2/live/train/12010/date/24-07-2017/apikey/dx8s8oak/");
   /* This is Train data for Indian trains. 
    * This particular is for Shatabdi Train which runs between Ahemdabad and Mumbai daily.
   
   http://api.football-api.com/2.0/matches?comp_id=1399&team_id=16110&from_date=20170101&to_date=20170505&Authorization=565ec012251f932ea4000001fa542ae9d994470e73fdb314a8a56d76
   */
   http.addHeader("Content-Type", "application/json");  //Specify content-type header
   delay(200);
   int httpCode = http.GET(); //Send the request
   String payload = http.getString();   
   Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
//   Serial.println(payload);    //Print request response payload
   JsonObject& root = jsonBuffer.parseObject(payload);   
       if(!root.success()){
             Serial.println("Nope");
              }
  
            else{       
                  for(loop1=0;loop1<75;loop1++){
                       JsonArray& route = root["route"];
                      JsonObject& route1=route[loop1];
                      JsonObject& last = route1["station_"];
                      boolean HA = route1["has_arrived"];
                      String total = route1["schdep"];
                      if(total=="Destination"){
                        String Number = route1["no"];
                        Serial.print(SN);
                        Serial.print("  ");
                        Serial.print(SNo);
                        Serial.print("/");
                        Serial.println(Number);
                        RESPONSE = "NS: " + SN + "  " + SNo + "/" + Number;
          
                        display.setTextAlignment(TEXT_ALIGN_LEFT);
                        display.setFont(ArialMT_Plain_10);
                        display.drawString(0,45,RESPONSE);
                        display.display();
                      }
                      if(!HA){
                       if(!Next_Station){
                        String Next_station = last["name"];
                        SN = Next_station;
                        String Number = route1["no"];
                        SNo = Number;
                      Next_Station=true;
                       }
                         
                  }
                      
                      }
                                                                          
                }
}