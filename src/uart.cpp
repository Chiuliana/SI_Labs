#include "UART.h"

static FILE uartout = {0};
static FILE uartin = {0};

FILE *uart_stdout = &uartout;
FILE *uart_stdin = &uartin;

static int uart_putchar(char c, FILE *stream)
{
    Serial.write(c);
    return 0;
}

static int uart_getchar(FILE *stream)
{
    while (!Serial.available())
        ;
    return Serial.read();
}

void initializeUart()
{
    Serial.begin(9600);
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream(&uartin, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdout = &uartout;
    stdin = &uartin;
}