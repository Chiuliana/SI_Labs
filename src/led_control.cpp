// led_control.cpp
#include "led_control.h"
#include <stdio.h>

static bool ledState = false;

void initLed() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    printf("LED initialized on pin %d\n", LED_PIN);
}

void setLedState(bool state) {
    ledState = state;
    digitalWrite(LED_PIN, state ? HIGH : LOW);
}

bool getLedState() {
    return ledState;
}