# Lab 7: Martin Kováč

### Arduino Uno pinout

1. In the picture of the Arduino Uno board, mark the pins that can be used for the following functions/operations:
   * PWM generators from Timer0, Timer1, Timer2
   * analog channels for ADC
   * UART pins
   * I2C pins
   * SPI pins
   * external interrupt pins INT0, INT1

<img width="842" alt="Snímka obrazovky 2022-11-15 o 21 55 34" src="https://user-images.githubusercontent.com/99388246/202025954-f7703647-a07a-46c9-ac52-fa75c81a3041.png">

### I2C communication

2. Draw a timing diagram of I2C signals when calling function `rtc_read_years()`. Let this function reads one byte-value from RTC DS3231 address `06h` (see RTC datasheet) in the range `00` to `99`. Specify when the SDA line is controlled by the Master device and when by the Slave device. Draw the whole request/receive process, from Start to Stop condition. The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

   <img width="1440" alt="Snímka obrazovky 2022-11-15 o 21 55 56" src="https://user-images.githubusercontent.com/99388246/202026013-d753f3ad-308c-4e0d-bdf6-70dfb29a6184.png">


### Meteo station

Consider an application for temperature and humidity measurements. Use sensor DHT12, real time clock DS3231, LCD, and one LED. Every minute, the temperature, humidity, and time is requested from Slave devices and values are displayed on LCD screen. When the temperature is above the threshold, turn on the LED.

3. Draw a flowchart of `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) for such Meteo station. The image can be drawn on a computer or by hand. Use clear description of individual algorithm steps.

   ![IMG_4571](https://user-images.githubusercontent.com/99388246/202025824-35a91f1d-a143-4aee-a357-edf10d7adc44.jpg)
