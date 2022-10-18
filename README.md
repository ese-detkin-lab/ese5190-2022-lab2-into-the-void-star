# LAB WRITEUP #
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2  

    Lihong Zhao  
        LinkedIn: www.linkedin.com/in/lihong-zhao-a24789224  
    Tested on: Lenovo Legion 5 Pro 16" Laptop, Intel Core i7-12700H， Windows11 

## 3.2 PIO Q&A ##

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


## 3.3: Photos of annotated code printouts
## 3.4: Spreadsheet of initial PIO register states
The WS2812 accepts color signals in GRB form, rather than the usual RGB form. the WS2812 takes the first 24 bits of the data representing the color from the PIO state machine and ignores the next 8 bits of the 32 bits. For the received 24 bits of data, it is automatically divided into three parts at 8 unit intervals. The three parts correspond to the green, red and blue lighted displays as showing in the following diagram.

![image](https://user-images.githubusercontent.com/113971230/196312411-b5268b79-2850-4f8a-8ab4-66396ffb4e1c.png)


Below is the spreadsheet of the list of registers for PIO.

|          |ADDRESS                 |OFFSET  |NAME                                         |VALUE|Notes|
| :---:    | :---:                  | :---:  | :---:                                       | :---: | :---: |
|BASE      | 0x5020000              | NONE   |PIO0_BASE<br>PIO1_BASE|NONE|Base address for PIO0_BASE and PIO1_BASE                   |
|CLTR      | 0x5020000              | 0x000  |PIO control register                         | 0x00000001 ||
|FSTAT     | 0x5020004              | 0x004  |FIFO status register                         | 0x0f000f01 | State machine 0's TX FIFO is  filled with color data while its RX FIFO is not used.     Other 3 state machine is not enabled. |
|FDEBUG    | 0x5020008              | 0x008  |FIFO debug register                          | 0x01000f00 | State machine 0's TX FIFO is  full and its RX is not used here.     Other 3 state machine is not enabled. |
|FLEVEL    | 0x502000c              | 0x00c  |FIFO level register                          | 0x00000000 | Only state machine 0's TX is  used, no level specficed for other TX or RX register |
|TXF0      | 0x5020010              | 0x010  |TXF0 register                                | 0x00000000 | The color 0xFF0000 is used here  for state machine 0. Since the WS2812 takes onlt GRB channel orders, the RGB  is transmitted in the form of GRB after transform. |
|TXF1      | 0x5020014              | 0x014  |TXF1 register                                | 0x00000000 ||
|TXF2      | 0x5020018              | 0x018  |TXF2 register                                | 0x00000000 ||
|TXF3      | 0x502001c              | 0x01c  |TXF3 register                                | 0x00000000 ||
|RXF0      | 0x5020020              | 0x020  |RXF0 rigister                                | 0xb6cf6b00 ||
|RXF1      | 0x5020024              | 0x024  |RXF1 rigister                                | 0x7fb2cd2f ||
|RXF2      | 0x5020028              | 0x028  |RXF2 rigister                                | 0xf1addb6c ||
|RXF3      | 0x502002c              | 0x02c  |RXF3 rigister                                | 0x47d836d7 ||
|INSTR_MEM0   | 0x5200048           | 0x048  |Write-only access to instruction memory location 0              | 0x00000000 ||
|INSTR_MEM1   | 0x502004c           | 0x04c  |Write-only access to instruction memory location 1              | 0x00000000 ||
|INSTR_MEM2   | 0x5020050           | 0x050  |Write-only access to instruction memory location 2              | 0x00000000 ||
|INSTR_MEM3   | 0x5020054           | 0x054  |Write-only access to instruction memory location 3              | 0x00000000 ||
|INSTR_MEM4   | 0x5020058           | 0x058  |Write-only access to instruction memory location 4              | 0x00000000 ||
|INSTR_MEM5   | 0x502005c           | 0x05c  |Write-only access to instruction memory location 5              | 0x00000000 ||
|INSTR_MEM6   | 0x5020060           | 0x060  |Write-only access to instruction memory location 6              | 0x00000000 ||
|INSTR_MEM7   | 0x5020064           | 0x064  |Write-only access to instruction memory location 7              | 0x00000000 ||
|INSTR_MEM8   | 0x5020068           | 0x068  |Write-only access to instruction memory location 8              | 0x00000000 ||
|INSTR_MEM9   | 0x502006c           | 0x06c  |Write-only access to instruction memory location 9              | 0x00000000 ||
|INSTR_MEM10  | 0x5020070           | 0x070  |Write-only access to instruction memory location 10              | 0x00000000 ||
|INSTR_MEM11  | 0x5020074           | 0x074  |Write-only access to instruction memory location 11              | 0x00000000 ||
|INSTR_MEM12  | 0x5020078           | 0x078  |Write-only access to instruction memory location 12              | 0x00000000 ||
|INSTR_MEM13  | 0x502007c           | 0x07c  |Write-only access to instruction memory location 13              | 0x00000000 ||
|INSTR_MEM14  | 0x5020080           | 0x080  |Write-only access to instruction memory location 14              | 0x00000000 ||
|INSTR_MEM15  | 0x5020084           | 0x084  |Write-only access to instruction memory location 15              | 0x00000000 ||
|INSTR_MEM16  | 0x5020088           | 0x088  |Write-only access to instruction memory location 16              | 0x00000000 ||
|INSTR_MEM17  | 0x502008c           | 0x08c  |Write-only access to instruction memory location 17              | 0x00000000 ||
|INSTR_MEM18  | 0x5020090           | 0x090  |Write-only access to instruction memory location 18              | 0x00000000 ||
|INSTR_MEM19  | 0x5020094           | 0x094  |Write-only access to instruction memory location 19              | 0x00000000 ||
|INSTR_MEM20  | 0x5020098           | 0x098  |Write-only access to instruction memory location 20              | 0x00000000 ||
|INSTR_MEM21  | 0x502009c           | 0x09c  |Write-only access to instruction memory location 21              | 0x00000000 ||
|INSTR_MEM22  | 0x50200a0           | 0x0a0  |Write-only access to instruction memory location 22              | 0x00000000 ||
|INSTR_MEM23  | 0x50200a4           | 0x0a4  |Write-only access to instruction memory location 23              | 0x00000000 ||
|INSTR_MEM24  | 0x50200a8           | 0x0a8  |Write-only access to instruction memory location 24              | 0x00000000 ||
|INSTR_MEM25  | 0x50200ac           | 0x0ac  |Write-only access to instruction memory location 25              | 0x00000000 ||
|INSTR_MEM26  | 0x50200b0           | 0x0b0  |Write-only access to instruction memory location 26              | 0x00000000 ||
|INSTR_MEM27  | 0x50200bc           | 0x0b4  |Write-only access to instruction memory location 27              | 0x00000000 ||
|INSTR_MEM28  | 0x50200b8           | 0x0b8  |Write-only access to instruction memory location 28              | 0x00000000 ||
|INSTR_MEM29  | 0x50200bc           | 0x0bc  |Write-only access to instruction memory location 29              | 0x00000000 ||
|INSTR_MEM30  | 0x50200c0           | 0x0c0  |Write-only access to instruction memory location 30              | 0x00000000 ||
|INSTR_MEM31  | 0x50200c4           | 0x0c4  |Write-only access to instruction memory location 31              | 0x00000000 ||
|SM0_CLKDIV   | 0x50200c8           | 0x0c8  |Clock Divisor register for SM 0                                  | 0x000fa000 ||
|SM1_CLKDIV   | 0x50200e0           | 0x0e0  |Clock Divisor register for SM 1                | 0x00000000 | State machine 1 is not used.                                 |
|SM2_CLKDIV   | 0x50200f8           | 0x0f8  |Clock Divisor register for SM 2                | 0x00000000 | State machine 2 is not used.                                 |
|SM3_CLKDIV   | 0x5020110           | 0x110  |Clock Divisor register for SM 3                | 0x00000000 | State machine 3 is not used.                                 |
|SM0_EXECCTRL  | 0x50200cc          | 0x0cc  |Execution/behavioral settings  for state machine 0      | 0x00000000 | Wrap top set to 0x1f while some  other address is nke known. |
|SM1_EXECCTRL  | 0x50200e4          | 0x0e4  |Execution/behavioral settings  for state machine 1      | 0x00000000 | State machine 1 is not used.                                 |
|SM2_EXECCTRL  | 0x50200fc          | 0x0fc  |Execution/behavioral settings  for state machine 2      | 0x00000000 | State machine 2 is not used.                                 |
|SM3_EXECCTRL  | 0x5020114          | 0x114  |Execution/behavioral settings  for state machine 3      | 0x00000000 | State machine 3 is not used.                                 |
|SM0_SHIFTCTRL | 0x50200d0          | 0x0d0  |Control behavior of the I/O  shift registers for state machine 0 | 0x00000000 | Shift OSR to left and AUTOPULL  is enabled in the configuration with a default pull threshold of 32. |
|SM1_SHIFTCTRL | 0x50200e8          | 0x0e8  |Control behavior of the I/O  shift registers for state machine 1 | 0x00000000 | State machine 1 is not used.                                 |
|SM2_SHIFTCTRL | 0x5020100          | 0x100  |Control behavior of the I/O  shift registers for state machine 2 | 0x00000000 | State machine 2 is not used.                                 |
|SM3_SHIFTCTRL | 0x5020118          | 0x118  |Control behavior of the I/O  shift registers for state machine 3 | 0x00000000 | State machine 3 is not used.                                 |
|SM0_ADDR    | 0x50200d4            | 0x0d4  |Current instruction address of  state machine 0        | 0x00000000 | State machine is going to output  the first digit of color data, which is the 0th instruction. |
|SM1_ADDR    | 0x50200ec            | 0x0ec  |Current instruction address of  state machine 1        | 0x00000000 | State machine 1 is not used.                                 |
|SM2_ADDR    | 0x5020104            | 0x104  |Current instruction address of  state machine 2        | 0x00000000 | State machine 2 is not used.                                 |
|SM3_ADDR    | 0x502011c            | 0x11c  |Current instruction address of  state machine 3        | 0x00000000 | State machine 3 is not used.                                 |
|SM0_INSTR   | 0x50200d8            | 0x0d8  |Instruction currently addressed  by state machine 0's program counter | 0x00000000 | Now the state machine 0 is going  to execute the 0th instruction out x, 1 side 0 [2] immediately, so this  register is wirtten as the instruction. |
|SM1_INSTR   | 0x50200f0            | 0x0f0  |Instruction currently addressed  by state machine 1's program counter | 0x00000000 | State machine 1 is not used.                                 |
|SM2_INSTR   | 0x5020108            | 0x108  |Instruction currently addressed  by state machine 2's program counter | 0x00000000 | State machine 2 is not used.                                 |
|SM3_INSTR   | 0x5020120            | 0x120  |Instruction currently addressed  by state machine 3's program counter | 0x00000000 | State machine 3 is not used.                                 |
|SM0_PINCTRL  | 0x50200dc           | 0x0dc  |State machine 0 pin control                  | 0x00000000 | Correct instruction specific a  pin used to receive the value of side-set change. |
|SM1_PINCTRL  | 0x50200f4           | 0x0f4  |State machine 1 pin control                  | 0x00000000 | State machine 1 is not used. |
|SM2_PINCTRL  | 0x502010c           | 0x10c  |State machine 2 pin control                  | 0x00000000 | State machine 2 is not used. |
|SM3_PINCTRL  | 0x5020124           | 0x124  |State machine 3 pin control                  | 0x00000000 | State machine 3 is not used. |

## 3.5: Photo of paper model

![image](https://user-images.githubusercontent.com/113971230/196324816-d1f1cc4f-600e-4268-9c7e-d5c45b38bd59.png)

## 3.6: Complete packet transmission spreadsheet

## 3.7: Polished timing diagram

## 4: Working USB + WS2812 code folder
[Code Folder](https://github.com/lihzhao14/ese5190-2022-lab2-into-the-void-star/tree/main/pico-diy)
