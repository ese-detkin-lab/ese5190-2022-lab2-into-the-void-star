University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Xiayu Zeng
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook air (M1, 2020), macOS Monterey 12.6
    
# Part 3
## 3.2 Response to Questions

-   *Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?*

    Answer: Bit-banging is applied for data transmissions in commonly embedded systems, it allows device to implement different protoclos woth minimal or no hardware changes. As PC-class processor need to transmit large amount of data at the same time and it would be really low effecient for it to transmi data through bit-banging, moreover, the bit-banging is generated based on high precise timing and IO ports.

-    *What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?*
    
    Answer: Cases like output control signal, output PWM signal, input nterrupt signal, work as i2c port.
-   *How do you get data into a PIO state machine?*

    Answer: System -> TX FIFO -> PIO SM
    
-   *How do you get data out of a PIO state machine?*

    Answer: PIO SM -> RX FIFO -> System
    
-   *How do you program a PIO state machine?*

    Answer: Through PIO assembler language.
    
- *In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?*

    Answer: pio_sm_put_blocking()
    
- *What role does the pioasm “assembler” play in the example, and how does this interact with CMake?*

    Answer: The pioasm assembler transfer the PIO file into the low level version which is readable for hardware. CMake function pico_generate_pio_header(TARGET PIO_FILE) invokes the assembler





