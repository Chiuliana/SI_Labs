#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "KeypadInput.h"
#include "LCDOutput.h"

void initializeKeypadLcd()
{
    initializeLCD();

    static FILE lcdout;
    static FILE kpdin;

    fdev_setup_stream(&lcdout, lcd_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream(&kpdin, NULL, keypad_getchar, _FDEV_SETUP_READ);

    stdout = &lcdout;
    stdin = &kpdin;
}

void setup()
{
    initializeKeypadLcd();
    printf("Enter Password: ");
}

void loop()
{
    char input[17];
    scanf("%16s", input);

    printf("\n");
    if (strcmp(input, "007D") == 0)
    {
        printf("Access Granted");
    }
    else
    {
        printf("Wrong Password");
    }

    delay(2000);
    lcd.clear();
    printf("Enter Password: ");
}
