 void getWeather(){
 
 HTTPClient http;    //Declare object of class HTTPClient
   DynamicJsonBuffer jsonBuffer;
   
   http.begin("http://dataservice.accuweather.com/currentconditions/v1/202439?apikey=GYpocjiLIX4Vb9RLeArUSc9jsDXY5Bku&details=true"); 
   /**  Note:
    Here 202439 is the location ID of my city (Vadodara).
    You have to change it according to your city. 
    Go to this link and enter your API Key and your city name. In the response body, look for "Key". That will be you Location key for the city that you have entered. 
    https://developer.accuweather.com/accuweather-locations-api/apis/get/locations/v1/cities/search
   
   http://api.football-api.com/2.0/matches?comp_id=1399&team_id=16110&from_date=20170101&to_date=20170505&Authorization=565ec012251f932ea4000001fa542ae9d994470e73fdb314a8a56d76
   http.addHeader("Content-Type", "application/json");  //Specify content-type header
   **/
   
   delay(200);
   int httpCode = http.GET(); //Send the request
   String payload = http.getString();   
   Serial.println(httpCode);   //Print HTTP return code 200 correct data 401 invalid data  404 Error
   //Serial.println(payload);    //Print request response payload
   JsonArray& root = jsonBuffer.parseArray(payload);
   
       if(!root.success()){
             Serial.println("Nope");
              }
  
            else{

/****************************** Get Temperature Data **********************************************/
              JsonObject& ALL=root[0];
              JsonObject& Temp=ALL["Temperature"];
              JsonObject& Metric = Temp["Metric"];
              String temp = Metric["Value"];
             
              Serial.print("Temp: ");
              Serial.print(temp);
              Serial.println(" * C");
/**************************************************************************************************/

/************************** How it actually feels like! **************************************/
              JsonObject& Feel=ALL["RealFeelTemperature"];
              JsonObject& MetricFeel = Feel["Metric"];
              String tempFeel = MetricFeel["Value"];

              Serial.print("Feels like: ");
              Serial.print(tempFeel);
              Serial.println(" * C");
/**************************************************************************************************/

/******************************* Get UV Index *******************************************************/              
              Serial.print("UV Index: ");
              String UV = ALL["UVIndex"];
              String desUV = ALL["UVIndexText"];
              Serial.print(UV);
              Serial.print(" | ");
              Serial.println(desUV);
              String atmos = ALL["WeatherText"];
              
              Serial.print("Weather: ");
              Serial.println(atmos);
/**************************************************************************************************/              
              
            }
 }
