#ifndef alarm_h
#define alarm_h

void AlarmStruc(int _alarmMin, int _alarmHour);

void alarm(boolean _AlarmMENU)
{
    static int AlarmHour = EEPROM.read(1);
    static int AlarmMin = EEPROM.read(2);

    switch (alarmCounter)
    {
    case 1:
        if (upValue)
        {
            AlarmHour += 1;
            if (AlarmHour >= 24)
            {
                AlarmHour = 0;
            }
        }
        else if (downValue)
        {
            AlarmHour -= 1;
            if (AlarmHour <= -1)
            {
                AlarmHour = 23;
            }
        }

        upValue = false;
        downValue = false;

        break;

    case 2:
        if (upValue)
        {
            AlarmMin += 1;
            if (AlarmMin >= 60)
            {
                AlarmMin = 0;
                AlarmHour += 1;
                if (AlarmHour >= 24)
                {
                    AlarmHour = 0;
                }
            }
        }
        else if (downValue)
        {
            AlarmMin -= 1;
            if (AlarmMin <= -1)
            {
                AlarmMin = 59;
                AlarmHour -= 1;
                if (0 > AlarmHour)
                {
                    AlarmHour = 23;
                }
            }
        }
        upValue = false;
        downValue = false;
        EEPROM.write(1, AlarmHour);
        EEPROM.write(2, AlarmMin);
        EEPROM.commit();
        AlarmHour = EEPROM.read(1);
        AlarmMin = EEPROM.read(2);
        break;
    }

    AlarmStruc(AlarmHour, AlarmMin);

    if (_AlarmMENU)
    {

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(BLACK, WHITE);
        display.setCursor(45, 0);
        display.println(" ALARM ");
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(38, 15);

        addZero(AlarmHour, AlarmMin, noSec);

        display.drawLine(AS_xpos[alarmCounter], 31, AS_xpos[alarmCounter] + 20, 31, WHITE);
    }
    else
    {

        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(20, 23);

        addZero(AlarmHour, AlarmMin, noSec);
        display.print("   ");
        addZero(hourResult, minResult, secResult);

        display.drawLine(0, 18, 128, 18, WHITE);
    }
}

void AlarmStruc(int _alarmMin, int _alarmHour)
{
    int minMinus = 1;

    secResult = 60 - ss;
    if (secResult == 60)
    {
        secResult = 0;
        minMinus = 0;
    }

    if (_alarmMin > mm)
    {

        minResult = _alarmMin - mm - minMinus;
        minMinus = 1;
        if (minResult < 0)
        {
            minResult = 59;
        }

        if (_alarmHour >= hh)
        {
            hourResult = _alarmHour - hh;
        }
        if (_alarmHour < hh)
        {
            hourResult = 24 + _alarmHour - hh;
        }
    }
    else if (_alarmHour <= mm)
    {
        minResult = (60 + _alarmMin) - mm - minMinus;
        minMinus = 1;

        if (_alarmHour <= hh)
        {
            hourResult = (24 + _alarmHour) - hh - 1;
        }
        if (_alarmHour > hh)
        {
            hourResult = _alarmHour - hh - 1;
        }
    }
}
#endif
