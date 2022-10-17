University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

Saurabh Sandeep Parulekar
   LinkedIn: https://www.linkedin.com/in/saurabh-parulekar/
Tested on: HP Pavillion Gaming Laptop, Windows 10 21H2

## Use of PIO module on RP2040

```
1) Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
   In today Pc although the processing power is much greater than RP2040, the layers of software and hardware between the processor and the outside world have also grown in number and size. Therefore it is difficult to obtain precise timing for hard real time applications. Incase of RP2040, it has a dedicated hardware called as the PIO, which runs separately, and hence it makes more sense to do bit-banging on this small microcontroller.

2) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
   In cases where a precise timed signals are not required, such that sufficiently correct timing to an external hardware still makes it understand the signals. GPIO can be used for controlling things which need discrete signals and do not depend on hard and fast timing such as status Leds. It can be also used in a closed loop system such as PWM to motor Control.

3) How do you get data into a PIO state machine?
   To put data into the PIO state machine we need to put data into the FIFO_TXn register of that particular PIO state machine. We do this in the C file, we can directly push data by using the helper function “pio_sm_put_blocking()”. This function checks if the FIFO is full and waits to put data into it till it gets empty.

4) How do you get data out of a PIO state machine? 
   To get data out of the PIO state machine, we need to first write a pio code, in which when we execute a “out” statement, the data is written to the particular pin mentioned in that statement.

5) How do you program a PIO state machine?
   To program a PIO state machine we need to make a .pio file, using the assembly instructions given in the RP2040 datasheet we can program the precise pin behaviour we need. Once we program the behaviour we need add the configuration of the state machine in that same file(eg. Which state machine, which PIO etc). Then we need to edit the Cmake file and “ico_generate_pio_header()” to generate a .pio.h file which can be used in the C code to send data to the State machine.

6) In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
   pio_sm_put_blocking(pio,sm,data) is a helper function which is directly responsible for telling the PIO to set LED to a new color. This function is accessed through the inline “put_pixel(data)” function.

7) What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
   When we run the Pioasm, it will it will create some static variables describing the program, and a method ws2812_default_program_config which configures PIO state machine based on user parameters, and the directives in the actual PIO program. To invoke the pioasm we need to call “pico_generate_pio_header” which will create an “.h” header file, which is already included in out code.
```
