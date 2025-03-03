#include <Arduino.h>
#include "LedControl.h"

const int LED_PIN = 13;

void initializeLed()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void setLedState(bool state)
{
    digitalWrite(LED_PIN, state ? HIGH : LOW);
}