University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

1)Why is bit-banging impractical on your laptop, despite it having a  much faster processor than the RP2040?
-PC-class processors keep hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks. Thus, bit - banging is impractical on a laptop despite it having much higher processor speeds.

2) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 
-A PIO state machine gets a lot more done in one cycle than a Cortex-M0+ when it comes to I/O: for example, sampling a GPIO value, toggling a clock signal and pushing to a FIFO all in one cycle, every cycle. However , a PIO state machine is not remotely capable of running general purpose software.

3) The instruction here takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time.

4) The state machine needs to be told which GPIO to output to depending on which pin group would be used ( out pin in this case) . Also , the GPIO needs to be told that the PIO is in control of it. Lastly , make sure that the PIO is driving the output enable line high.

5) The RP2040 has two PIO blocks, each of them with four state machines. Each PIO block has a 32-slot instruction memory which is visible to the four state machines in the block. We need to load our program into this instruction memory before any of our state machines can run the program. Once the program is loaded, we find a free state machine and tell it to run our program. 

6) This is done by the function * put_pixel() function*. This function takes its argument from another fucntion urgb_32() which converts the rgb values to rbg values which the PIO understands. At the lowest level , the **pio_sm_put_blocking** is responsible for setting a new color to the LED. The **puts()** function takes in a paramter and calls the **pattern_table[]** function. In each of the pattern functions called in the pattern_table[] fucntion , the *put_pixel()* function is called .

7) Within the SDK you do not need to invoke pioasm directly, as the CMake function *pico_generate_pio_header* takes care of invoking pioasm and adding the generated header to the include path of the target *TARGET* for you.

