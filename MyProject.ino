#include <stdio.h>
#include "setup.h"
#include "City_ID.h"
#include "Display_Selector.h"
#include "FootballApi.h"
#include "Reminder.h"
#include "trainNo_Selector.h"
#include "ChangeConnection.h"
#include "clock.h"
//unsigned int i=0,j=0,check,k=1;

int sel;
void (* fun_sel[6])() = {ChangeWifi, getCityID, Live_score, reminder, WATCH_display, trainNo_Selector};
void setup() { 
  System_Init();
}

void loop() {
display.clear();
  server.handleClient();
  for(sel=0;sel<6;sel++){
   fun_sel[sel]();
   delay(1000);
  }
}

