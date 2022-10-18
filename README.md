University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

```
Chenwei Tang
  email:tchenwei@seas.upenn.edu
  Linkedin:https://www.linkedin.com/in/chenwei-tang-3328a224b/
 Tested on: Legion Y7000, Windows 10 21H2
```
# Introduction
This lab guides us to gain practice with documentation, by taking careful notes and posting a setup guide on Github, then we would take a deep dive into the programmable I/O (PIO) module
# 3.3
The scans of my annotated code printouts(ws2812.c and generated/ws2812.pio.h) can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part3/3.3.pdf)
# 3.4
My spreadsheet of initial PIO register states can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part3/3.4.xlsx)
# 3.5
A photo or scan of my paper model can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part3/3.5.pdf)
# 3.6
My complete packet transmission spreadsheet can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part3/3.6.xlsx)
# 3.7
My complete packet transmission spreadsheet and polished timing diagram can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part3/3.6%263.7.png)
# 4
My working USB + WS2812 code folder can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/tree/main/Part4/pico-project)<br>
The gif of my code can be found [here](https://github.com/Chenwei-Tang/ese5190-2022-lab2-into-the-void-star/blob/main/Part4/part4.gif)
# Brief responses to the reading questions in 3.2
• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?<br>
The processor isn’t really designed for this. It has other work to do. As processors have become faster in terms of overwhelming number-crunching brute force, the layers of software and hardware between the processor and the outside world have also grown in number and size. In response to the growing distance between processors and memory, PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks.<br>
• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?<br>
LEDs and push buttons<br>
• How do you get data into a PIO state machine?<br>
The pull instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time. <br>
• How do you get data out of a PIO state machine?<br>
The state machine needs to be told which GPIO or GPIOs to output to. There are four different pin groups which are used by different instructions in different situations. The OSR is able to shift this data out, one or more bits at a time, to further destinations, using an out instruction. The out instruction here takes one bit from the data we just pull-ed from the FIFO, and writes that data to some pins.<br>
• How do you program a PIO state machine?<br>
A method ws2812_default_program_config configures a PIO state machine based on user parameters.<br>
• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code
```
typedef void (*pattern)(uint len, uint t); It is accessed by pattern_table[pat].pat(NUM_PIXELS, t);
```
