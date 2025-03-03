#include "LCDOutput.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with I2C address 0x27

void initializeLCD()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

int lcd_putchar(char c, FILE *stream)
{
    if (c == '\n')
    {
        lcd.setCursor(0, 1);
        return 0;
    }
    lcd.write(c);
    return 0;
}
