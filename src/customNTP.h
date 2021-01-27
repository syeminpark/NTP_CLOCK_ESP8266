#ifndef customNTP_h
#define customNTP_h

void NTPDisplay()
{
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(20, 0);
    addZero(hh, mm, ss);
}

void NTPUpdate()
{

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK, WHITE);
    display.setCursor(30, 0);
    display.println(" NTP Update ");

    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(20, 20);
    if (WiFi.status() != WL_CONNECTED)
    {
        display.println("ERROR");
        display.println("WIFI IS DISCONNECTED");
    }
    else
    {
        display.print("Updating Server");
    }
    display.display();
    waitNTP(3000, 5000);
    state = 0;
}

#endif