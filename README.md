University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    XUANANG CHEN
        xuanangc@seas.upenn.edu
    Tested on: 
    THUNDEROBOT 911Plus 11 (15.6-inch 2022)
    -Intel(R) Core(TM) i7-10870H CPU @ 2.20GHz 2.21 GHz -Windows 11 21H2 22000.1098
    -64-bit operating system, x64-based processor

## 3.2 PIO
- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040 ?
    - Laptop processors have hundreds of instructions running simultaneously on a single core, making them unsuitable for applications with hard real-time tasks.
- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
    - LEDs and push buttons.
- How do you get data into a PIO state machine?
    - Via TX FIFO.
- How do you get data out of a PIO state machine?
    - Via RX FIFO.
- How do you program a PIO state machine?
    - Using PIO ASM synax.
- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?
    - `pio_sm_put_blocking`
- How is this function accessed from the main “application” code?
    - By reading every bit of SM.
 - What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
    - The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040;
    - the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target application.
## 3.3 FOLLOW THE FLOW
![image]
