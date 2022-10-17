# UPenn, ESE 5190: Intro to Embedded Systems, Lab 2A

    Katrina Ji, Worked with: Yuchen Wang
    Tested on: MacBook Pro (14-inch, 2021), macOS Monterey 12.6

## Part 3.2 Q&A [Pico C SDK manual](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

As processors have become faster in terms of overwhelming number-crunching brute force, the layers of software and hardware between the processor and the outside world have also grown in number and size. In response to the growing distance between processors and memory, PC-class processors keep many hundreds of instructions in-flight on a single core at once, which has drawbacks when trying to switch rapidly between hard real time tasks.

Additionally of course, the processor is now busy doing the "bit-banging", and cannot be used for other tasks. If your processor is interrupted even for a few microseconds to attend to one of the hard peripherals it is also responsible for, this can be fatal to the timing of any bit-banged protocol.

Whilst dealing with something like an LED string is possible using "bit-banging", once hardware protocol gets faster to the point that it is of similar order of magnitude to the system clock speed, there is really not much you can hope to do. 

2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?

When the hardware is already programmed to fit the GPIO protocal. PIO hardware is useful when working with customized hardwares.

3. How do you get data into a PIO state machine?

   a) The `pull` instruction takes one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Data moves from the FIFO to the OSR one word (32 bits) at a time. 
   
   b) The `out` instruction takes one bit from the data pulled from the FIFO, and writes that data to some pins. 

4. How do you get data out of a PIO state machine?

   a) The state machine needs to be told which GPIO or GPIOs to output to.
   
   b) The GPIO also needs to be told that PIO is in control of it.
   
   c) Program the instructions in the .pio file. (which will later be made into a header file)

5. How do you program a PIO state machine?

Write the instructions in a .pio file. When using cmake, generate a header that has the same content as the .pio file and add the header as a source for the chip to look at.

6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?



7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?



## LAB WRITEUP: due Monday, Oct 17 at 8:30 AM ET on Github
Include the following files in your repo:
- 3.3: Photos or scans of your annotated code printouts 
- 3.4: Your spreadsheet of initial PIO register states
- 3.5: A photo or scan of your paper model
- 3.6: Your complete packet transmission spreadsheet 
- 3.7: Your polished timing diagram
- 4: Your working USB + WS2812 code folder
  - Don’t include build/, which is only for your machine. In general, you may want to use a “.gitignore” file to exclude machine-specific files when working in repositories you plan to publish.
- Update your README.md by filling in the TODOs along with the following content.
- Present your work for parts 3 and 4 as a cohesive writeup, linking and giving context for each file you uploaded. Include the following in your writeup:
  - Brief responses to the reading questions in 3.2.
  - Brief discussion of decisions you made while working with your modeling documents.
  - At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective.
    - What were some strengths/weaknesses of working with paper?
    - What were some strengths/weaknesses of working with spreadsheets?
    - How might you approach this task using other tools available to you?
  - Finally, submit a pull request with a link to your repo:
- The title should be "LAB 2A: YOUR NAME", followed by “Worked with: LAB PARTNER(S)”
- The comment section of your pull request should
include:
  - A mention of other students whose Github content you found helpful or who were able to help you with the lab, if any
  - (Briefly) Any bells and whistles you want to highlight
  - Feedback on your experience with the lab, if any
