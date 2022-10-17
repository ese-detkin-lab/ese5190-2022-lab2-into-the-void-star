# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    by Yu Feng
    Tested on: MacBook Pro (15-inch, 2018), macOS Monterey 12.4

### README:

    This repository records the ESE5190: Intro to Embedded Systems, Lab 2A including code and related setup configurations.


### 3.3: Photos or scans of your annotated code printouts

The following link contains the annotated code for WS2812.c and WS2812.h.

The first three pages contain code from WS2812.c and remaining 2 pages contain codes from WS2812.h. The count jumps from WS2812.c at 6 to WS2812.h and jumps back at 20. These 14 instructions are documented and annotated in WS2812.h.

https://github.com/skyfall88888/ese5190-2022-lab2-into-the-void-star/blob/main/Lab2(a)_3.3_annotated_code.pdf

### 3.4: Your spreadsheet of initial PIO register states

The following link contains the spreadsheet for the registers.

https://github.com/skyfall88888/ese5190-2022-lab2-into-the-void-star/blob/main/Lab2(a)_3.4_PIO_REG.xlsx

### 3.5: A photo or scan of your paper model

The following link contains the pdf of the paper model. 

https://github.com/skyfall88888/ese5190-2022-lab2-into-the-void-star/blob/main/Lab2(a)_3.5.pdf


### 4: Working USB + WS2812 code folder

The following link contains the zip file for the working USB + WS2812 code folder. The file and the related c code file are named as hello_usb_plus_led.

https://github.com/skyfall88888/ese5190-2022-lab2-into-the-void-star/blob/main/hello_usb_plus_led.zip

# Additional Lab Questions

3.2 PIO reading questions:

• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

   From the perspective of processor, to enable bit-banging requires the IRQ instruction to be executed to wake up the processor from what it was doing fast enough to send the next bits. But if the working frequency is high, it is very difficult to keep the frequency compliant and to keep the timing cycle exact.
    
• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

   Cases when the interface speed is relatively low. When the external hardware is operating at a low enough frequency, it is very likely that it can still receive/send and understand the signals. For example, push buttons, indicator LEDs.

• How do you get data into a PIO state machine?

   Instruction is pulled from the FIFO through transmitting register to the PIO state machine. Instructions like 'out', 'pull' can move data from FIFO/OSR from/to SM/memory. Specifically to get data into a PIO state machine, 'out' can be used. In addition, instructions like 'pio_add_program()' can find space in 1 PIO's specific memory and loads the instructions before the SM can run the program.
    
   In general:
    1. Determine which PIO instance to use(out of 2)
        PIO pio = pio0;
        PIO pio = pio1;
    2. Assign instructions into instruction memory with sufficient space
        uint offset = pio_add_program(pio, &program_name_here)
    3. Find an available state machine
        uint sm = pio_claim_unused_sm(pio, true);
        some_kind_of_program_init(pio, sm, offset, PICO_DEFAULT_LED_PIN);
    Up to this point, state machine is ready and running.
    

• How do you get data out of a PIO state machine?

   As mentioned in part 'How do you get data into a PIO state machine', 'pull' instruction is an example that can get it done.

• How do you program a PIO state machine?

   I described how to setup and get SM running above, to program a PIO state machine, data needs to be pushed into the TX FIFO. The data that got pushed to the TX FIFO will be transmitted to the SM and gets executed.

• In the example, which low-level C SDK function is directly
responsible for telling the PIO to set the LED to a new color? How
is this function accessed from the main “application” code?

   pio_sm_put_blocking: write a word of data to a state machine's TC FIFO< blocking if the FIFO is full.

• What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?

   The assmbler works as a 'translator' that compiles the ASM language. CMake generally supports the 'assembler' to convert between 'machine specific' and 'human readable' languages.
