University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Prateek Bashista
    Tested on: HP Pavillion Gaming Ryzen 5 4600H CPU, 16GB RAM

(TODO: Your README)


PART 3: TALKING LEDS

3.2 PIO

Q1) Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Ans) Akthoughs PCs these days are faster in speed, bit banging is not practical for them anymore. This is because , the layers and size between hardware and software have rapidly increased with developments.Additonally, Modern PCs keep hundreds of instructions inflight at any point of time , which makes it hard for the PC to switch between real time tasks, thus increasing the latency.
Q2) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 

The PIO hardware is relatively not equipped to run complex general purpose software implmentations. For cases in the implmentation of SDIO and DPI video editing, better route is going GPIO as we may end up using 2-3 of our PIO state machines.

Q3) How do you get data into a PIO state machine? 

The data in the FIFO buffers is transferred to the Output Shift Register (OSR) which is the holding place for the input to PIO state machine oen word (32 Bit) at time. The data from the OSR is mapped to the ins one bit at time.

Q4) How do you get data out of a PIO state machine?

1) First, the output GPIO pins are defined.
2) It is defined that the PIO hardware is the controllling hardware.
3) We then set the direction of the previously defined pin to OUTPUT to mantaint he flow of data.

Q5) How do you program a PIO state machine?

1) We set which PIO instance needs to be used. We have 2 PIO instances available for our use. Each block has 4 state machines.
2) We need to load our program in PIO instruction memory before any state machine can run it. pio_add_program finds free slot for our instructions in PIO'S instruction memory.
3) Once instruction is loaded, a free state machine is searched for and if found, it is instructed to run our program. Each state machine can be instructed to run a different program given memory limit is not reached.

Q6) In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

1) pio_sm_put_blocking() function is responsible for setting the led to new colour whenever a new value is passed. It takes a 32 bit hex code converted to GRB by urgb_u32() function and shifts it by 8 bits.
2) The pattern table function inside the main code has definitions for different patterns. These pattern functions calls the put_pixel() function which contains the pio_sm_put_blocking() function.
main() -> pattern_tables() -> pattern_() -> put_pixel() -> pio_sm_put_blocking()

Q7) What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

