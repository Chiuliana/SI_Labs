#include "Led.h"
#include "Config.h"
#include "Globals.h"
#include <Arduino.h>
#include <stdio.h>

void run_led()
{
    int buttonReading = digitalRead(BUTTON_PIN);
    if (buttonReading == LOW)
    {
        if (!buttonPressed)
        {
            led1State = !led1State;
            digitalWrite(LED_1_PIN, led1State ? HIGH : LOW);
            printf("Button pressed! LED1 is now: %s\n", led1State ? "ON" : "OFF");
            buttonPressed = true;
        }
    }
    else
    {
        buttonPressed = false;
    }
    lastTaskTime[0] = millis();
}
