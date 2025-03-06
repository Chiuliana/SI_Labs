#include "Globals.h"
volatile unsigned long lastTaskTime[3];
volatile bool buttonPressed = false;
volatile bool incButtonPressed = false;
volatile bool decButtonPressed = false;
volatile bool led1State = true;
volatile bool led2State = false;
volatile int counter = 5;