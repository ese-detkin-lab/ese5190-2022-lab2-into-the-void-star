University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Ruturaj A. Nanoti
        www.linkedin.com/in/ruturajn
    Tested on: ASUS TUF DASH F15, Windows 11 (WSL)

### PART 3.2 : PIO

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

    **Ans:** The `pioasm` tool is used to translate assembly code into a header file. This is integrated with `CMake` using the 
    `pico_generate_pio_header(TARGET_PIO_FILE)` function, where the `TARGET_PIO_FILE` argument is used to address the `.pio` file.

### PART 3.3 : FOLLOW THE FLOW

***NOTE: The code for `ws2812.c` is annotated with comments.***

![embedded_c1](https://user-images.githubusercontent.com/56625259/196353886-8ab1ac11-11b7-4d9c-852f-69fb200b6f1b.JPG)

![embedded_c2](https://user-images.githubusercontent.com/56625259/196353911-2a3abf8a-5ed9-48fa-89c1-5f8cd3131e9d.JPG)

![embedded_c3](https://user-images.githubusercontent.com/56625259/196353943-ad4bbcfd-495c-4125-a17c-1e547465ae18.JPG)

![embedded_c4](https://user-images.githubusercontent.com/56625259/196353958-42bd1563-5d20-4ed8-b79c-6ea496691426.JPG)

![embedded_c5](https://user-images.githubusercontent.com/56625259/196353978-9eb261a6-7358-4a24-88a8-d79003e29a7c.JPG)

<br>

***NOTE: The code for `ws2812.h` is annotated with comments.***

![embedded_h1](https://user-images.githubusercontent.com/56625259/196355871-9ff69497-3e40-469b-92b2-4a0b8e8e0638.JPG)

![embedded_h2](https://user-images.githubusercontent.com/56625259/196355880-7f4df490-734d-45ab-ba91-926047ed2df4.JPG)

![embedded_h3](https://user-images.githubusercontent.com/56625259/196355896-12d7cc68-e9f5-413c-bbe3-e0a19c59e79d.JPG)

![embedded_h4](https://user-images.githubusercontent.com/56625259/196355915-23a340a0-abc5-4cc2-b672-159dce777a25.JPG)

![embedded_h5](https://user-images.githubusercontent.com/56625259/196355941-5b8ec697-9194-4602-a597-06b6c0eafdc5.JPG)


### PART 3.4 : COLOR BY NUMBER

The Excel File contains the values for the registers : [Link](https://github.com/Ruturajn/ese5190-2022-lab2-into-the-void-star/blob/main/ESE519-Spreadsheet.xlsx)

### PART 3.5 : MODELLING TIME

![WhatsApp Image 2022-10-17 at 10 51 10 PM](https://user-images.githubusercontent.com/56625259/196359264-f81e6bf6-640e-41be-947f-67f4f2a0a58d.jpeg)

### PART 3.6 : ZOOMING IN AND TIMING DIAGRAM

The Excel File contains timing data for packet transfer to the `ws2812` module : [Link](https://github.com/Ruturajn/ese5190-2022-lab2-into-the-void-star/blob/main/ESE5190-3.7.xlsx)

### PART 4 : HELLO BLINKENLIGHT


https://user-images.githubusercontent.com/56625259/196392029-b82e49ca-d3dc-409e-9239-3145cd341b79.mp4

### REFLECTIONS

- What were some strengths/weaknesses of working with paper?
    
    **Ans**: It felt easier to dry run code.

- What were some strengths/weaknesses of working with spreadsheets?
    
    **Ans**: Understanding the bits in registers was easier when working with them on paper.

-  How might you approach this task using other tools available to you?
    
    **Ans**: Visualizing timing for various elements would be helpful.
