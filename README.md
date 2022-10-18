3.2 
Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
Bit-banging is too harder for the general slow protocols. It has some other work to do. When you use bit-banging to cope with certain work, any other work will not be able to be done at the same time, otherwise leading to big accident. Thus, it is not a good choice for your general work.

What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
1.When you only work a GPIO a few times but not loop for loads of times. 2.  When you need to switch on or off certain external peripherals like something less time-critical.

How do you get data into a PIO state machine?
TX1 transmit register to read data to input it into the state machine.

How do you get data out of a PIO state machine?  
RX1 receive register the same as the above.

How do you program a PIO state machine? 
Use the memory system in the state machine to load data into SM. Set mapping then the PIO runs.

In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code? 

put_pixel(arg) in which you set the (0,0,0xff) to be blue light. Of course it also has some basic lower function that contacts with ENABLE ORDER IN SDK C.

What role does the pioasm “assembler” play in the example, and how does this interact with CMake? 

You program with C sdk and translate it with GCC into assembler (jmp move out nop...) and then use cmake to combine them to produce the uf2, which means that you needn't to recompile the codes.



Brief discussion of decisions you made while working with your modeling documents. 
