#ifndef LCDOUTPUT_H
#define LCDOUTPUT_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdio.h>

extern LiquidCrystal_I2C lcd;

void initializeLCD();
int lcd_putchar(char c, FILE *stream);

#endif
