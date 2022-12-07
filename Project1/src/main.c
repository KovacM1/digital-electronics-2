/***********************************************************************
 * 
 * Use Analog-to-digital conversion to read push buttons on LCD keypad
 * shield and display it on LCD screen.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions



// Definovanie pripojenia pinov encodera
#define CLK PB2
#define DT PB3

//Premenne pre encoder
static int8_t counter = 0; 
static uint8_t aState;
static uint8_t aLastState;

// Premenne pre joystick
static uint8_t intCounter = 0;


int main(void)
{
    GPIO_mode_input_nopull(&DDRB,CLK);
    GPIO_mode_input_nopull(&DDRB,DT);

    aLastState = GPIO_read(&PINB,CLK);

    // Inicializacia displeja
    lcd_init(LCD_DISP_ON);

  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX = ADMUX | (1<<REFS0);
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM1_overflow_4ms();
    TIM1_overflow_interrupt_enable();
    TIM0_overflow_33ms();
    TIM0_overflow_interrupt_enable();
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {

    }

    return 0;
}

ISR(TIMER1_OVF_vect)
{
  /* ADC conversion */
  ADCSRA |= (1<<ADSC);
}

ISR(TIMER0_OVF_vect)
{

  char string[4];
  //Citanie aktualneho stavu CLK pinu
  aState = GPIO_read(&PINB,CLK);

  lcd_gotoxy(0, 1);
  lcd_puts("ENKODER:");

  // Cyklus pre citanie hodnoty encodera
  if (aState != aLastState){

    if (GPIO_read(&PINB,DT) != aState) {
      counter ++;
    }
    else {
      counter --;
    }

    //Podmienka nepresiahnutia hodnoty 20
    if(counter  > 20)
      counter = 20;
    else if (counter  < 0)
    {
      counter = 0;
    }
    //Vypis hodnoty enkodera
    itoa(counter, string, 10);
    lcd_gotoxy(10, 1);
    lcd_puts("     ");
    lcd_gotoxy(10, 1);
    lcd_puts(string);
  }

  aLastState = aState;

}

// Cyklus pre citanie pozicie jyosticku
ISR(ADC_vect)
{
  char charX[4];
  char charY[4];
  uint16_t valueX;
  uint16_t valueY;
  uint8_t channel = 0;


  static int8_t nooverflow = 0;
  nooverflow++;
  if(nooverflow > 3)
  {
    nooverflow = 0;
    intCounter++;
  }
  
  /* address shifting ADMUX -----------------------------------------*/

  if (channel == 0){
    // Select input channel ADC0 (voltage divider pin)
    ADMUX = ADMUX & ~( 1<<MUX3 | 1<<MUX2 | 1<<MUX0 | 1<<MUX1);
    ADCSRA |= (1<<ADSC);
    valueX = ADC;

    itoa(valueX, charX, 10);
    lcd_gotoxy(0,0);
    lcd_puts("       ");
    lcd_gotoxy(0,0);
    lcd_puts("X:");
    lcd_gotoxy(2,0);
    lcd_puts(charX);

    channel = 1;
  }
  if (channel == 1){
    // Select input channel ADC1 (voltage divider pin)
    ADMUX &= ~((1<<MUX3 | 1<<MUX2 | 1<<MUX1)); ADMUX |= (1<<MUX0);
    ADCSRA |= (1<<ADSC);
    valueY = ADC;
    
    itoa(valueY, charY, 10);
    lcd_gotoxy(7,0);
    lcd_puts("       ");
    lcd_gotoxy(7,0);
    lcd_puts("Y:");
    lcd_gotoxy(9,0);
    lcd_puts(charY);

    channel = 0;
  }
  
}