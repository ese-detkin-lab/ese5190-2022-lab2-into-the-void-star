University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Nikola Obradovic
    Tested on: Surface Book 2

# 3
## 3.2
- Why is bit-banging impractical on your laptop, despite it having a
much faster processor than the RP2040?
  + The computer has many other processes running and the user program does not have any control over the scheduler. Maintaining accurate timing would be impossible. 
- What are some cases where directly using the GPIO might be a
better choice than using the PIO hardware?
  + If the GPIO is not frequently toggled, the overhead of a PIO program may not be necessary
- How do you get data into a PIO state machine?
  + You can write data to the FIFO buffer that is read by the SM. Having the PIO program read data in from a GPIO also gets data into the SM. You can also think of some of the SDK functions that set PIO parameter as "getting data into the state machine"
- How do you get data out of a PIO state machine?
  + Read from the RX FIFO. Having the PIO program write the data out to a GPIO pin also gets the data "out" of the state machine.
- How do you program a PIO state machine?
  + There are multiple SDK functions available that allow you to set SM parameters. PIO programs are written in the PIO assembly language and compiled into instructions that can be loaded into the PIO instruction registers.
- In the example, which low-level C SDK function is directly
responsible for telling the PIO to set the LED to a new color? How
is this function accessed from the main “application” code?
  + `pio_sm_put()` is called by `pio_sm_put_blocking()`, which is called by the application function `put_pixel()`
- What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?
  + pioasm generates the ws2812.pio.h file that contains the instructions that are loaded into the PIO SM. There is a CMake function defined that generates the header based on a provided `.pio` file (`pico_generate_pio_header()`)

## 3.3
[This PDF](section3/section3_3.pdf) contains the marked-up paper copies of the ws2812.c and ws2812.pio.h files. There is a mistake in the diagram drawn next to the `urgb_u32()` function: the empty/unused bits should be on the LSB side.
## 3.4
The first sheet in the [spreadsheet](section3/section3.xlsx) contains the initial states of the relevant PIO registers when the first color code is written to the TX FIFO. Registers were broken out into sections per the datasheet. Formulas were used to recombine the bits into the 32-bit hexadecimal value (also, check out the custom number format that adds the "0x" before the values. So convenient!).
## 3.5
The [paper model](section3/section3_5.pdf) shows the transmission of a single bit using the PIO program.
## 3.6
In progress (see sheet 2 of [the spreadsheet](section3/section3.xlsx))
## 3.7
In progress

## Section 3 reflection
I prefer to use paper as an informal, freeform design tool - quick sketches and notes. It does help visualize the information, but I get caught up in trying to make it look nice if there are formal requirements (since my handwriting is so bad). I am a big fan of Excel as an engineering design tool; I use it almost every day at work for purposes similar to what we did in section 3.4.
Other tools: I considered using the serial interface on the RP2040 to print the contents of various registers at different points in the program, but it would not be possible to do so and maintain the correct timings. It would be nice to find some kind of application that let you plot the signal timings, drag them around and define relationships between them.

# 4
My [test program](ndo_usb_ws2812/usb_ws2812.c) displays a "Hello World" message on the serial interface, and then accepts input from the user to control the light value. Sending 'r', 'g', 'b' or ' ' (space) will set the LED red, green, blue, or off, respectively. 
