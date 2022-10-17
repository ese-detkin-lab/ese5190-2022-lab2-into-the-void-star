University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Junpeng Zhao
    Tested on: dell xps13(2019), windows 10

`.\lab2q4\`: Question Q4 code <br>
`.\lab2q3\`: example code ws2812<br>
`.\part3\`:Question 3 screenshots, comments and others
# 3.1 
Done
# 3.2 PIO
Come back later
Reading chapter 3 of pico C/C++ SDK manual
* Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?<br>
Laptop processor has many hundreds of instructions in-flight on a single core at once, so it is not suitable on applying hard real time tasks<br>
* What are some cases where directly using the GPIO might be a better choice than using the PIO hardware? <br>
LEDs and push buttons.<br>
* How do you get data into a PIO state machine?<br>
  TX FIFO<br>
* how get data out?<br>
RX FIFIO
*  How do you program state machine<br>
PIO ASM
*   In the example, which low-level C SDK function is directly 
responsible for telling the PIO to set the LED to a new color<br>
`pio_sm_put_blocking`
*  What role does the pioasm “assembler” play in the example, and 
how does this interact with CMake?<br>
    >  * The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040
    > * the CMake function pico_generate_pio_header(TARGET
PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target
application
# 3.3 FOLLOW THE FLOW
ws2812.c
<img src=".\part3\comment33-1.jpg" style="zoom:70%"> <br>
<img src=".\part3\comment33-2.jpg" style="zoom:70%"> <br>
ws2812.pio.h
<img src=".\part3\comment33-3.jpg" style="zoom:70%"> <br>
# 3.4 COLOR BY NUMBER
**Most of data is acquired by printing values**<br>
<font color=#56A4CD >**COLOR(RGB):0x56A4CD**</font> 
|   |ADDRESS|OFFSET|NAME|VALUE|notes|
|:-|:--|:--|:--|:--|:--|
|Base       |0x50200000|       0|   PIO0_BASE|       |       init with pio0|
|CTRL       |0x50200000|0x000   |PIO control register|0x00000001      |pio=0,sm=0       |
|FSTAT      |0x50200000|0x004   |FIFO status register|0x00010f00|TX Full,RX empty|
|FDEBUG     |0x50200000|0x008   |FIFO debug register|0x01000f00||
|FLEVEL     |0x50200000|0x00c   |FIFO levels    |0x00000000||
|TXF0       |0x50200000|0x010   |TX FIFO for SM0|0x00A456CD|GRB value, use RX as TX|
|RXF0       |0x50200000|0x020   |RM FIFO for SM0|0x00000000||
|INSTR_MEM0 |0x50200000|0x048   |Instruction memory location 0|0x00000000||
|INSTR_MEMn|      |||0x00000000|Mem0-Mem31 all 0       |
|INSTR_MEM31|0x50200000|0x0c4   |Instruction memory location 31|0x00000000||
|SM0_CLKDIV |0x50200000|0x0c8   |Clock divisor register for SM0|0x000fa000|CLKDIV_INT=0xf0000,CLKDIV_FRAC=0xa000, f=clock f/|
|SM0_EXECCTRL|0x50200000|0x0cc  |Execution settings for state machine N|0x0001fe00||
|SM0_SHIFTCTRL|0x50200000|0x0d0 |Control behaviour of the input/output shift registers|0x40060000|use RX fifo as TX, output left,autopull |
|SM0_ADDR   |0x50200000|0x0d4   |   |0x0000001c|current instruction address (0x1c)|
|SM0_INSTR  |0x50200000|0x0d8   |   |0x00006221||
|SM0_PINCTRL|0x50200000|0x0dc|State machine pin control|0x20003000|side set 1, pin=12|

# 3.5

## Understand ws2812 protocol
* Basic circuitry for WS2812 LED: <br>
    shift 
* How connect WS2812 to a microcontroller<br>
    A serial data input to WS2812
* how to send single 1 or 0 bit to ws2812<br>
    > The width of the pulse determines whether it is a 1 or a 0 bit
* how many bits for a single color value<br>
  Three bytes in total for green, red and blue
* what happens if send more bits than this in a packet<br>
  Extra data will be retransmitted to the following WS2812
* how do you tell you are done sending data<br>
  Since autopull is enabled, if the PIO is stalled means it reaches its shift threshold, which means already sending data.
* how do you send data to more than one ws2812<br>
    Send a series of data, each ws2812 will keep the first three bytes of data and retransimts the rest of data to the next.
<font color=#56A4CD >**COLOR(GRB)   :0xA456CD<br>    0b101001000101011011001101**</font> 
<img src=".\part3\chart3-5.jpg" style="zoom:70%"> <br>

---



**Data flow:**
 (TX FIFO -> SM-> OSR)
`SHIFTCTRL_OUT_SHIFTDIR=0`, so OSR shift **left**
> **Autopull**: a mode where the state machine automatically
refills the OSR from the TX FIFO (an automatic pull) when a configured number of bits have been shifted out. Autopull
happens in the background, in parallel with whatever else the state machine may be up to (in other words it has a cost
of zero cycles)<BR>
> **Stalling**:<br>
• A WAIT instruction’s condition is not yet met<br>
• A blocking PULL when the TX FIFO is empty, or a blocking PUSH when the RX FIFO is full<br>
• An IRQ WAIT instruction which has set an IRQ flag, and is waiting for it to clear<br>
• An OUT instruction when autopull is enabled, and OSR has already reached its shift threshold<br>
• An IN instruction when autopush is enabled, ISR reaches its shift threshold, and the RX FIFO is full


||0|1|2|3|4|5|6|7|8|9|10|notes|
|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|
|Current instr|Line3|delay|delay|L4|delay|L5|delay|delay|delay|delay|L3|
|Data in FIFO?|0xA456CD00|0x0|0x0|0x0|0x0|0x0|0x0|0x0|0x0|0x0|0xA456CD00|Assume sending same value to LED
|SM stalled|n|y|y|y|y|y|y|y|y|y|y|
|delay cycles left|2|1|0|1|0|4|3|2|1|0|2|
|value of OSR|0xA456CD00->0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|0x48AD9A00|->0x915B3400|shift left at L3|
|x value|0->1|1|1|1|1|1|1|1|1|1|1->0|overwrite x at L3
|LED state|unknow->L|LOW|LOW|L to H|HIGH|HIGH|HIGH|HIGH|HIGH|HIGH|H to L|





* How many SM clock cycles take place from when color data is written to the FIFO up until the first full bit is sent, and make a numbered column for each time window
  10 cycles for 1 bit. For 24 bits, there's total 240cycles. But because the configuation is set to send RGBW, so total of 320 cycles.

# 3.6
`.\part3\chart36.png`
<img src=".\part3\chart36.png"> <br>
# 3.7
`.\part3\chart37.png`
<img src=".\part3\chart37.png"> <br>

---
# Reflect on the tools

||strengths|weaknesses|
|---|---|---|
|paper|easy to write, looks intuitional|spend lots of time|
|spreadsheets|much clean,save time|need to learn how to use|

Electronic drawing on iPad, which could reduce drawing time as cost on paper work, but also easy to execute compared with spreadsheets

# Comment
* **Minghui Ni** helped me on figuring out question 3.5
* Feedback: please give a much clear instuction for each question in future worksheet and a clearly specify for each question's deliverables. Question 3.5's instruction is too vague



