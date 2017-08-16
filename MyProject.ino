#include "setup.h"
#include "City_ID.h"
#include "Display_Selector.h"
#include "FootballApi.h"
#include "Reminder.h"
#include "trainNo_Selector.h"

//unsigned int i=0,j=0,check,k=1;

void setup() {  
  System_Init();
}
void loop() {
   display.clear();
    server.handleClient();
    Live_score();
}

