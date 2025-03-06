#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "Globals.h"
#include "Config.h"
#include "Led.h"
#include "BlinkingLed.h"

void setup()
{
    void initializeUart();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
    pinMode(BUTTON_INC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DEC_PIN, INPUT_PULLUP);
    unsigned long currentTime = millis();
    lastTaskTime[0] = currentTime + TASK1_OFFSET;
    lastTaskTime[1] = currentTime + TASK2_OFFSET;
    lastTaskTime[2] = currentTime + TASK3_OFFSET;
    digitalWrite(LED_1_PIN, led1State);
    digitalWrite(LED_2_PIN, led2State);
}

void loop()
{
    unsigned long currentTime = millis();
    if (currentTime - lastTaskTime[0] >= TASK1_RECURRENCE)
    {
        run_led();
    }
    if (currentTime - lastTaskTime[1] >= TASK2_RECURRENCE / counter)
    {
        run_blinking_led();
    }
    if (currentTime - lastTaskTime[2] >= TASK3_RECURRENCE)
    {
        run_blinking_led_buttons();
    }
}