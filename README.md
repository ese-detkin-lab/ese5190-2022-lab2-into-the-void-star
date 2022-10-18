University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

3.2 PIO

3.2.1 Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
  
  "Bit-Banging" is very hard. The processor isn’t really designed for this and has large amount other work to do. 
  For slower protocols, you can use an IRQ to wake the processor up fast enough from what it's doing to send the next bit. Your processor is now busy doing the "bit-banging", and cannot be used for other tasks. Interruption of the processor can have very serious consequences.

3.2.2 What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
  
  If the specific GPIO are supposed to be accessed for several times. It is essentially an acyclic process.  
  Low-priority tasks that are less time-critical.
  The main case where software GPIO access is the best choice is LEDs and push buttons.
  
3.2.3 How do you get data into a PIO state machine?
  
  TX FIFO
  Each state machine has two FIFOs, between the state machine and the system bus, for data travelling out of (TX) and into (RX) the chip.
  TX first(TX) write the data into the state machine.
  The pull instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR).
  Data moves from the FIFO to the OSR one word (32 bits) at a time. 

3.2.4 How do you get data out of a PIO state machine?
  
  RX FIFO
  As mentioned above, the state machine also has a RX to output the data through the register and we can read the data from here.

3.2.5 How do you program a PIO state machine?
  
  System software loads data into the PIO's instruction memory and then set the i/o mapping.

3.2.6 In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? 
How is this function






