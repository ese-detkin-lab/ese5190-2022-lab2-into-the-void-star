University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Aamir Abbas Khambaty
    Partner: Shantanu Sampath
    linkedin.com/in/aamir-khambaty-7807a11a4
    Tested on: Dell G3 Core i7, 16 GB RAM

(TODO: Your README)
Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

Questions from Section 3.2
1. Why is bit-banging impractical on your laptop, despite it having a 
much faster processor than the RP2040?

Ans: Bit-banging is a very time cfitical process. The processor of the laptop has to concirrently carry out a high number of tasks. If the processor has to attend to any other task such as other hardware peripherals. Bit-banging involves the processor to poll the GPIO pins. If the processor attends to any other task for even a few microseconds the big-banging protocol could get adversely affected.

2. What are some cases where directly using the GPIO might be a 
better choice than using the PIO hardware? 

a. If a certain GPIO needs to be accessed only a few times such as as an enable pin of an external chip, basically a process that does not to be looped.
b. To switch on or off certain external peripherals such as indicator LEDs.
c. Low priority tasks which are less time critical.

3. How do you get data into a PIO state machine? 

Each state machine in PIO has a TX First in First shift register. The system software will load data into this register and the stat emachine reads data from this register.


4.How do you get data out of a PIO state machine?

Each state machine in PIO has a RX First in First shift register. The stat emachine will ouput the data through this register and the system software will read it through this register.

5. How do you program a PIO state machine? 
There are 4 PIO state machines.There is a shared instruction memory for all these 4 state machines. The system sofware will load the data into these state machines via this memory set, set the i/o mapping and get the PIO running.

6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?  How is this function accessed from the main “application” code? 
 The "pio_sm_put_blocking" function sets the new colour to the led. 
 In order to access this function in the main application code:
 a. Add the Pico SDK link libararies to the CMakeLists.txt file: picostdlib.h and hardware/pio.h
 b. In the main code call the pio_sm_put_blocking functions with the following parameters: pio instance, state machine instance, 32 bit color data.
 
7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 
In the pico SDK the pioasm is an assembler that translates the assmebly code from the pio.h file into the binary code needed to be loaded in the state machine.
In the CMake file tehre exists a function known as pico_generate_pio_header(TARGETPIO_FILE) which invokes the Pioasm, which makes it easier as we dont have to invoke it from the C-SDK.

### II) What were some strengths/weaknesses of working with paper?

Strengths:
1. Easier to initate the design and proptptype the model
2. Clear understanding by simplification.
3. Helps to put down ideas.

Weakness:
1. Large number of sheets to be printed and referred to.
2. Connecting data from different sheets is difficult.

### III) What were some strengths/weaknesses of working with spreadsheets?

Strengths:
1. Data and information represented systematically.
2. Data can be imported easily.

Weakness:
1. Difficult to explain details about the data.
2. Sometimes too much information could be overwhelming.

### IV) How might you approach this task using other tools available to you?
1. Online Videos and Tutorials.
2. SDK Documentation
3. Use of an IDE to simplify coding.





