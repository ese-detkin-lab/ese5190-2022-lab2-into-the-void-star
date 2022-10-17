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

Ans: From TX FIFO into OSR.


4. How do you get data out of a PIO state machine?  

Ans: From ISR into RX FIFO.


5. How do you program a PIO state machine? 

Ans: PIO state machines execute short, binary programs. The PIO has a total of nine instructions: JMP, WAIT, IN, OUT, PUSH, PULL, MOV, IRQ, and SET. We write program using assembly language.


6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

Ans: Pio_sm_put_blocking . Calling put_pixel function. 


7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

Ans: The PIO assembler is included with the SDK, and is called pioasm. This program processes a PIO assembly input text file, which may contain multiple programs, and writes out the assembled programs ready for use. For the SDK these assembled programs are emitted in form of C headers, containing constant arrays. the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.


# At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective.


o What were some strengths/weaknesses of working with paper?

strengths: Flexibility in representation	

weaknesses: time consuming and making changes is difficult


o What were some strengths/weaknesses of working with spreadsheets?

strengths: much cleaner than paper model and saves time		

weaknesses: Regid way of representation (only tabular)


o How might you approach this task using other tools available to you?

Flowchart can also be used to show the flow of the code

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)
