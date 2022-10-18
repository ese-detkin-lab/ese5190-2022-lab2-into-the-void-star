University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A


        Name: Sen Luo
        email: luosen@seas.upenn.edu
        Tested on: Razer Blade 15 (15-inch, 2020), Windows 10 21H2

# Part3 TALKING LEDS

## Brief responses to the reading questions in 3.2

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? 

Due to the timing uncertainty of actually entering an interrupt handler, the bit-banging become impractical. Another choice is to set the processor in a carefully times loop trying to make sure the GPIO reading and writing happens on the exact cycle required, which is really hard work. 

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  

LEDs and push buttons.

- How do you get data into a PIO state machine? 

The pull instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time.

- How do you get data out of a PIO state machine?

The out instruction here takes one bit from the data we just pull-ed from the FIFO, and writes that data to some pins.

- How do you program a PIO state machine? 

There are three things to consider here:
1. The state machine needs to be told which GPIO or GPIOs to output to. 
2. The GPIO also needs to be told that PIO is in control of it(GPIO function select)
3. If we are using the pin for output only, we need to make sure that PIO is driving the output enable line high. 

- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

```
pio_sm_put_blocking(pio, sm, 1):
```
After you set up everything correctly, the state machine will run autonomously,then the processor will push data directly into the state machine' TX FIFO. Writing 1 will turn the LED on, and writing a 0 will turn the LED off. 

- What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

The role of the pioasm assembler is to translating assembly code into binary. If Cmake functions want to interact with pioasm, you need take care of invoking pioasm and adding the generated header to the include path of the target TARGET for you. 

## 3.3 FOLLOW THE FLOW
For this part, I tried to describe the definition of the functions and their runing sequence.
### ws2812.c
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Lab%202%20Prob3/ws2812.c1.jpg)

![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Lab%202%20Prob3/ws2812.c2.jpg)

### ws2812.pio.h
![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Lab%202%20Prob3/ws2812.pio.h1.jpg)

![](https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Lab%202%20Prob3/ws2812.pio.h2.jpg)

## 3.4 COLOR BY NUMBER
For this part, I choose color 0X0000FF(BLUE).
https://github.com/SEN316/ese5190-2022-lab2-into-the-void-star/blob/main/Lab%202%20Prob3/part3.4%20-%20Sheet1.pdf
## 3.5 MODELING TIME

## 3.6 ZOOMING IN 

## 3.7 TIMING DIAGRAM
