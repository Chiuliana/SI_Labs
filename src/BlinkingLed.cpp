#include "BlinkingLed.h"
#include "Config.h"
#include "Globals.h"
#include <Arduino.h>
#include <stdio.h>

void run_blinking_led()
{
    if (!led1State)
    {
        led2State = !led2State;
        digitalWrite(LED_2_PIN, led2State ? HIGH : LOW);
    }
    else
    {
        digitalWrite(LED_2_PIN, LOW);
    }
    lastTaskTime[1] = millis();
}

void run_blinking_led_buttons()
{
    bool incButtonState = digitalRead(BUTTON_INC_PIN) == LOW;
    bool decButtonState = digitalRead(BUTTON_DEC_PIN) == LOW;
    if (incButtonState && !incButtonPressed)
    {
        if (counter < 60)
        {
            counter++;
            printf("Blink count increased to: %d\n", counter);
        }
        incButtonPressed = true;
    }
    else if (!incButtonState && incButtonPressed)
    {
        incButtonPressed = false;
    }
    if (decButtonState && !decButtonPressed)
    {
        if (counter > 1)
        {
            counter--;
            printf("Blink count decreased to: %d\n", counter);
        }
        decButtonPressed = true;
    }
    else if (!decButtonState && decButtonPressed)
    {
        decButtonPressed = false;
    }
    lastTaskTime[2] = millis();
}