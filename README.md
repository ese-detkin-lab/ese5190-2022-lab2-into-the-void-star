University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Sugata Sen, worked with Harish Ramesh
    https://www.linkedin.com/in/sugata-sen/, https://www.linkedin.com/in/harishramesh1998/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
## 3.2 : Answers to the Reading related questions

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

    - In bit banging, we effectively emulate a peripheral using software signals. Even though a laptop has high processing power than the RP2040, for timings which occur at rates much slower than processor clock speed, it is tough to implement accurately the real time peripheral IO by bit banging on laptop. The bit banging is practical for the rp2040 as it is easy to implement using the PIO module.

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

    - GPIO is usually better for simpler use cases, like driving single pin outputs etc, for example for direct pulse control of a pin like for LED blinking. PIO is useful when there is repeated R/W of information and temporal accuracy is of importance.

- How do you get data into a PIO state machine?

    - The data flow is mentioned in the datasheet when it explains the Ooutput shift register and FIFO functionality. The data goes into the PIO state machine through a FIFO queue. In fact the “pull” instruction loads data from the TXFIFO to OSR (32 bits).

- How do you get data out of a PIO state machine?

    - The "out" instruction can be used to shift data from the Input Shift Register into RXFIFO. From there we can get output via a pin if required.

- How do you program a PIO state machine?

    - A .pio program elaborates how the PIO state machine must work. It is made of instructions: JMP, WAIT, IN, OUT, PUSH, PULL, MOV, IRQ, and SET. Thus the assembly language can be used to program a pio state machine.

- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

    - pio_sm_put_blocking() is used to block the FIFO, if it is full, and acts as a flag. It also allows writing data to the TX FIFO queue if vacant. 

    - The function is accessed by calling the put_pixel() in the main code.

- What role does the pio asm “assembler” play in the example, and how does this interact with CMake?

    - This pioasm processes a PIO assembly input text file. This can have multiple programs, and creates assembled code. The assembled code is visible in form of C headers. The cmake function pico_generate_pio_header(TARGET PIO_FILE) invokes the pioasm. 


## 3.3 Follow the flow
https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/AnnotationStuffpart%203.3.pdf

## 3.4 Color by number
I found the answers to the clue questions by scouringthe program and calculating time from datasheet.

1.	Which PIO instance is being used?  Pio0

2.	Which state machine is being used with this PIO instance? sm0

3.	Which pin is this state machine configured to control? (you can  either use settings from the example program, or for the Qt Py  LED pin yours will be connected to) : To the pin 2 by default, and we configured this to work with pin 11

4.	How long is this state machine’s clock cycle? 0.8 MHz

5.	How much is this state machine’s clock scaled down relative to the system clock? (i.e. the “clock divisor”)  133/8 = 16.625

6.	In which direction will this state machine shift bits out of its  “output shift register”? LSB first (right shift)


https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/ESE_519_lab_2a_3.4.xlsx

## 3.5 Modelling Time
https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/Part3.5.pdf

## 3.6 & 3.7 Zooming In and Timing Diagram
https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/ese_519_lab2a_3_6_7.xlsx

For the timing diagram in 3.7, we have mentioned the value of the clock at clock cycle period and mentioned the value at each time instant. Graphically representing the clock was becoming tedious after starting it.

## Hello Blinkenlight
The final codes have been added in a nested directory called "The Final Code folder",and linked below for ease of viewing:
C code: https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/The%20Final%20Code%20folder/ws2812.c
PIO Header file: https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/The%20Final%20Code%20folder/generated/ws2812.pio.h



### Output
![](https://github.com/sugahiraeth/ese5190-2022-lab2-into-the-void-star/blob/36518f5be5dad070610266429e872d5c1c16442f/op.gif)

## Brief Responses to questions raised in into the (void):
