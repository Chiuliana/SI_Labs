#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

extern volatile unsigned long lastTaskTime[3];
extern volatile bool buttonPressed;
extern volatile bool incButtonPressed;
extern volatile bool decButtonPressed;
extern volatile bool led1State;
extern volatile bool led2State;
extern volatile int counter;

#endif