#ifndef menu_h
#define menu_h

void mainMenu()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK, WHITE);
    display.setCursor(90, 0);
    display.println(" MENU ");
    display.drawRect(0, MS_ypos[counter], 68, 9, WHITE);
    display.setTextColor(WHITE);
    display.println("-NTP Update");
    display.println("-Alarm");
    display.println("-Info");
}

void Info()
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK, WHITE);
    display.setCursor(50, 0);
    display.println(" Info ");
}

void switchDisplay()
{
    switch (state)
    {
    case 0:
        NTPDisplay();
        AlarmMenu = false;
        alarm(AlarmMenu);
        break;

    case 1:
        mainMenu();
        break;

    case 2:

        switch (counter)
        {
        case 0:
            NTPUpdate();
            break;

        case 1:
            AlarmMenu = true;
            alarm(AlarmMenu);
            break;

        case 2:
            Info();
            break;
        }
        break;
    }
}

#endif
