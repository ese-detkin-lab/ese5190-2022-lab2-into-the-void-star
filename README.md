University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Ruturaj A. Nanoti
        www.linkedin.com/in/ruturajn
    Tested on: ASUS TUF DASH F15, Windows 11 (WSL)

### PART 3 - TALKING LEDs

- Q1: Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
    
    **Ans**: *Bit-Banging* is the process of using `GPIOs` to create a protocol. This is not feasible for the processors in modern PCs, because they have many hundreds
    of instructions in-flight on a single core, which creates problems when trying to switch between hard and real time tasks.
    
- Q2: What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
    
    **Ans**: Although the PIO State Machines are very efficient when it comes to monitoring GPIO states, it is not very capable of running general purpose programs. 
    Hence, more involved protocls like DPI and SDIO will require two or three state machines.
 
- Q3: How do you get data into a PIO state machine?
   
    **Ans**: The data from the transmit FIFO buffer, is placed into the OSR (**O**utput **S**hift **R**egister). The data movement from the FIFO to OSR happens one
    word (32-bits) at a time. From the OSR, data obtained from the FIFO is written to pins (i.e. 1-bit).

- Q4: How do you get data out of a PIO state machine?

    **Ans**: This is done by firstly selecting the `GPIO` pin/s that the PIO outputs to. Along with this, the `GPIO` pin that is used by the PIO, also need to know
    that the PIO is controlling it, so we configure the that pin/s to that mode (GPIO function select).

- Q5: How do you program a PIO state machine?
    
    **Ans**: For a program to be run on a PIO state machine, our program needs to be loaded into the instruction memory. For this to be possible, the location for
    free space in the instruction memory needs to be found. Once, you have the program loaded, you can find a free state machine and ask it to run the program, we
    just loaded.

- Q6: In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the 
    main “application” code?
    
    **Ans**: The `pio_sm_put_blocking()` is the low-level function used for telling the PIO, to set the LED to a new color. It takes a `32-bit` hex code, as one of 
    it's argument, which is `pixel_grb` that is left shifted by 8.
    
    The `puts()` function call in the main function, randomly addresses the `pattern_table` array, which in turn calls any of the `pattern_*` functions, where,
    a call to the `put_pixel()` function is made. Finally, the `put_pixel()` function, calls the `pio_sm_put_blocking()` function.
    
    Following is the control flow in the program,
    
    `main()` &#8594; `pattern_table[]` &#8594; `pattern_*` &#8594; `put_pixel()` &#8594; `pio_sm_put_blocking()`
    
- Q7: What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

    **Ans:** The `pioasm` tool is used to translate assembly code into a binary. This is integrated with `CMake` using the `pico_generate_pio_header(TARGET_
    PIO_FILE)` function, where the `TARGET_PIO_FILE` argument is used to address the `.pio` file.
