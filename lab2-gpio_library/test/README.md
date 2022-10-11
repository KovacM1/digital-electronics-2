# Lab 2: Martin Kováč

### GPIO control registers

1. Complete the table for DDRB and PORTB control register values.

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input  | no  | Tri-state, high-impedance |
   | 0 | 1 | input  | yes | pull-up activated         |
   | 1 | 0 | output | no  | low level                 |
   | 1 | 1 | output | yes | high level                |

### GPIO library

2. Complete the table with code sizes from three versions of the blink application.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style     | 480 |
   | Registers         | 176 |
   | Library functions | 176 |

### Traffic light

3. Scheme of traffic light application with one red/yellow/green light for cars, one red/green light for pedestrians, and one push button. Connect AVR device, LEDs, resistors, push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

<img width="937" alt="Snímka obrazovky 2022-10-11 o 19 02 44" src="https://user-images.githubusercontent.com/99388246/195154825-687a7eb1-7b76-476c-a0d3-ea8ee7a8cdc5.png">
