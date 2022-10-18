University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    XUANANG CHEN
        xuanangc@seas.upenn.edu
    Tested on: 
    THUNDEROBOT 911Plus 11 (15.6-inch 2022)
    -Intel(R) Core(TM) i7-10870H CPU @ 2.20GHz 2.21 GHz -Windows 11 21H2 22000.1098
    -64-bit operating system, x64-based processor

## 3.2 PIO
- Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040 ?
    - Laptop processors have hundreds of instructions running simultaneously on a single core, making them unsuitable for applications with hard real-time tasks.
- What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
    - LEDs and push buttons.
- How do you get data into a PIO state machine?
    - Via TX FIFO.
- How do you get data out of a PIO state machine?
    - Via RX FIFO.
- How do you program a PIO state machine?
    - Using PIO ASM synax.
- In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?
    - `pio_sm_put_blocking`
- How is this function accessed from the main “application” code?
    - By reading every bit of SM.
 - What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
    - The PIO Assembler parses a PIO source file and outputs the assembled version ready for inclusion in an RP2040;
    - the CMake function pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target application.
## 3.3 FOLLOW THE FLOW
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/44cf3a90f34fbbf224ca9f7cd6a5a9a07c01714b/ws2812_00.png)
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/b63bb793e03e17da55170429981f42fc92ad487b/ws2812_01.png)
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/e6e6341b007635ef08d5fb1629217944bb9e8d46/ws2812_02.png)
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/271024adfa63f6d21dda2dd87e3fbcdef16d2182/ws2812_03.png)
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/906a8a0536331f81ccdfd6e4acee27abdfe39088/ws2812_04.png)
## 3.4 COLOR BY NUMBER
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
## 3.5 MODELING TIME
## Understand ws2812 protocol
- Basic circuitry for WS2812 LED: <br>
    -shift 
- How connect WS2812 to a microcontroller<br>
    -A serial data input to WS2812
- how to send single 1 or 0 bit to ws2812<br>
    -The width of the pulse determines whether it is a 1 or a 0 bit
- how many bits for a single color value<br>
    -Three bytes in total for green, red and blue
- what happens if send more bits than this in a packet<br>
    -Extra data will be retransmitted to the following WS2812
- how do you tell you are done sending data<br>
    -Since autopull is enabled, if the PIO is stalled means it reaches its shift threshold, which means already sending data.
- how do you send data to more than one ws2812<br>
    -Send a series of data, each ws2812 will keep the first three bytes of data and retransimts the rest of data to the next.
<font color=#56A4CD >**COLOR(GRB)   :0xA456CD<br>    0b101001000101011011001101**</font> 
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
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/22475f1c31279941fc1ac15a82006ee478359a05/3.5.jpg)

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
## 3.6 & 3.7
![image](https://github.com/IndigoQuadratic/ese5190-2022-lab2-into-the-void-star/blob/5a3b736502ee904fe61e897822c4777707174eb6/3.6&3.7.jpg)
    
  
