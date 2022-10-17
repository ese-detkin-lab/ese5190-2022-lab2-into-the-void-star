University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    name:Ze Li
    twitter:Kopred7
    Tested on:  MacBook Pro (16-inch, 2021), macOS Monterey 12.6

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)
# Answers for 3.2Q

**Q1:Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?**

A1:First,since the bit-bangning is that uses the software to realize I2C protocol and the bit-bangning can just provide a low inefficient for cpu,cpu in our laptop need a high efficient way to use I/O serials.Ans alos bit-bangning need users are responsible for their own synchronization and timing and so on,which would increase workload for users and decrease sense of user.

**Q2:What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?** 

A2:First, GPIO means General Purpose Input / Output which can allow users to use them to drive the LED light or something directly.But for PIO which is an abstract concept,Users need to define them manually.Therefor,GPIO is better than PIO.

**Q3How do you get data into a PIO state machine?**

A3:For the input,we can use the TXn FIFO to get the data from PIO state machine.And then ,we can use the out command which can allow the state machine move a data from OSR to Scratch register.

**Q4:How do you program a PIO state machine?**

A4:By writting a pio program such as ws2812.pio which will use the pio asm-like instructions,we can generate a .pio.h file while building.In addition,if we want to generate the .pio.h file, we should edit the CMakelists.txt.

**Q5:In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?**

A5:In ws2812.c, the function is put_pixel(uint32_t pixel_grb).But,actually,pio_sm_put_blocking(PIO pio, uint sm, uint32_t data) is the real function.

**Q6:How is this function accessed from the main “application” code?**

A6:when the main code need to put color to NeoPixel,the program will call the function put_pixel() and the function will call another function named pio_sm_put_blocking which is defined in pio.c.

**Q7:What role does the pioasm “assembler” play in the example, and how does this interact with CMake?**

A7:The pioasm "assembler" allow users to define the function of GPIO to solve the inefficient problem which is caused by different communication rates of each communication protocol.In CMakeLists.txt, we can use pico_generate_pio_header to generate a .pio.h file.Such as pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)


# 3.3 Follow the flow

