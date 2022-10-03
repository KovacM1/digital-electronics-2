# Lab 1: Martin Kováč

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB0   // PB5 is AVR pin where green on-board LED 
                        // is connected
#define SHORT_DELAY 300 // Delay in milliseconds
#define PAUSE 200 // Delay in milliseconds
#define LONG_DELAY 600 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Generate a letter `A` Morse code

        // Change LED value
        digitalWrite(LED_GREEN, HIGH);
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_GREEN, LOW);
         _delay_ms(PAUSE);
        digitalWrite(LED_GREEN, HIGH);
        _delay_ms(LONG_DELAY);
        digitalWrite(LED_GREEN, LOW);
        _delay_ms(PAUSE);
        

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!
// dokreslit v simullde!

   ![Atmega schema](images/atmega_lab01.png)
