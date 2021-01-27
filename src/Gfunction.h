#ifndef Gfunction_h
#define Gfunction_h

void wait()
{
    waitFin = true;
}

void addZero(int _hour, int _min, int _sec = 61)
{
    int array[3] = {_hour, _min, _sec};
    int timeLength = sizeof(array) / sizeof(int);
    if (_sec == 61)
    {
        timeLength -= 1;
    }

    for (int i = 0; i < timeLength; i++)
    {
        if (array[i] < 10)
        {
            display.print("0");
        }
        display.print(array[i]);
        if (i < timeLength - 1)
        {
            display.print(":");
        }
    }
}

void waitNTP(int _sucDelay, int _failDelay)
{
    if (timeClient.update())
    {
        delay(_sucDelay);
    }
    else
    {
        stopper.attach_ms(_failDelay, wait);
        while (!timeClient.update())
        {
            timeClient.forceUpdate();
            if (waitFin)
            {
                stopper.detach();
                waitFin = false;
                break;
            }
        }
    }
}

void initialize()
{
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(EXIT, INPUT);

    attachInterrupt(digitalPinToInterrupt(UP), UpInterrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(DOWN), DOWNInterrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(ENTER), ENTERInterrupt, FALLING);
    attachInterrupt(digitalPinToInterrupt(EXIT), EXITInterrupt, FALLING);

    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        printf(".");
    }
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
}
void welcome()

{

    display.clearDisplay();
    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(30, 0);
    display.println("Syemins");
    display.setCursor(30, 17);
    display.println(" Clock");
    display.display();
}

#endif