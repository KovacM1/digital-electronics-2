/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
#define BUTTON PD0      // External button 
#define SHORT_DELAY 250 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops
#include <gpio.h>

// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
//#include "Arduino.h"
#define LED_GREEN  13   // PB5 is AVR pin where green on-board LED
                        // is connected
#define BUTTON   0


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pin where on-board LED is connected as output
    GPIO_mode_output(&DDRB, LED_GREEN);  // Set output mode in DDRB reg
    GPIO_mode_input_pullup(&DDRD, BUTTON); 
    // Infinite loop
    while (1)
    { 
      _delay_ms(SHORT_DELAY);
      GPIO_read(&PIND, BUTTON);
      // Change LED value
        if (BUTTON == 1)
          {
            // Set pin(s) to HIGH
            GPIO_write_low(&PORTB, LED_GREEN);
            _delay_ms(SHORT_DELAY);
            GPIO_write_high(&PORTB, LED_GREEN);
          }
        else
          {
            // Set pin(s) to LOW
            GPIO_write_high(&PORTB, LED_GREEN);
          }
    }
    // Will never reach this :)
    return 0;
}