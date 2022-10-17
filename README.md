University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)


|          |ADDRESS                 |OFFSET|NAME|VALUE|Notes|
| :---:    | :---:                  | :---:  | :---:                                   | :---: | :---: |
|BASE      | 0x5020000              | NONE   |PIO0_BASE<br>PIO1_BASE|NONE|Base address for PIO0_BASE and PIO1_BASE                   |
|CLTR      | 0x5020000              | 0x000  |PIO control register                     | 0x00000001 | 12:31 digits are reserved, and  state machine 0 is enabled.  |
|FSTAT     | 0x5020004              | 0x004  |FIFO status register                     | 0x0f000f01 | State machine 0's TX FIFO is  filled with color data while its RX FIFO is not used.     Other 3 state machine is not enabled. |
|FDEBUG    | 0x5020008              | 0x008  |FIFO debug register                      | 0x01000f00 | State machine 0's TX FIFO is  full and its RX is not used here.     Other 3 state machine is not enabled. |
|FLEVEL    | 0x502000c              | 0x00c  |FIFO level register                      | 0x00000000 | Only state machine 0's TX is  used, no level specficed for other TX or RX register |
|TXF0      | 0x5020010              | 0x010  |TXF0 register                         | 0000 0000<br />1111 1111<br />0000  0000<br />0000 0000 | The color 0xFF0000 is used here  for state machine 0. Since the WS2812 takes onlt GRB channel orders, the RGB  is transmitted in the form of GRB after transform. |
|TXF1      | 0x5020014              | 0x014  |TXF1 register                         | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | Not used, keep  default.                                     |
|TXF2      | 0x5020018              | 0x018  |TXF2 register                         | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | Not used, keep  default.                                     |
|TXF3      | 0x502001c              | 0x01c  |TXF3 register                         | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | Not used, keep  default.                                     |
|RXF0      | 0x5020020              | 0x020  |RXF0 rigister                         |                          EMPTY                          | Not used, default  empty.                                    |
|RXF1      | 0x5020024              | 0x024  |RXF1 rigister                         |                          EMPTY                          | Not used, default  empty.                                    |
|RXF2      | 0x5020028              | 0x028  |RXF2 rigister                         |                          EMPTY                          | Not used, default  empty.                                    |
|RXF3      | 0x502002c              | 0x02c  |RXF3 rigister                         |                          EMPTY                          | Not used, default  empty.                                    |
|INSTR_MEM0   | 0x5200048           | 0x048  |WO ACCESS TO INSTRUCTION MEMORY  0              | 0000 0000<br />0000 0000<br />0110  0010<br />0010 0001 | Store the first instruction  out  x, 1 side 0 [2] here in the 15-0  digits while reserving 31-16 digits. |
|INSTR_MEM1   | 0x502004c           | 0x04c  |WO ACCESS TO INSTRUCTION MEMORY  1              | 0000 0000<br />0000 0000<br />0001  0001<br />0010 0011 | Store the first instruction  out  jmp !x, 3 side 1 [1] here in the  15-0 digits while reserving 31-16 digits. |
|      ...      |    ...     |  ...   |                             ...                              |                           ...                           | ...                                                          |
|INSTR_MEM31  | 0x50200c4           | 0x0c4  |WO ACCESS TO INSTRUCTION MEMORY  31              | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | Apart from those 4 slots used  for the 4 instructions, other instruction memories are not used and allow WO  access. |
|SM0_CLKDIV   | 0x50200c8           | 0x0c8  |Clock Divisor register for SM 0                | 0000 0000<br />0000 1111<br />1010  0000<br />0000 0000 | Since the default clk_sys is  150MHz, the assigned frequency is 800000 and the cycles per bit is 8, so the  INT is 15 and the FRAC is 0.625 |
|SM1_CLKDIV   | 0x50200e0           | 0x0e0  |Clock Divisor register for SM 1                | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 1 is not used.                                 |
|SM2_CLKDIV   | 0x50200f8           | 0x0f8  |Clock Divisor register for SM 2                | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 2 is not used.                                 |
|SM3_CLKDIV   | 0x5020110           | 0x110  |Clock Divisor register for SM 3                | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 3 is not used.                                 |
|SM0_EXECCTRL  | 0x50200cc          | 0x0cc  |Execution/behavioral settings  for state machine 0      | 0000 0000<br />0000 0001<br />1111  0000<br />0000 0000 | Wrap top set to 0x1f while some  other address is nke known. |
|SM1_EXECCTRL  | 0x50200e4          | 0x0e4  |Execution/behavioral settings  for state machine 1      | 0000 0000<br />0000 0001<br />1111  0000<br />1000 0000 | State machine 1 is not used.                                 |
|SM2_EXECCTRL  | 0x50200fc          | 0x0fc  |Execution/behavioral settings  for state machine 2      | 0000 0000<br />0000 0001<br />1111  0000<br />1000 0000 | State machine 2 is not used.                                 |
|SM3_EXECCTRL  | 0x5020114          | 0x114  |Execution/behavioral settings  for state machine 3      | 0000 0000<br />0000 0001<br />1111  0000<br />1000 0000 | State machine 3 is not used.                                 |
|SM0_SHIFTCTRL | 0x50200d0          | 0x0d0  |Control behavior of the I/O  shift registers for state machine 0 | 0000 0000<br />0000 0110<br />0000  0000<br />0000 0000 | Shift OSR to left and AUTOPULL  is enabled in the configuration with a default pull threshold of 32. |
|SM1_SHIFTCTRL | 0x50200e8          | 0x0e8  |Control behavior of the I/O  shift registers for state machine 1 | 0000 0000<br />0000 1100<br />0000  0000<br />0000 0000 | State machine 1 is not used.                                 |
|SM2_SHIFTCTRL | 0x5020100          | 0x100  |Control behavior of the I/O  shift registers for state machine 2 | 0000 0000<br />0000 1100<br />0000  0000<br />0000 0000 | State machine 2 is not used.                                 |
|SM3_SHIFTCTRL | 0x5020118          | 0x118  |Control behavior of the I/O  shift registers for state machine 3 | 0000 0000<br />0000 0110<br />0000  0000<br />0000 0000 | State machine 3 is not used.                                 |
|SM0_ADDR    | 0x50200d4            | 0x0d4  |Current instruction address of  state machine 0        | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine is going to output  the first digit of color data, which is the 0th instruction. |
|SM1_ADDR    | 0x50200ec            | 0x0ec  |Current instruction address of  state machine 1        | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 1 is not used.                                 |
|SM2_ADDR    | 0x5020104            | 0x104  |Current instruction address of  state machine 2        | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 2 is not used.                                 |
|SM3_ADDR    | 0x502011c            | 0x11c  |Current instruction address of  state machine 3        | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 3 is not used.                                 |
|SM0_INSTR   | 0x50200d8            | 0x0d8  |Instruction currently addressed  by state machine 0's program counter | 0000 0000<br />0000 0000<br />0110  0010<br />0010 0001 | Now the state machine 0 is going  to execute the 0th instruction out x, 1 side 0 [2] immediately, so this  register is wirtten as the instruction. |
|SM1_INSTR   | 0x50200f0            | 0x0f0  |Instruction currently addressed  by state machine 1's program counter | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 1 is not used.                                 |
|SM2_INSTR   | 0x5020108            | 0x108  |Instruction currently addressed  by state machine 2's program counter | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 2 is not used.                                 |
|SM3_INSTR   | 0x5020120            | 0x120  |Instruction currently addressed  by state machine 3's program counter | 0000 0000<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 3 is not used.                                 |
|SM0_PINCTRL  | 0x50200dc           | 0x0dc  |State machine 0 pin control                  | 0001 0100<br />0000 0000<br />0000  0100<br />0000 0000 | Correct instruction specific a  pin used to receive the value of side-set change. |
|SM1_PINCTRL  | 0x50200f4           | 0x0f4  |State machine 1 pin control                  | 0001 0100<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 1 is not used.                                 |
|SM2_PINCTRL  | 0x502010c           | 0x10c  |State machine 2 pin control                  | 0001 0100<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 2 is not used.                                 |
|SM3_PINCTRL  | 0x5020124           | 0x124  |State machine 3 pin control                  | 0001 0100<br />0000 0000<br />0000  0000<br />0000 0000 | State machine 3 is not used.                                 |
