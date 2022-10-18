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
