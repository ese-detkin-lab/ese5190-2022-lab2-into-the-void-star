University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) Ying Xu
        (TODO) anniexu6@seas.upenn.edu
    Tested on: (TODO) MacBook Air(M1), macOS Big Sur version 11.6

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

##

3.2

• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Above certain speeds — say a factor of 1000 below the processor clock speed — IRQs become impractical, in part due to the timing uncertainty of actually entering an interrupt handler. 


• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

Whilst dealing with something like an LED string is possible using "bit-banging", once your hardware protocol gets faster to the point that it is of similar order of magnitude to your system clock speed, there is really not much you can hope to do. The main case where software GPIO access is the best choice is LEDs and push buttons.

• How do you get data into a PIO state machine?

Put data into the FIFO_TXn register of the PIO state machine.


• How do you get data out of a PIO state machine? 

The OSR is a staging area for data entering the state machine through the TX FIFO. Data is pulled fromthe TX FIFO into the OSR one 32-bit chunk at a time.


• How do you program a PIO state machine?

Running pioasm on the .pio file and ask it to spit out SDK code and configuring the PIO SM when using the program.


• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

pio_sm_put_blocking(pio,sm,data)

• What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

we can use it to build your PIO programs, for you to #include from your C or C++ program. pioasm can also be used directly, and has a few features not used by the C++ SDK, such as generating programs suitable for use with the MicroPython PIO library. And CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.

##

3.3 FOLLOW THE FLOW

ws2812.c
!https://github.com/real-YingXu/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812_c.pdf



ws2812.pio.h

!https://github.com/real-YingXu/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812_h.pdf



3.4 COLOR BY NUMBER









3.5 MODELING TIME

3.6 ZOOMING IN
















