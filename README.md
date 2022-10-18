University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yangbo Zhou
    Tested on:  HP Envy 13, Windows 11

# 3.2 PIO Questions

Q: Why is bit-banging impractical on your laptop, despite it having a 
much faster processor than the RP2040?  

A: When the processor is doing the "bit-banging", other tasks could not work at the same time.

Q: What are some cases where directly using the GPIO might be a 
better choice than using the PIO hardware?

A: The GPIO could only take some certain tasks like output voltage, reading input voltage.

Q: How do you get data into a PIO state machine? 

A: After data saved to RX FIFO, the data will be transmitted to OSR.

Q: How do you get data out of a PIO state machine? 

A: Using ‘pull’ instruction to take data from TX FIFO buffer, and ‘out’ instruction to take one data item from TX FIFO

Q: How do you program a PIO state machine? 

A: Using PIO assembly language.

Q: In the example, which low-level C SDK function is directly 
responsible for telling the PIO to set the LED to a new color? How 
is this function accessed from the main “application” code? 

A: static inline void put_pixel(uint32_t pixel_grb) 
   pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);

Q: What role does the pioasm “assembler” play in the example, and 
how does this interact with CMake? 

A: The PIO assembler. Through the CMake function pico_generate_pio_header(TARGET PIO_FILE) .



# 3.3 Annotated Code

These are the annotations for ws2812.c
![0d768cda79b2ebc448dc157c632e14b](https://user-images.githubusercontent.com/90922933/196425386-7fa472c6-f410-4777-b08e-a21101![5dbf440c4b3c96535b3feb9a19beb2e](https://user-images.githubusercontent.com/90922933/196425402-0838b963-bd79-401b-b971-1f7a2be59173.jpg)
c0214a.jpg)

These are for ws2812.pio.h
![2001001baf1c4d246c5310ec9a34dbe](https://user-images.githubusercontent.com/90922933/196425508-63e54a57-6ac9-4011-9978-f7823838cd63.jpg)
![b63ef4c98926549963690efaa13907a](https://user-images.githubusercontent.com/90922933/196425514-9624f16a-4777-49f0-a10a-ca412754c13c.jpg)



# 3.4 PIO Register Spreadsheet

Below is the register spreadsheet based on the datasheet of PICO SDK and RP2040
[3.4_Register_List (1).xlsx](https://github.com/yangbozh/ese5190-2022-lab2-into-the-void-star/files/9809592/3.4_Register_List.1.xlsx)


# 3.5 Paper Model

Below is a handdrawn paper model.
![44660b26e95b2e17d82eb9e6fdaaeeb](https://user-images.githubusercontent.com/90922933/196410738-db473f5e-08ed-467b-92c5-5916fb40a288.jpg)

# 3.6 Transmission Spreadsheet

This excel file is the Transmission Spreadsheet. 
[3.6.xlsx](https://github.com/yangbozh/ese5190-2022-lab2-into-the-void-star/files/9809572/3.6.xlsx)

# 3.7 Time Diagram

Below is the time diagram.
![6607bdb09280fcc83f24c42be58719f](https://user-images.githubusercontent.com/90922933/196410797-2b88e8aa-5ce0-40b2-9421-4cb24d428b67.jpg)

# 4 WOrking USB + WS2812 code folder

This is the code folder, everything except "build". 
https://github.com/yangbozh/ese5190-2022-lab2-into-the-void-star/tree/main/ESE519_LAB2A_PART4

# Discussion

This is the first time I deal with the knoledges about embedded system. Many of the terms are so strange for me that I have never even heard
of them before. To complete this file, in addition to check the datasheets refered in the instruction, I had to look up many other more resources to understand this lab. After stayed up two nights and spent dozens of hours of time on this aggsinment, it starts to seem interesting to me.

