University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

Harish Ramesh, Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/ ; https://www.linkedin.com/in/sugata-sen/
Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10

## 3.3 Follow the flow
https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/79140c6e067e816f42d2d9d76407d760bad93ade/3.3_annotations_and_flow.pdf

## 3.4 Color by number
https://docs.google.com/spreadsheets/d/1iRsQCAwo6xrsGQcdKzWXdB_pM1_v_IVhFM-M53KPGO0/edit?usp=sharing

## 3.5 Modelling Time
https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/3a815c42360a7faf1715b66e33a4eccf398051eb/3_5_Zooming_in.pdf

## 3.6 & 3.7 Zooming In and Timing Diagram
https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/3a815c42360a7faf1715b66e33a4eccf398051eb/ese_519_lab2a_3_6_7.xlsx
For the timing diagram in 3.7, we have mentioned the value of the clock at clock cycle period and mentioned the value at each time instant. Graphically representing the clock was becoming tedious after starting it.

## Hello Blinkenlight
The codes have been added to the repo:
- c code: https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/3a815c42360a7faf1715b66e33a4eccf398051eb/ws2812.c
- header file: https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/3a815c42360a7faf1715b66e33a4eccf398051eb/ws2812.pio.h
### Output
![](https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/e5a9fb32666a7cfa5c006d0ef4bc1a1b9688ec98/op.gif)

## Brief Responses to questions raised in into the (void):
### Reading questions in 3.2
- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040? <br>
With the Moores law increase that we have seen, processors have scaled up to such an extent that a lot of processes run concurrently behind the scenes.This makes using hard resets like interrupts impractical. Smaller processors like those in micro-controllers respond better to bit-banging because they have a lot lesser on their plate. Bit-banging on a higher level processor like a pc could break the flow and cause timing issues and race conditions.

-What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?<br>
Simple tasks like toggling pins on and off do not require the PIOs programming power which is better used for dealing with harder functions.

-How do you get data into a PIO state machine?<br>
The data goes through an Rx FIFO and the ISR.

-How do you get data out of a PIO state machine?<br>
The data goes through the OSR and a Tx FIFO.

- How do you program a PIO state machine?<br>
PIO state machines can execute short, simple and binary programs. Needless to say they need to be programmed in assembly language. The PIO has a total of nine instructions to work with: JMP, WAIT, IN, OUT, PUSH, PULL, MOV, IRQ, and SET. 

-In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?<br>
The function used is the put_pixel function. This is declared using the Pio_sm_put_blocking sub-function.

-What role does the pioasm “assembler” play in the example, and how does this interact with CMake?<br>
The PIO assembler is included with the SDK, and is referred to as pioasm. This program processes a PIO assembly input text file, which may contain multiple programs, and writes out the assembled programs ready for use. For the SDK these assembled programs are emitted in form of C headers, containing constant arrays. the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.

### Reading questions in 3.4
-Which PIO instance is being used?<br>
From the code we can see that pio0 is used as the sm used is set to 0.

-Which state machine is being used with this PIO instance?<br>
As mentioned above the state machine used is SM 0.

-Which pin is this state machine configured to control? (you can either use settings from the example program, or for the Qt Py LED pin yours will be connected to)?<br>
As the code is written it uses pin 2. We rewrite it to work with pin 11.

-How long is this state machine’s clock cycle?<br>
0.8 Mhz

-How much is this state machine’s clock scaled down relative to the system clock? (i.e. the “clock divisor”)<br>
16.625

- In which direction will this state machine shift bits out of its “output shift register”?<br>
Right Shift

## Decisions taken during modelling
We decided to use blue light of the highest intensity at the very beginning as the light to be transmitted. This made it so that the data that we would transmit would be 0x000000FF which made computations and demonstrations slightly easier.

## Reflections
- What were some strengths/weaknesses of working with paper and spreadsheets?<br>
Strengths: Poring through documentation tends to make you understand atleast 50% of what's happening at the register level in the board.<br>
Weaknesses: Considering the size of the documentation, without some sort of guidance at the start you feel like you are thrown off the deep end. In addition following the the code at the bit level is very tedious and when you are not aware how each register functions at an atomic scale, it becomes very hard to track and follow through. Despite having an electronics background I found it difficult, time-consuming and error-prone to follow through some parts of the assignment writeup. Students from other disciplines would have had a rougher time.

-How might you approach this task using other tools available to you?<br>
We could try to deal with problems at a higher level of abstraction to make it less strenous. Maybe flowcharts instead to follow the code. If there was helper code that was semi-complete that we could use to track register values that could be useful too.
