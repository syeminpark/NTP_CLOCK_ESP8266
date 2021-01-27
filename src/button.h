#ifndef button_h
#define button_h

ICACHE_RAM_ATTR void UpInterrupt()
{
    if (millis() - time2 > debounce)
    {
        time2 = millis();
        if (state != 2)
        {
            counter -= 1;
        }
        else if (state == 2 && counter == 1 && alarmCounter != 0)
        {
            upValue = true;
        }
        if (counter < 0)
        {
            counter = 2;
        }
    }
}

ICACHE_RAM_ATTR void DOWNInterrupt()
{
    if (millis() - time2 > debounce)
    {
        time2 = millis();
        if (state != 2)
        {
            counter += 1;
        }
        else if (state == 2 && counter == 1 && alarmCounter != 0)
        {
            downValue = true;
        }

        if (counter > 2)
        {
            counter = 0;
        }
    }
}

ICACHE_RAM_ATTR void ENTERInterrupt()
{
    if (millis() - time2 > debounce)
    {
        time2 = millis();

        state += 1;
        if (state > 2)
        {
            //알람 변경
            if (counter == 1)
            {
                alarmCounter += 1;
                if (alarmCounter > 2)
                {
                    alarmCounter = 0;
                }
            }
            state = 2;
        }
    }
}

ICACHE_RAM_ATTR void EXITInterrupt()
{
    if (millis() - time2 > debounce)
    {
        time2 = millis();

        if (state == 2 && counter == 1)
        {
            alarmCounter -= 1;
            if (alarmCounter < 0)
            {
                alarmCounter = 0;
                state -= 1;
            }
        }
        else
        {
            state -= 1;
            if (state < 0)
            {
                state = 0;
            }
        }
    }
}
#endif