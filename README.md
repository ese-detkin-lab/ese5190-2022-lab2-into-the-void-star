University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Navit Gill
        
    Tested on: MacBook Pro (13-inch, 2018), macOS Monterey 12.6
Used the C SDK for RP2040 to use C to code QT PY RP2040 board. Used the USB and ws2812 examples to combine them and blink the neopixel LED while sending serial commands to the console.

# Section 1 and 2
Used the datasheets and manual to set up the C SDK on my device (MacBook Pro 13-inch, 2018, macOS Monterey 12.6)
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/Setup%20Guide.md

# Brief responses to questions in Section 3.2
Bit banging is impractical on laptop even if the processor is really fast because one the processor is not designed for that. It has other important tasks that it should be able to run without getting interrupted for “bit-banging”. Two the timing needs to be accurate for bit-banging to work perfectly. The speed for LED strings isn’t that much but other hardware protocols are even higher speeds and timing comes into play.

Cases where gpio might be a better choice than using pio is if the hardware uses common protocols like uart, i2c or spi to connect and communicate with the microcontroller

Input shift register is used to get get data into PIO state machine from some pin
Output shift register is used to get data out of a state machine onto some pin

We can program a pio state machine usine .pio file written in assembly language, some software in C to run the main program and a cmake file to load onto rp2040 based board

# Section 3.3
Annotated the ws2812.c and .pio files 
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812%202.pdf
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812.pio.pdf

# Section 3.4
Created a spreadsheet of some of the registers used and their values
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/ESE5190_LAB2A.xlsx

# Section 3.5 
Showed transmission of 1 bit after receiving from FIFO
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/3.5.pdf

# Section 4
Here are the main files used to combine hello_usb.c code with ws2812.c code. Excluded the pico_sdk_import.cmake and the generated and build files.
The combined code is in hello_usb.c 
https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/hello_usb.c
The cmakelists file https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/CMakeLists.txt
The ws2812 header file https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812.h
ws2812.c file https://github.com/navgill4/ese5190-2022-lab2-into-the-void-star/blob/main/ws2812.c

Modeling the transmission on ipad with apple pencil had it's pros and cons. Creating the transmission model by hand helped me understand it better but representing this professionally should be done on computer.
Creating a spreadsheet with register values also helped understand which registers we used and their value based on our program.
One con of creating the spreadsheet by hand is if we change the code we would have to manually change the register value we put down for that register in the spreadsheet.
