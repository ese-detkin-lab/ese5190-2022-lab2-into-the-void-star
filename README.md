# University of Pennsylvania
# ESE 5190: Intro to Embedded Systems
## Lab 2A

### Shantanu Sampath
Partner: Aamir Khambaty

https://www.linkedin.com/in/shantanu-sampath/

 Tested on: HP 17 (Windows 11)


### I)Responses to 3.2:

1) Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

A. Bit-banging involves the CPU polling on the GPIO pins periodically, making it difficult to complete other tasks. This would affect the real-time performance of the system.

2) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

A. a. Accessing a pin for a one-time use or outside of a continuous loop. Going through the PIO would add latency.
   b. Low-priority tasks which can be pre-empted by higher priority ones can be bit-banged. 
   c. Designing a system to cut costs: FOr extremely low cost systems that do not require significant real time performance, bit banging could be preferred to 
      offset the investment in a dedicated hardware module. 

3) How do you get data into a PIO state machine?

A. The software needs to write to data into the TX FIFO registers.

4) How do you get data out of a PIO state machine?

A. Data is retrieved by accessing the RX FIFO register in the state machine. 

5) How do you program a PIO state machine?

A. The PIO consists of 4 state machines that use a shared instruction memory. The software must load the data and code into this shared memory, configure the IO mappting and trigger the state machine.

6) In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

A. Low level C SDK function to set LED color: pio_sm_put_blocking()
   How is it added: 
   - Add the PICO SDK link libraries to the CMakeLists.txt file: pico_stdlib and hardware_pio. These libraries contain the APIs and bitfields necessary to access the low level PIO registers. 
   - In the code, call the pio_sm_put_blocking() API by passing in the parameters: pio instance, state machine instance and the 32 bit value which is used to determine the LED color

7) What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

A. The pioasm is an assembler, which is used to convert the assembly code in the .pio file into low level machine code, used to directly control the PIO module. 
  Within the CMakeLists.txt file, the the instruction pico_generate_pio_header(TARGET PIO_FILE) invoke the assembler for us.

8) Brief discussion of decisions you made while working with your modeling documents.
9)  At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective.

### II) What were some strengths/weaknesses of working with paper?

Strengths:
1) Helps get a clear understanding of the mechanincs
2) Helps to get ideas down quickly and intuitively

Weakness:
1) Hassle of printing and using so many sheets
2) Not the neatest way to go about it

### III) What were some strengths/weaknesses of working with spreadsheets?

Strengths:
1) Information can be presented clearly and effectively
2) Easily sharable and scalable

Weaknesses:
1) Not an elegant method to represent simple concepts.

### IV) How might you approach this task using other tools available to you?

1) SDK documentation
2) Stack Overflow
3) Using a debugger and an IDE to step through code
