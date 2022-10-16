University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

Part 3: Talking LEDs

3.2)

Q1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Ans: The laptop processor is not exactly designed for ‘bit-banging’. As processors have become faster in terms of overwhelming number-crunching brute force, the layers of software and hardware between the processor and the outside world have also grown in number and size. In response to the growing distance between processors and memory, PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks. That is why bit-banging is impractical to use on our laptops. 


Q2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

Ans: A GPIO is capable of running  general purpose software, which the PIO is not capable of doing. In this case, where the GPIO outweighs the PIO hardware. 


Q3. How do you get data into a PIO state machine?

Ans: From the transmit FIFO buffer, we take one data item and place it in the output shift register (OSR). This data moves one word at a time (32 bits) from the FIFO to the OSR. The OSR is capable of shifting its data out, one or more bits at a time to further destinations.


Q4. How do you get data out of a PIO state machine?

Ans: The state machine needs to be told which GPIO or GPIOs to output to. There are four different pin groups which are used by different instructions in different situations. The GPIO also needs to be told that PIO is in control of it (GPIO function select). PIO can drive the ‘output enable’ line up and down programmatically using certain instructions.


Q5. How do you program a PIO state machine

Ans: The RP2040 has two PIO blocks, each of them with four state machines. Each PIO block has a 32-slot instruction memory which is visible to the four state machines in the block. Our program needs to be loaded into this instruction memory before any of our state machines can run the program. Once the program is loaded, we find a free state machine and tell it to run our program. We can order multiple state machines to run the same program, or tell each state machine to run a different program. The state machine stalls if we don’t provide any data in the TX FIFO, for which it is waiting. We need to write a function to push the data into the TX FIFO. In this way, we can successfully program a PIO state machine.


Q6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

Ans: In the example, the `pio_sm_put_blocking()` function is responsible at the lowest level for telling the PIO to set the LED to a new color. It takes its input from the `pixel_rgb`. It falls within the `put_pixel()` function. The `put_pixel()` function takes its arguments from another function `urgb_u32()`, which defines the RGB values of the colors to be displayed on the LED. 

This function is being accessed using the `puts()` function. We pass `pattern_table[]` as an argument for this function. The pattern table lets us access various patterns in which we want our LEDs to blink. In each of these pattern functions, the `put_pixel` function is being calles. This leads to the color changing action which is required for our program to function.


Q7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

Ans: We use the pioasm tool to convert the assembler code to binary. We use the `CMake` function to invoke the pioasm and add the generated header to the include path of our target. The actual function being used it `pico_generate_pio_header(TARGETPIO_FILE)`. 
