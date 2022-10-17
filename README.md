University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Name: Ronil Synghal
        LinkedIn: www.linkedin.com/in/ronil-synghal
    Tested on: (TODO) MacBook Pro (13-inch, 2018, Four Thunderbolt 3 Ports), macOS Big Sur 11.4

## 3.3: Photos or scans of your annotated code printouts
The following [link](https://github.com/ronils428/ese5190-2022-lab2-into-the-void-star/blob/main/3.3%20Annotated%20Code.pdf) contains the annotated code for WS2812.c and WS2812.h.

## 3.4: Spreadsheet of initial PIO register states
The following [link](https://github.com/ronils428/ese5190-2022-lab2-into-the-void-star/blob/main/3.4%20Registers.pdf) contains the spreadsheet for the initial registers.


## 3.5: Paper Model
The following [link](https://github.com/ronils428/ese5190-2022-lab2-into-the-void-star/blob/main/3.5%20Modeling%20Time.pdf) contains paper model of the state machine’s operation as it relays a color packet to the NeoPixel.

## 3.6 & 3.7 Packet Transmission timing diagram and data arrangement
The following [link](https://github.com/ronils428/ese5190-2022-lab2-into-the-void-star/blob/main/3.6:3.7%20Timing%20Diagram.pdf) contains a hand-drawn timing diagram of relevant signals with approximated delays.

## 4: Hello, Blinkenlight
The following [link](https://github.com/ronils428/ese5190-2022-lab2-into-the-void-star/tree/main/hello_led) is the folder that contains all of the code to make the LED blink when we send certain serial commands.

# Additional Lab Questions

## 3.2
- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?  
    - One of the main disadvatanges of bit-banging is that more communication errors (glitches and jitters) occur. On a laptop, it is incrredibly important that the communcaiton is pristine and thus bit-banging wouldn't be a good solution.
- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  
    - Using a GPIO is a better choice when the interface speed is low. Push buttons are a great example. The communication can handle low frequencies so it can still receive and send signals in the time.
- How do you get data into a PIO state machine?
    - You can get data into a PIO state machine via a FIFO queue. Each state machine is connected with FIFO queues to exchange data with the main program. Instructions like "out" can be used to get data into a PIO state machine from FIFO to memory.
- How do you get data out of a PIO state machine?  
    - The logic is similar, but instead instructions like "pull" are used.
- How do you program a PIO state machine? 
    - Programming a PIO state machine requires pushing data into the TX FIFO from which it will be transmitted to the state machine and then executed.
- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
    - The function that is used is pio_sm_put_blocking() which writes data to the TX FIFO queue and blocks it if it is full.
- What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
    - The assmebler compiles Assembly code into a human readable format. 

# Decisions Made
- A lot of this lab was cross referencing code examples, tables, and reading through the following datasheets and guides.
    1. https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
    2. https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf
    3. https://ece4760.github.io/

- Following the links above allowed me to get a high level understanding of how PIO and state machines work. The registers definitely was the hardest part and I'm still not sure if the values I put are correct. 
- I referenced the [lab](https://github.com/ese-detkin-lab/ese5190-2022-lab2-into-the-void-star/pull/14) created by Haoze Wu. His team wrote a very well explained and detailed explanation of the lab.


## Reflections

- What were some strengths/weaknesses of working with paper? 
    - One of the major strengths of working with paper is that is really enforces you to understand what is happening from a conceptual level. However, this ends up being a weakness so to speak as it isn't that easy to check your understanding. 

- What were some strengths/weaknesses of working with spreadsheets?  
    - One of the main strengths here was organizing the vast amount of registers in a clean/readable format. The data was scatterred in different places in the linked documentation pages above and having it all centralized is very useful.

- How might you approach this task using other tools available to you?
    - I think one thing definitely to do in the future is ensure that my understanding of the labs are clear from day 1 and really using the TAs knowledge. 
