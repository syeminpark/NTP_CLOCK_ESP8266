#include "lib.h"

void setup()
{
  initialize();
  welcome();
  timeClient.begin();
  waitNTP(3000, 5000);
}

void loop()
{
  hh = timeClient.getHours();
  mm = timeClient.getMinutes();
  ss = timeClient.getSeconds();

  switchDisplay();
  display.display();
}
