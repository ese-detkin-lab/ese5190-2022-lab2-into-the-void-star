University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A


        Name: Sen Luo
        email: luosen@seas.upenn.edu
        Tested on: Razer Blade 15 (15-inch, 2020), Windows 10 21H2

# Part3 TALKING LEDS

## Brief responses to the reading questions in 3.2

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? 

        Due to the timing uncertainty of actually entering an interrupt handler, the bit-banging become impractical. Another choice is to set the processor in a carefully times loop trying to make sure the GPIO reading and writing happens on the exact cycle required, which is really hard work. 

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  

- How do you get data into a PIO state machine? 

- How do you get data out of a PIO state machine?

- How do you program a PIO state machine? 

- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

- What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 
