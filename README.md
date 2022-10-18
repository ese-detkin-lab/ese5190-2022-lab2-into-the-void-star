University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

Sahil Mahendra Mangaonkar
LinkedIn: https://www.linkedin.com/in/sahil-m-39a2671b0
Tested on:  HP Probook 650 G1 (15.6-inch, 2014), Window 10

# Brief responses to the reading questions in 3.2:
1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

Ans: With increase in the speed of processors, the layers between hardware and software between the processor and the outside world have also increased in size and number.  Because of which, the processors keep hundreds of thousands of instructions on a single core at a time. Hence it’s difficult to switch rapidly between hard real time tasks.

Above certain speeds — say a factor of 1000 below the processor clock speed — IRQs become impractical, in part due to the timing uncertainty of actually entering an interrupt handler. It’s difficult to write in assembly, trying to make sure the GPIO reading and writing happens on the exact cycle required. your processor is now busy doing the "bit-banging", and cannot be used for other tasks. If your processor is interrupted even for a few microseconds to attend to one of the hard peripherals it is also responsible for, this can be fatal to the timing of any bit-banged protocol.


2. What are some cases where directly using the GPIO might be a  better choice than using the PIO hardware?

Ans: Simple task such as LED blinking is better done with GPIO than using pio where we’ll send data into state machine having more sets of instruction than what we need to toggle LED with GPIO. PIO suits better for performing complex tasks efficiently.


3. How do you get data into a PIO state machine? 

Ans: From TX FIFO into OSR using pull instruction.


4. How do you get data out of a PIO state machine?  

Ans: From ISR into RX FIFO out instruction.


5. How do you program a PIO state machine? 

Ans: PIO state machines execute short, binary programs. The PIO has a total of nine instructions: JMP, WAIT, IN, OUT, PUSH, PULL, MOV, IRQ, and SET. We write program using assembly language.


6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

Ans: Pio_sm_put_blocking . Calling put_pixel function. 


7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

Ans: The PIO assembler is included with the SDK, and is called pioasm. This program processes a PIO assembly input text file, which may contain multiple programs, and writes out the assembled programs ready for use. For the SDK these assembled programs are emitted in form of C headers, containing constant arrays. the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.


# 3.4: Spreadsheet of initial PIO register states

https://docs.google.com/spreadsheets/d/18KsNoGRULzMHCPo81uQk1wKcW_Gdkq5YdlxhDTKC2yk/edit?usp=sharing

1.	Which PIO instance is being used? 

Ans: Pio0

2.	Which state machine is being used with this PIO instance?

Ans: SM0

3.	Which pin is this state machine configured to control? (you can  either use settings from the example program, or for the Qt Py  LED pin yours will be connected to)  

Ans: Default pin of mcu or pin 2 of mcu

4.	How long is this state machine’s clock cycle? 

Ans: 800 kHz

5.	How much is this state machine’s clock scaled down relative to the system clock? (i.e. the “clock divisor”)  

Ans: 125M/(800k*10)=15.625

6.	In which direction will this state machine shift bits out of its  “output shift register”?

Ans: LSB first (right shift)

# 3.5 State machine:

For color value 0x00FF0000

.wrap_target       

bitloop: 			            
 	out x, 1 side 0 [T3 - 1] ; 	             L1   Shift 1 bit from OSR into x and set side set pio pin low and wait for T3-1 cycles
	
	 jmp !x do_zero side 1 [T1 - 1] ;        L2   Jump to do_zero loop if x is zero and set side set pio pin high and wait for T1-1 cycles
	 
 do_one: 
 
 	jmp bitloop side 1 [T2 - 1] ;	           L3   Jump to bitloop if x was 1 and set side set pio pin high and wait for T2-1 cycles
	
 do_zero:                                                   
 
 	nop side 0 [T2 - 1] ; 		               L4   No Operation if x was 0 and set side set pio pin low and wait for T2-1 cycles
	
.wrap				

1.	What basic circuitry does a WS2812 LED need to operate? 

Ans: Supply (GND and VDD=5v), data pin, a resistor of value 150, a capacitor.

2.	How do you connect a WS2812 to a microcontroller? 

Ans: Connect GND of microcontroller to GND of WS2812, a gpio pin of microcontroller controlled using PIO to data in (DI) pin of ws2812.

3.	How does a WS2812 translate bits to color values? 

Ans: Bits are sent sequentially to the module to turn on and off the led so fast that we can see a color generated as we wanted.

4.	How do you send a single 1 or 0 bit to the WS2812? 

Ans: Make DI pin high or low using data pin of microcontroller.

5.	How many bits does it take to send a single color value? 

Ans: 8

6.	What happens if you send more bits than this in a packet? 

Ans: It will take data as it comes and will not give correct color.

7.	How do you tell a WS2812 you’re done sending data? 

Ans: Out instruction waits for data and keep side pin low.

8.	How do you send data to more than one WS2812 in a chain?

Ans: Connect DO of 1 module to DI of other and so on.

3.6: Your complete packet transmission spreadsheet: https://docs.google.com/spreadsheets/d/12_uLVYzCS_PQK7ii11mfC0H6asqVYpEb/edit?usp=sharing&ouid=105381450260615402187&rtpof=true&sd=true

# 4. Code for Lab 2 Q 4

This program will take an integer input from 1,2, and 3. Depending upon input number, WS2812 neopixel LED will blink with a perticular color for that many number of times. Following will be the output of the program:

1-->Neopixel LED will blink with red color once.

2-->Neopixel LED will blink with green color twice.

3-->Neopixel LED will blink with blue color thrice.

Refer to code ws2812.c file for explaination of the program.

Output: https://github.com/Sahil-M-M/ese5190-2022-lab2-into-the-void-star/blob/main/Code-for-Lab-2-Q4/ESE5190%20Lab%202%20Q%204%20output.gif


# At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective.

1. Brief discussion of decisions you made while working with your modeling documents.

Ans: Various values the registers will take, flow of codes, and timing diagrams.

2. What were some strengths/weaknesses of working with paper?

strengths: Flexibility in representation	

weaknesses: time consuming and making changes is difficult


3. What were some strengths/weaknesses of working with spreadsheets?

strengths: much cleaner than paper model and saves time		

weaknesses: Regid way of representation (only tabular)


4. How might you approach this task using other tools available to you?

Ans: Flowchart can also be used to show the flow of the code.
We can use online tools for ploting the timing diagrams.

