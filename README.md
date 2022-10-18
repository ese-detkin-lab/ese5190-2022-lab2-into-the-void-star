University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Sizhe Ma
    Tested on: Thinkpad X1, Windows 10 Pro, Intel(R) Core(TM) i7-8650U CPU @ 1.90GHz   2.11 GHz

## Lab Writeup

### 3.2 PIO Questions
• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?、

The custom hardware components take care of specific tasks that the more general multi-tasking CPU is not designed for.

• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  

Whilst dealing with something like an LED string is possible using "bit-banging", once your hardware protocol gets faster
to the point that it is of similar order of magnitude to your system clock speed, there is really not much you can hope to
do. The main case where software GPIO access is the best choice is LEDs and push buttons.

• How do you get data into a PIO state machine? 

Put data into the FIFO_TXn register of the PIO state machine.

The ```pull``` instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time

• How do you get data out of a PIO state machine? 

The OSR is able to shift this data out, one or more bits at a time, to further destinations, using an ```out``` instruction

The OSR is a staging area for data entering the state machine through the TX FIFO. Data is pulled fromthe TX FIFO into the OSR one 32-bit chunk at a time.

• How do you program a PIO state machine? 

There are two ways to program a PIO state machine: using C++ SDK or directly from MicroPython.

• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

```
pio_sm_put_blocking(pio,sm,data)
```

• What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

We can use it to build your PIO programs, for you to ```#include``` from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library.

And CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.

### 3.3 Follow the Flow

[ws2812.c](https://github.com/MaxMa6150/ese5190-2022-lab2-into-the-void-star/blob/main/3.3_ws2812_c.pdf)

[ws2812.pio.h](https://github.com/MaxMa6150/ese5190-2022-lab2-into-the-void-star/blob/main/3.3_ws2812_h-1.pdf)

### 3.4 Color by Number
We choose the color blue with value 0x00ff00：
Here is the [list of register](https://github.com/MaxMa6150/ese5190-2022-lab2-into-the-void-star/blob/main/RegisterList_3.4.xlsx).
![fb3e222239a723a8a36987e85852102](https://user-images.githubusercontent.com/114200453/196376939-99f629ac-f8f1-49f3-88db-3354cfd0c025.jpg)


### 3.5 Modeling Time
The model/chart with the code is attached below:
![e0b00783580c2c6e7955fce979ce67e](https://user-images.githubusercontent.com/114200453/196373103-88f8a259-ec6f-437a-9601-0142a0195496.jpg)

As shown in the model, 10 SM clock cycles take place from when color data is written to the FIFO up until the first full bit is sent, and make a numbered column for each time window.







