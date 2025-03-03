#ifndef UART_H
#define UART_H

#include <Arduino.h>
#include <stdio.h>

void initializeUart();

extern FILE *uart_stdout;
extern FILE *uart_stdin;

#endif