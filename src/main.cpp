// main.cpp
#include <Arduino.h>
#include <stdio.h>
#include "led_control.h"

#define BAUD_RATE 9600
#define BUFFER_SIZE 32

// Create FILE structure for stdin and stdout
static FILE uartout = {0};
static FILE uartin = {0};

// UART output function
static int uart_putchar(char c, FILE* stream) {
    Serial.write(c);
    return 0;
}

// UART input function
static int uart_getchar(FILE* stream) {
    while (!Serial.available());
    return Serial.read();
}

void setup() {
    // Initialize serial communication
    Serial.begin(BAUD_RATE);
    
    // Set up stdout and stdin
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream(&uartin, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdout = &uartout;
    stdin = &uartin;
    
    // Initialize LED
    initLed();
    
    // Print welcome message
    printf("LED Control System Ready\n");
    printf("Available commands:\n");
    printf("- led on  : Turn LED on\n");
    printf("- led off : Turn LED off\n");
}

void loop() {
    char command[BUFFER_SIZE];
    printf("Enter command: ");
    
    // Read command using scanf
    if (scanf("%31s", command) == 1) {  // Read max 31 chars to leave room for null terminator
        if (strcmp(command, "led") == 0) {
            char state[5];  // "on" or "off" plus null terminator
            if (scanf("%4s", state) == 1) {
                if (strcmp(state, "on") == 0) {
                    setLedState(true);
                    printf("Command confirmed: LED turned ON\n");
                }
                else if (strcmp(state, "off") == 0) {
                    setLedState(false);
                    printf("Command confirmed: LED turned OFF\n");
                }
                else {
                    printf("Invalid state. Use 'on' or 'off'\n");
                }
            }
        }
        else {
            printf("Unknown command. Use 'led on' or 'led off'\n");
        }
        
        // Clear any remaining characters in the input buffer
        while (getchar() != '\n' && getchar() != '\r');
    }
}