## Pre-Lab preparation

1. Use schematic of the [Arduino Uno](https://oshwlab.com/tomas.fryza/arduino-shields) board and find out on which Arduino Uno pins the SDA and SCL signals are located.

    ![image](https://user-images.githubusercontent.com/99388246/200770550-44d8c874-0ae1-4421-b4d5-750a49cd793e.png)

2. Remind yourself, what the general structure of [I2C address and data frame](https://www.electronicshub.org/basics-i2c-communication/) is.

    Data is transferred between the master device and slave devices through a single SDA data line, via patterned sequences of 0’s and 1’s (bits). Each sequence of 0’s and 1’s is termed as a transaction and the data in each transaction is structured as below:

    ![image](https://user-images.githubusercontent.com/99388246/200770594-ea32e409-d3dd-4075-87e0-5d80b2d738e0.png))
