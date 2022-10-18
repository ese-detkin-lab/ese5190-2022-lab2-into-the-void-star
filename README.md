University of Pennsylvania, ESE 5190 : Intro to Embedded Systems, Lab 2A

	SURAJ SREE BALAKRISHNA MARTHY
	https://www.linkedin.com/in/suraj-marthy-8b7109138/ ; 
	Tested on: Acer Predator Helios 300 PH315-51 (15.6 inches, Intel Core i5+8th Gen), Windows 11

## 3.2 : Reading Questions  

- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
	- Bit banging causes errors in communication basically during read/write. Anything that repeatedly reads/writes from GPIOs may not use bit-banging and preferably PIO may be used. Even though a laptop has high processing power than the RP2040, obtaining a precise timing is tricky for real time applications. But this can be performed on an RP2040 due to the presence of a dedicated hardware called PIO.

- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
	- GPIO can be better when the timing precision may be compromised. PIO is used when there is repeated read/write of information with a great deal of accuracy in time. For example, in case of a feedback controlled loop system (closed loop) the GPIO might just be sufficient.

- How do you get data into a PIO state machine?
	- Data can be put in a PIO state machine through a FIFO queue. FIFO queues interact with the state machine to transmit and receive data from the main program. Helper functions such as pio_sm_put_blocking() can be used to indicate that the FIFO is full and to wait until it gets free.

- How do you get data out of a PIO state machine?
	- An "out" statement can be used in a PIO code to write the data to a particular PIN which is defined. Basically, instead of FIFO PUSH from the above case, it works as FIFO PULL.

- How do you program a PIO state machine?
	- A .pio file is used to program a PIO state machine which contains instructions to identify each PIN behaviour. After the PIN behaviours are programmed, the configuration of the state machine is added and the CMakeLists.txt file is edited to generate a .pio.h file which is included in the C code to transmit data to the SM.

- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
	- pio_sm_put_blocking() is a helper function that is used to block the FIFO queue if it is full and also to wrte data to the TX FIFO queue if it is vacant. So this means that the same function is used to tell the PIO to set the LED to a new color.

- What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
	- The assembly C code is described in a easier way using the pioasm assembler. pico_generate_pio_header has to be called in the CMake file to create a header file which invokes pioasm.

## 3.3 : Follow the Flow

This [link](https://github.com/SurajMarthy1001/ese5190-2022-lab2-into-the-void-star/blob/d94f95174980885a1f097fd64cb2c9735ae31a64/AnnotatedCode.pdf) contains the annotated code of ws2812.c and generated/ws2812.pio.h

## 3.4 : Color by Number

	This link <> contains the spreadsheet of initial registers

## 3.5 : Modeling Time

	This link <> contains paper model of SM's operation as it relays a color packet to the Neopixel

## 3.6 & 3.7 : Zooming In & Timing Diagram

	This link <> contains timing diagram

## 4 : Hello, Blinkenlight

	This link <> directs to the folder that has the code and header files needed to blink the Neopixel when a certain Serial output is seen

## Decisions Taken

- This lab was performed after going through several documents and online examples on how a PIO and state machine works. 
- The readings provided were really useful in understanding the code and different functions that were used in it :
 
	- https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf
	- https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
	- https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf

## Reflections

- What were some strengths/weaknesses of working with paper?
	- Analysis of the C code and the .pio.h file while understanding the flow of each instruction is easier through annotating on paper. 

- What were some strengths/weaknesses of working with spreadsheets?
	- Spreadsheets help in better organisation of data and make it easier to read which is one of the main strenghts. 

- How might you approach this task using other tools available to you?
	- Need to delve deeper into the readings to have a clearer understanding about what exactly is going on. 


