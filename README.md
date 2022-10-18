University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Minghui Ni
    Tested on: Windows 11

`./lab2A_code`  contains Q4 code

## 3.2 Questions

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Answer: The modern laptop or PC processors are fast enough to support thousands of instructions on a core in parallel. Thus, it is more suitable for some task with large computation volume and not suitable for the real time execution with a small set of instructions.

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 

Answer: Since PIO needs user to program the IO port, it is more suitable for some complicated task. The GPIO can only take some tasks like output voltage, reading input voltage. Thus, for some simple tasks, GPIOs are easier to use.

- How do you get data into a PIO state machine?

Answer: Well, after we saved the data to the TX FIFO, it will transmit the data automatically to the Output Shift Register(OSR) after a threshold if you set the auto-pull on. Then the OSR will follow the PIO program to pull data from either the Most Significant Bit or the Least Significant Bit based on the configuration. Then the PIO state machine can get the data pulled from the OSR.

- How get data out?

Answer: Getting data out is actually the reverse process of sending data in but with using the RX FIFO and  the Input Shift Register(ISR)

- How do you program state machine?

Answer: PIO ASM

- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?

Answer: `pio_sm_put_blocking()`

- What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
  - The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040
  - the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target application

## 3.3 Follow the flow

[ws2812.c](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/Annotated_Code_Printout_3.3_ws2812_C.pdf)

[ws2812.pio.h](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/Annotated_Code_Printout_3.3_ws2812_C.pdf)



## 3.4 Color By Number

The color instruction I choose is #808080

All reserved bits are set to be zero

All bits which are not configured by the program are set as the reset value.

Here is the link to the spreadsheet: [spreadsheet_of_3.4](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/spreadsheetESE5190_Lab2A_3.4with3.6.xlsx)



## 3.5 Modeling the Time

As for the WS2812 protocol, its input contains two different patterns of voltage: "short positive" and "long positive". As these so-called names show us, the short positive patter has only 2 cycles having high voltage input and it will be recognized as a 0 bit. On the contrary, the long positive pattern will has 7 cycles having high voltage input and it will be recognized as a 1 bit.



The pio program will pull a bit from OSR, and rise the side-set pin's voltage and then ,based on the bit value, choose to either have low voltage output or the high voltage output. This pio program performance matches the requirement of the WS2812 protocol. Thus, it works. The time model is shown in this file: [Time Model](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/paper_model_3.5.pdf)



## 3.6 Complete Packet Transmission Spreadsheet

Please check out the second inner sheet of this spreadsheet: [spreadsheet of 3.6](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/spreadsheetESE5190_Lab2A_3.4with3.6.xlsx)



## 3.7 Polished Timing Diagram

Please check out the Timing Diagram : [diagram of 3.7](https://github.com/minghuin/ese5190-2022-lab2-into-the-void-star/blob/main/polished_timing_diagram_3.7.pdf)



## Reflect on the Tools

paper-strength: clear and easy to follow

paper-weakness: need to write carefully if you want a good surface.

Spreadsheets-strength: arranged and formulated

Spreadsheets-weakness: a little messy when you want to find something. Need to consider its setup format.



I used ipad for paper writing. it  removes all the weakness brought by the paper.



## Comment

I worked with **Yizhe Wang**, we spent several days in the detkin lab for this lab. We do learn a lot from it.

I referred **Junpeng Zhao**'s readme file for format and some questions. 
