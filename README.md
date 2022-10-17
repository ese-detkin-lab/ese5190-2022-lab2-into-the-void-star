University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Meiyi Yu
    Tested on: MacBook Pro (13-inch, 2019), macOS Monterey

Included lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)


### 3.2 Questions
##### Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? 
If using bit-banging, it will continuously consumes the memory and kernel of the PC, while the computer has other tasks to do.  for slower protocols you might be able to use an IRQ to wake up the processor from what it was doing fast enough (though latency here is a concern) to send the next bit(s). But PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks. 

##### What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 
When the frequency is relatively slow, like LED or push buttons.

##### How do you get data into a PIO state machine?  (reference Yu Feng)
Instruction is pulled from the FIFO through transmitting register to the PIO state machine. Instructions like 'out', 'pull' can move data from FIFO to OSR to SM register/memory. Specifically to get data into a PIO state machine, 'out' can be used. In addition, instructions like 'pio_add_program()' can find space in 1 PIO's specific memory and loads the instructions before the SM can run the program.

##### How do you get data out of a PIO state machine?  
Use 'pull' operation.

##### How do you program a PIO state machine? 
In general: 1. Determine which PIO instance to use(out of 2) PIO pio = pio0; PIO pio = pio1; 2. Assign instructions into instruction memory with sufficient space uint offset = pio_add_program(pio, &program_name_here) 3. Find an available state machine uint sm = pio_claim_unused_sm(pio, true); some_kind_of_program_init(pio, sm, offset, PICO_DEFAULT_LED_PIN); Up to this point, state machine is ready and running.

##### In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How 
is this function accessed from the main “application” code? 
pio_sm_put_blocking. Accessed from while loop.

##### What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 
PIO is programmed with assembling language, and cmake acts as a compiler to compile the assembler to executable program. 

### 3.3 Follow the flow
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/3.3.pdf

### 3.4 Register Table
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/Lab2table.xlsx

### 3.5 .pio main
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/blob/main/3.5.png

### 3.6

### 3.7

### 4 light the LED and print out message
https://github.com/Thea-E/ese5190-2022-lab2-into-the-void-star/tree/main/WS2812_LED


