# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Ang Li
        E-mail: angliqd@seas.upenn.edu
    Tested on:
    Legion Y7000P IAH7 (15.6-inch 2022)
    -12th Gen Intel(R) Core(TM) i5-12500H 3.10 GHz
    -Windows 11 21H2 22000.1098
    -64-bit operating system, x64-based processor
    
# Part 3.2
* Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? 
    * If we use bit-banging there may produce lots of  communication errors，which means it is unreliable and backward for our laptop。
* What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
    * GPIOs are more suitable for less complex tasks such as input and output as well as analog I2C or SPI data lines, ADC voltage detection, output PWM waveforms, etc.
* How do you get data into a PIO state machine?
    * Get data into a PIO state machine via a FIFO queue, which can exchange data with the main program. 
* How do you get data out of a PIO state machine?
    * By using ‘pull’ instruction to take data.
* How do you program a PIO state machine?
    * Use PIO assembly language
* In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
    * "pio_sm_put_blocking". Write data to the TX FIFO queue.If the TX FIFO queue is full then block it.
* What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
    * Its responsibility is to compile the assembly code into a human readable format.
# Part 3.3
Please check [this file](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/blob/c14eceb35c38d918b2db69ddecf0a25b496b9bbe/part3.3.pdf)

# Part 3.4
Please check [this file](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/blob/c14eceb35c38d918b2db69ddecf0a25b496b9bbe/part3.4.xlsx)

# Part 3.5
![alt](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/blob/d0e7c30c7e524fdeda398c277f7bdd0d4c59232f/part3.5.png)


# Part 3.6
Please check [this file](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/blob/b4767c917af17fb11938fe2cc508e517b1fa5476/part3.6.xlsx) 

# Part 3.7
![alt](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/blob/c14eceb35c38d918b2db69ddecf0a25b496b9bbe/part3.7.png)

# Part 4
Please check the folder in [this link](https://github.com/AngLi-00/ese5190-2022-lab2-into-the-void-star/tree/main/part4) , which contains all of the code to make LED blink and change color while sending "Hello World".
