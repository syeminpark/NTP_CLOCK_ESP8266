#ifndef Gvar_h
#define Gvar_h

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1

#include <Ticker.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.bora.net", 3600 * 9, 60000);
Ticker stopper;

const char *ssid = "TP-Link_F1F2";
const char *password = "85510432";

String arr_days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String date_time; // You can specify the time server pool and the offset (in seconds, can be // changed later with setTimeOffset() ). Additionaly you can specify the // update interval (in milliseconds, can be changed using setUpdateInterval() ).

const int UP = 14;
const int DOWN = 12;
const int ENTER = 13;
const int EXIT = 15;

int counter = 0;
int alarmCounter = 0;
boolean upValue = false;
boolean downValue = false;

boolean AlarmMenu = false;
boolean waitFin = false;

int noSec = 61;

const int debounce = 200;
unsigned long time2 = 0;
//main menu square
int MS_ypos[3] = {7, 15, 23};
//alarm menu square
int AS_xpos[3] = {-21, 38, 74};

int state = 0;
int subMenu;

int hh;
int mm;
int ss;

int secResult;
int minResult = 0;
int hourResult = 0;


#endif
