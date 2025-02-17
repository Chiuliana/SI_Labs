// led_control.h
#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>

// LED pin definition
#define LED_PIN 13  // Using built-in LED for demonstration

// Function declarations
void initLed();
void setLedState(bool state);
bool getLedState();

#endif