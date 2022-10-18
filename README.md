University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Zihan Zhang
         zihanzh@seas.upenn.edu
    Tested on: Ubantu

#Part 3.2
  Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
  If the processor is interrupted to attend to one of the hard peripherals it is also responsible for, it can be fatal to the timing of any bit-banged protocol. And 
  the  ratio between the processor speed and protocol speed is big, so the processor will spend uselessly idling in between GPIO accesses.

  What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
  The main case where software GPIO access is the best choice is LEDs and push buttons.

  How do you get data into a PIO state machine?
  Use pio_sm_put_blocking() function to push data directly into the state machine’s TXFIFO.

  How do you get data out of a PIO state machine?
  Use pull instruction first to take one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Then use out instruction to 
  write  that data to some pins.
  
  How do you program a PIO state machine?
  System software loads data into the PIO's instruction memory and then set the i/o mapping.

   In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the 
   main “application” code?
   pio_sm_put_blocking pio_sm_put_blocking() is called with the parameters from the put_pixel().

   What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
   Our program written in C language can be built to assembler with GCC. We can use CMake to generate uf2 file which can be recognized by the board.
 
#Part3.3
   
   
   
   
   
   
   
   
   
   
   
   
   





