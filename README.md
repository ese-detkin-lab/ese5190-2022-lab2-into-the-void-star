# University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

   Name: Yuan Chi<br>
   Tested on: MacBook Air (13-inch, 2019), macOS Monterey 12.6

## 3.2 PIO

### Brief responses to the reading questions in 3.2
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

## 3.3 Follow the flow

Photos my annotated code printout:<br>
https://github.com/ChiYuan9/ese5190-2022-lab2-into-the-void-star/blob/main/3.3-Annotated%20Code%20Printouts.pdf

## 3.4 Color by number

My favorate color is purple (RGB: 0xff00ff);<br>
My spreadsheet:<br>
https://github.com/ChiYuan9/ese5190-2022-lab2-into-the-void-star/blob/main/3.4Spreadsheet.xlsx

## 3.5 Modeling time

1. What basic circuitry does a WS2812 LED need to operate?<br>
When the power pin is high, WS2812 LED can receive data and change the color of LED based on input data.

2. How do you connect a WS2812 to a microcontroller?<br>
The connection between WS2812 and the RP2040 is wired connection. More specific, the input pin of the WS2812 is the DI pin, which is the PIN 12 on Adafruit Qt Py RP2040.

3. How does a WS2812 translate bits to color values?<br>
WS2812 receive color data in the GRB order. For the first 8 bit of the received 24 bit data, it is recognized as data for Green channel, and the second and thrid 8 digits for Red and Blue channels respectively.

4. How do you send a single 1 or 0 bit to the WS2812?<br>
WS2812 uses a non-return-to-zero protocol to communicate with other hardware: the length of the time period a high voltage continues identifies two different digits.  When the high voltage lasts 0.7us and followed by a low voltage input lasts 0.6us would be recognized as digit 1.  When the high voltage lasts 0.35us, which is shorter than the length of digit 1's high voltage input, followed by a low voltage input lasting 0.8us would be recognized as digit 0.

5. How many bits does it take to send a single color value?<br>
It takes 24 bits.

6. What happens if you send more bits than this in a packet?<br>
Extra bits will be output from the first WS2812 LED and send to the rest of WS2812 LED.

7. How do you tell a WS2812 you’re done sending data?<br>
The TX FIFO will be empty, and the SM will stalled.

8. How do you send data to more than one WS2812 in a chain?<br>
When serial data is presented at the LED’s input, it takes the first three bytes for itself (Green, Red, Blue) and the remainder is passed along to its serial data output. Often these LEDs are connected in a single long chain, each LED connected to a common power supply, and each LED’s data output connected through to the next LED’s input. A long burst of serial data to the first in the chain will deposit three bytes of GRB data in each LED, so their colour and brightness can be individually programmed.

