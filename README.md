University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

SATYAJEET DAS<br />
LinkedIn: https://www.linkedin.com/in/satyajeet-das/<br />
Tested on:DELL Inspiron 16 Plus (16-inch, 2022), Windows 11 Home 21H2<br />


(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

Link to set up guide (Part 1 & 2): ![Set Up Gide for Windows](https://github.com/satyajeetburla/-Lab-2-SETUP-GUIDE)

#3.2
## Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
Because PIO state machines allow for repeated readings and writes from GPIOs. Furthermore, it performs data transfer operations 
more efficiently than "Bit-Bangling."


## What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? 
We can use Bit-Bangling in tasks that require slower protocols. We can use IRQ-based bit banging on simpler embedded systems. LEDs and push buttons are the most common applications for software GPIO access.

## How do you get data into a PIO state machine?
The OSR serves as a holding place for data entering the state machine through the TX FIFO. Data is loaded into the OSR one 32-bit 
chunk at a time from the TX FIFO. When an out instruction is issued, the OSR can divide the data into smaller chunks by shifting to 
the left or right and sending the bits that fall off the end to one of a few potential destinations, such as the pins.


## How do you get data out of a PIO state machine? 
GPIO mapping logic enables each state machine to see and manipulate up to 30 GPIOs. Here, we must define the GPIO Pins and PIO 
instances that will be synchronized for data to exit the PIO state machine.

# In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? 
put_pixel() helper method above to output a sequence of pixel values while setting LED to a new color value.

## How is this function accessed from the main “application” code?
The PIO file we just looked at, WS2812.pio, is automatically turned (we'll learn how later) into a header containing our built 
PIO program binary, any assistance functions we put in the file, and other valuable program information. This is coded as 
WS2812.pio.h.

## What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
Our.pio file's assembly program is converted into a binary program. Assembler programs are those that handle the task of 
converting assembly code into binary. A CMake file explains how to compile them into a binary that can be loaded into your 
Raspberry Pi Pico or other RP2040-based board. The CMake function pico generate pio header(TARGET PIO FILE) handles executing 
pioasm and putting the resulting header to the target TARGET's inclusion path. 






##3.3 WS2812.pio's annotations
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/PIO/Untitled_1.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/PIO/Untitled_2.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/PIO/Untitled_3.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/PIO/Untitled_4.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/PIO/Untitled_5.png)


##3.3 .WS2812.c File anotation
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/C/Untitled_1.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/C/Untitled_2.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/C/Untitled_3.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/C/Untitled_4.png)
<br>
![ ](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/C/Untitled_5.png)


##3.4
<br>

[This](https://github.com/satyajeetburla/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203/main/3.4%20Spreadsheet%201.xlsx) is the link of the spreadsheet that I have prepared for this portion of the answer
# Which PIO instance is being used? Which state machine is being used with this PIO instance?
In this code, 0 instace of PIO and 0 instance of State machine were used.

# Which pin is this state machine configured to control? (you can either use settings from the example program, or for the Qt Py LED pin yours will be connected to)
Here WS2812_PIN was used by state machine to control.

# How long is the state machine's clock cycle? How much is this state machine’s clock scaled down relative to the system clock? 
State machines clock cycle is 48MHz. The clock divider can be configured to slow down the execution of the state machine: a clock divisor of n indicates that one 
instruction is performed every n system clock cycles. SDK's system clock frequency is set at 125MHz by default.

# In which direction will this state machine shift bits out of its “output shift register”?
Output Shift Register receives the input from the TX FIFO register bit-wise and shifts the output to the other output pins using OUT
command.

# What basic circuitry does a WS2812 LED need to operate?
Green, Red, and Blue are represented by three cascaded blocks on the WS2812. Each block has I/O ports such as (Power supply LED), Vdd, Gnd, Data output (DOUT), Data input (DIN), Power supply Control circuit (VCC), and Ground (VSS). Data bits indicating RGB brightness are serially sent into the Din pin, after which the chip strips out the first 24 bits (8 bits for R,G,B) and sends the remaining bits out the Dout pin. By connecting the LEDs in a string, with the Dout from one LED flowing to the Din of the next LED, each LED strips off the bits it requires from the front of the data stream and transmits the remainder of 
the data stream to the next LED. The number of LEDs you can drive with a single data line is theoretically unlimited; the only constraint is that the time it takes 
to update all the LEDs in the string rises linearly with the number of LEDs in the string. This results in a highly creative and 
effective method of addressing unique RGB data to any number of LEDs linked in a string.



//3.5
# How do you connect a WS2812 to a microcontroller?
WS2812 is connected to Microcontroller by Connecting with PCB Board with soldering.

# How does a WS2812 translate bits to color values?
When serial data is supplied to the LED's input, it takes the first three bytes (red, green, blue) and passes the remainder to its 
serial data output. These LEDs are frequently connected in a single continuous chain, with each LED connected to a common power 
source and its data output connected to the next LED's input.

# How do you send a single 1 or 0 bit to the WS2812?
WS2812 line format. Here, Wide positive pulse is used for 1 and narrow positive pulse for 0.

# How many bits does it take to send a single color value?
In WS2812, each color is represented by 24 bits of data.

# What happens if you send more bits than this in a packet? When we try to send more than one bits than this in a packet, the packet is divided into multiple packets and sent. How do you tell a WS2812 you’re done sending data?
To fill the vacuum, the out instruction pushes data out of the OSR and zeroes in from the other end. Because the OSR is 32 bits wide, you will begin to see zeroes after shifting out a total of 32 bits. A pull instruction explicitly removes data from the TX FIFO and places it in the OSR (stalling the state machine if the FIFO is empty).

# How do you send data to more than one WS2812 in a chain?
We are using TX FIFO registers for sending data more than one WS2812 in a chain. The data that we are moving out of the OSR comes from the state machine's TX FIFO, which is more extensively documented in the RP2040 Datasheet. The TX FIFO is a data buffer between the state machine and the rest of the RP2040 that may be filled 
either directly from the CPU or through system DMA, which is substantially quicker.

