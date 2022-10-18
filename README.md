# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

# File description

【**part3.3**】: Annotated code for ws2812 example

【**part3.5.peng**】: Paper model for PIO process 1 bit (DATA=0 / DATA=1)

【**Spreadsheet of initial PIO register states.xlsx**】: Spreadsheet of initial PIO register states, Packet transmission spreadsheet and Timing diagram based on part3.5

【**part4**】: Working USB + WS2812 folder

# Part 3.2

- *Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?*

    Because the processors of laptop have become faster in terms of overwhelming number-crunching brute force, the layers of        software and hardware between the processor and the outside world have also grown in number and size. In response to the growing distance between processors and memory, PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks.

- *What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?*

    The main case where software GPIO access is the best choice is LEDs and push buttons.

- *How do you get into a PIO state machine?*

    **IN** instructions shift 1…32 bits at a time into the register, then **PUSH** instructions write the ISR contents to the RX FIFO.

- *How do you get data out of a PIO state machine?*

    The **PULL** instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time. Then use **OUT** instruction shift data from the OSR to other destinations, 1…32 bits at a time.

- *How do you program a PIO state machine?*

    Choose one PIO instance to use

    PIO pio = pio0;

    Find a location (offset) in the instruction memory where there is enough space of program

    unit offset = pio_add_program(pio, &hello_program);

    Find a free state machine on chosen PIO

    Uint sm = pio_claim_unused_sm(pio, ture)
 
- *In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?*

    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);

- *What role does the pioasm “assembler” play in the example, and how does this interact with CMake?*

    The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040 application. This includes C and C++ applications built against the SDK, and Python programs running on the RP2040 MicroPython port.

# Part 3.3

Check the file 【**part3.3**】, some annotaions were wirtten in the code of file【**part4**】.

# Part 3.4

Check the file 【**Spreadsheet of initial PIO register states.xlsx**】

# Part 3.5

Check the file 【**part3.5**】

- *What basic circuitry does a WS2812 LED need to operate?*

    Intelligent digital port data latch, signal reshaping amplification drive circuit, precision internal oscillator, 12V voltage programmable constant current control.

- *How do you connect a WS2812 to a microcontroller?*

    | WS2812 Pin | Function Description | RP2040 Pin |
    | ---------- | -------------------- | ---------- |
    | DOUT | Control data signal output | LEDs |
    | DIN | Control data signal input | GPIO 12 |
    | VCC | Power supply control circuit | GPIO 11 |

- *How does a WS2812  translate bits to color values?*

    Composition of 24bit data:

    |G7|G6|G5|G4|G3|G2|G1|G0|R7|R6|R5|R4|R3|R2|R1|R0|B7|B6|B5|B4|B3|B2|B1|B0|
    |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|

- *How do you send a single 1 or 0 bit to the WS2812?*

    Wide positive pulse for 1, narrow positive pulse for 0, very long negative pulse for latch enable.

- *How many bits does it take to send a single color value?*

    24

- *What happens if you send more bits than this in a packet?*

    LEDs consume 24 bits of pixel data, then pass any additional input data on to their output. In this way a single serial burst can individually program the color of each LED in a chain.

- *How do you tell a WS2812 you’re done sending data?*

    A long negative pulse latches the pixel data into the LEDs.

- *How do you send data to more than one WS2812 in a chain?*
    
    Set a threshold for 24 bits

# Part 3.6 & 3.7

Check the file 【**Spreadsheet of initial PIO register states.xlsx**】

# Part 4

Check the file 【**part4**】for detailed code.

# Reflection

The data sheet of MCU and sensor and the handout for SDK is really a good resource to check when we begin to code our onw project. But the data they contain is huge, creating our own sheet for data we need to check oftenly will help a lot when we encounter some specifc question like address issures.

And before begin our own project, we'd better deep understand the example code. Not only the .c/.h these high level could, but also try to zoom in a cycle to understand what the processor will do to send one bit data.

Last, doucumentary is also important since we could fell free to go back and check what we've done before.
