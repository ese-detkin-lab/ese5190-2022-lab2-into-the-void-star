University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Chenye Xiong
        Email: xcyxcy@seas.upenn.edu
    Tested on: MacBook Pro (13-inch, M2, 2022), macOS Monterey 12.6

(Chenye Xiong)

## Brief responses to the reading questions in 3.2 of the Pico C SDK manual

### Why is bit-bang impractical on our laptop, despite it having a much faster processor than the RP2040 ?

1. It is too fast. The processor of our laptop isn't designed for this and it has a lot of work to do. In response to the growing distance between processors and memory, PC-class processors is trying to switch rapidly between hard real time tasks. If the processor is busy doing the ""bit-banging", it cannot be used for other tasks.

2. Above certain speeds - say a factor of 1000 below the processor clock speed - IPQs become impartical, in part due to the timing uncertainty of actually entering an interrupt hander.

3. Whilst dealing with something like an LED string is possible using "bit-banging", once your hardware protocol gets faster to the point that it is of similar order of magnitude to your system clock speed, there is not much you can hope to do.

### What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

1. For slower protocols.
2. In early days when processors were much slower and less tasks,the distance between the processor and memory was shorter, or the layer of software and hardware between processor and the outside was less and smaller, the GPIO could be a better choice.
3. On simpler embedded system.
4. LEDs and push buttons.

### How do you get data into a PIO state machine?

1. Loads a program into a PIO's instruction memory.
2. Sets up a PIO state machine to run the program.
3. Interacts with the state machine once it is running.

### How do you get data out of a PIO state machine?

1. The state machine needs to be told which GPIO or GPIOs to output to.
2. The GPIO also needs to be told that PIO is in control of it.
3. If we are using the pin for output only, we need to make sure that PIO is driving the output enable line high. PIO can drive this line up amd down programmatically.

### How do you program a PIO state machine?
1. Loads a program into a PIO's instruction memory.
2. Sets up a PIO state machine to run the program.
3. Interacts with the state machine once it is running.

The main ingredients in this recipe are:
- A PIO program
- Some software, written in C, to run the whole show
- A cmake file describing how these two are combined into a program image to load onto a PR2040-based development board

### In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

1. `rgbw`
2. `sm_config_out_shift(&c, false, true, rgbw ? 32 : 24)`

### What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

1. Translating assembly code into binary.
2. Building your PIO programs for you to `#include` from your C or C++ program.
3. It can also be used directly, and it can generate programs suitable for use with the MicroPython PIO library.
4. Within the SDK you do not need to invoke pioasm directly, as the CMake function `pico_generate_pio_header(TARDET PIO_FILE)` takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.
