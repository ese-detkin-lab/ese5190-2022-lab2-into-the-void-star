# UPenn, ESE 5190: Intro to Embedded Systems, Lab 2A

    Katrina Ji, Worked with: Yuchen Wang
    Tested on: MacBook Pro (14-inch, 2021), macOS Monterey 12.6

## Part 3.2 Q&A 
Referred to [Pico C SDK manual](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
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

`pio_sm_put_blocking()` will tell PIo to set LED to new color. This function is probably initilized by one of the included header. The machine will look into the target header and perform instructions.

7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

Translating assembly code into binary. The CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET.

## Part 3.3 Code Annotation
See folder with name "lab2par3.3"

## Part 3.4 spreadsheet of initial PIO register states

![lab2par3 4register](https://user-images.githubusercontent.com/114244957/196347625-b2e75b01-4c3d-48fa-9b5c-73efd9416e57.png)

## Part 3.5 Paper Model

![IMG_0672](https://user-images.githubusercontent.com/114244957/196578972-13ff1c93-a566-4dc4-b360-ad6de2ccc9de.jpg)

The '-' mark means reserved. They are presented as grey blocks in the spreadsheet.

## Part 3.6 & 3.7 Packet transmission spreadsheet & Timing Diagram

The color for the example timing diagram is 0x0000FF(Blue in GRB).

![IMG_0675](https://user-images.githubusercontent.com/114244957/196578990-34e8d84a-da70-42bb-b379-79f042dfd988.jpg)

This is a tranmission for transmitting the first bit.

![IMG_0673](https://user-images.githubusercontent.com/114244957/196579062-296fa372-8ac6-42c6-b489-6a9e4c50b697.jpg)

The diagram uses a time resolution of *2 of a single SM clock cycle. The full diagram is shown above.

End discussion:
- I have chosen the color blue because the 0xFF is at the end of the sm. Thus, the "flow" of the bits will be more obvious in the timing diagram.
- Working with paper is easier for skim and scam. I can spread the papers and have a quick view of the codes/timing diagrams. Whereas iPad limited the contents I can see at one time due to the screen size.
- Spreadsheet can sometimes be too long to read and find useful information. Comparing to spreadsheet, I prefer tables. However, when the spreadsheet is not too long, it is easy to catch key infomation as infomation are spreaded out.
- I have not use VScode when I program. This could be a potential upgrade in the future.

## Part 4 Hello_LED

The codes are in the folder called "lab2_submissionfiles".

Guide to setup the SDK and run example codes are [ese5190Lab2_SDKGuide](https://github.com/katrinaji/ese5190Lab2_SDKGuide.git).
