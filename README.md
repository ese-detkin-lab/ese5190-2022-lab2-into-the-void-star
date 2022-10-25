University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Qiao Xu
    qiaoqiao@seas.upenn.edu
    Tested on: Microsoft Windows 11 Pro

# 3.2 questions
1. Why is bit-changing impractical on your laptop, despite it having a much faster processor than the RP 2040?
Firstly, the bit-changing is IRQ based. But the IRQs become impractical above certain frequencies due to the timing uncertainty of actually entering an interrupt handler. It is hard to make sure the GPIO reading and writing happens on the exact same cycle required when doing the bit-banging.
Secondly, the processor can not be used for other tasks while being busy doing the “bit-banging”.

2. What are some cases where directly using the GPIO might be a better choice than the RP 2040?
	It can be used when you want to create new types of hardware interfaces on your RP-2040based device. Using the GPIO access is usually the best choice when dealing with LEDs and push buttons.

3. How do you get your data into a PIO state machine?
The data can be directly pushed into the state machine’s TX FIFO by using the “ pio_sm_put_blocking()”. 

4. How do you get data out of a PIO state machine?
By using the “pull” instruction to take one data item from the transmit FIFO buffer into the OSR first, and then use the “out” instruction to take one bit from the data to the destination such as a pin,, and then use “jmp” function to jump back to the loop to repeatedly take one data item from FIFO.

5. How do you program a PIO state machine?
It is often the case to write PIO programs both within the C++ SDK and directly from MicroPython.
And usually we need a PIO program, some software written in C to run the whole show, and a CMake file describing how these two are combined into a program image to load onto a RP2040-based development board.

6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
	The put_pixel function tells the new color, and this function is used in the void “pattern” function, and it will be accessed through the main function by the pattern_table[] function.

7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake
It is used to build the PIO programs and to #include from the program. It can be used to generate programs that are suitable for use with the MicroPython PIO library.

# 3.3 Follow the flow(Annotation of the code)
[3.3 annotation](https://github.com/23qiaoqiaoo/ese5190-2022-lab2-into-the-void-star/blob/9145ebe13a1cfc03275d63b546fdc448a64cb02e/3.3%20annotation.docx "3.3 annotation")
# 3.4 Datasheet
[3.4 datasheet](http://https://github.com/23qiaoqiaoo/ese5190-2022-lab2-into-the-void-star/blob/935e004791342202cf4c44891b5fdded6d76ba84/Q.xlsx)
# 3.5 Modeling time
![3.5 modeling time](https://github.com/23qiaoqiaoo/ese5190-2022-lab2-into-the-void-star/blob/247d7eb02a2beebc56e592daf04a9d26bc05951b/247743715797080649.jpg "3.5 modeling time")
#3.6&3.7
([!](https://github.com/23qiaoqiaoo/ese5190-2022-lab2-into-the-void-star/blob/a6076997da726e9bb2f57a184569932c8fb3fe6f/Lab3.6&3.7.xlsx)
# End Discussion
## The weaknesses of working with paper
It is hard to keep the paper tiny and it is hard to keep. The accuracy might be influenced too.
## The strength of working with paper
It is easier to think of the whole logic and take notes. And I personally feel more comforbale reading the paper version compared to the elctronic one.
## The weakness of working with spreadsheet
It is a lot to write and format when there is a bunch of data need to be recorded. It is slower compared to working on paper.
## The strength of working with spreadsheet
It can be easily stored and updated for future use.
