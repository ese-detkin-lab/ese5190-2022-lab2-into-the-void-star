University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Osamuyi Uwadia
    LinkIn: https://www.linkedin.com/in/osamuyi-uwadia-a3038813b/
    Tested on: HP Spectre x360 Convertible 15-df1xxx Microsoft Windows 11

3.2
1.	Why is bit-banging impractical on your laptop, despite it having a 
much faster processor than the RP2040?  
The laptop’s processors has a lot of instructions on a single core.

2.	What are some cases where directly using the GPIO might be a 
better choice than using the PIO hardware?  
LEDs and push buttons

3.	How do you get data into a PIO state machine? 
pull from Tx FIFO to output shift register (OSR)

4.	How do you get data out of a PIO state machine?  
Out from OSR to Rx FIFO


5.	How do you program a PIO state machine? 
The PIO ASM. I/O is mapped, and state machine is triggered

In the example, which low-level C SDK function is directly 
responsible for telling the PIO to set the LED to a new color? How 
is this function accessed from the main “application” code? 
pico_sm_put_blocking by including ‘ws2812.pio.h’ in the code and using ‘put_pixel’ function to input color value

6.	What role does the pioasm “assembler” play in the example, and 
how does this interact with CMake?
The PIO assembler parses a PIO sourse file and output the assembled version ready for inclusion in an RP2040 application
The CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target 

3.3


3.4



4.0
