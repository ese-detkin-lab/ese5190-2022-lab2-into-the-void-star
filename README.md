# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

   Name: Yuan Chi<br>
   Tested on: MacBook Air (13-inch, 2019), macOS Monterey 12.6

## 3.2 Brief responses to the reading questions in 3.2

1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?<br>
If the processor is interrupted to attend to one of the hard peripherals it is also responsible for, it can be fatal to the timing of any bit-banged protocol. And the ratio between the processor speed and protocol speed is big, so the processor will spend uselessly idling in between GPIO accesses.

2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?<br>
The main case where software GPIO access is the best choice is LEDs and push buttons.

3. How do you get data into a PIO state machine?<br>
Use pio_sm_put_blocking() function to push data directly into the state machine’s TXFIFO.

4. How do you get data out of a PIO state machine?<br>
Use pull instruction first to take one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Then use out instruction  to write that data to some pins.

5. How do you program a PIO state machine?<br>
First, choose a PIO instance to use. Second, use pio_add_program() loading program into the PIO's instruction memory. Third, use pio_claim_unused_sm() finding a free state machine. Last, configure out state machine by using helper function we included in our .pio file to start and run our program.

6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?<br>
The processor can use pio_sm_put_blocking(pio, sm, 1) and pio_sm_put_blocking(pio, sm, 0) to push data directly into the state machine’s TX FIFO to turn on LED or turn off LED.
7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?<br>
The assembler will change a ".pio" file to some static variables describing the program and a method which configures a PIO state machine based on user parameters, and the directives in the actual PIO program. CMake support the converte process from "human language" to "machine language".

## 3.3 Photos or scans of your annotated code printouts

https://github.com/ChiYuan9/ese5190-2022-lab2-into-the-void-star/blob/main/3.3-Annotated%20Code%20Printouts.pdf
