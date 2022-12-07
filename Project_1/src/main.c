/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components list:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 6)
 *     D7   - PD7 (Data bit 7)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

static uint8_t counter = 0;
static uint8_t aState = 0;
static uint8_t aLastState = 0;

#define outputA PB3
#define outputB PB4
/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    GPIO_mode_input_nopullup(&DDRB, outputA);
    GPIO_mode_input_nopullup(&DDRB, outputB);

	aLastState = GPIO_read(PINB, outputA);

    // Initialize display
    lcd_init(LCD_DISP_ON_CURSOR);

    // Put string(s) on LCD screen
    // lcd_gotoxy(6, 1);
    // lcd_puts("LCD Test");
    // lcd_putc('!');

    lcd_gotoxy(1, 0);
    lcd_puts("X:");

	 lcd_gotoxy(3, 0);
    lcd_puts("0000");

    lcd_gotoxy(8, 0);
    lcd_puts("Y:");

    lcd_gotoxy(10, 0);
    lcd_puts("0000");

    lcd_gotoxy(1, 1);
    lcd_puts("ENKODER:");

    // Set back light at PB2
    GPIO_mode_output(&DDRB, PB2);
    // GPIO_write_low(&PORTB, PB2);
    GPIO_write_high(&PORTB, PB2);

    // Configuration of 8-bit Timer/Counter2 for Stopwatch update
    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
	static uint8_t value = 0;
	static uint8_t string = 0;

    aState = GPIO_read(PINB, PB3); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (GPIO_read(PINB, PB3) != aState) { 
       counter ++;
     } else {
       counter --;
     }
	counter = value;
    itoa(value,string,10);
	lcd_gotoxy(9, 1);
    lcd_puts(string);

   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state        

    
    // Else do nothing and exit the ISR
}