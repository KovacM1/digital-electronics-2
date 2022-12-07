### Team members:

* Martin Kováč 
  (responsible for programing encoder, joystick, flowchart diagram, editing video documentation)
* Lukáš Kudrna 
  (responsible for programing LCD display, creating video, hardware description and desing of README file)
##  Project assignment

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

## Goal of project

## GitHub repository structure

   ```c
   Project1       // PlatfomIO project
   ├── include         // Included files
           └── timer.h
   ├── lib             // Libraries
        └── gpio
              └── gpio.c
              └── gpio.h
        └── lcd
              └── lcd.c
              └── lcd.h
              └── lcd_definitions.h
        └── uart
              └── uart.c
              └── uart.h
   ├── src             // Source file(s)
   │   └── main.c
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```

## Hardware description

Insert descriptive text and schematic(s) of your implementation.

## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/                                                                         
2. https://www.electronicwings.com/arduino/analog-joystick-interfacing-with-arduino-uno                                                                    
3. https://github.com/tomas-fryza/digital-electronics-2
