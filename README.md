# 3.2 PIO
Why is bit-bang impractical on our laptop, despite it having a much faster processor than the RP2040 ?

1.	For speed, modern PC-class processors need the memory and speed to handle task processing. In bitbanging, the process tries very hard to read and write GPIOs in the same cycle (a few microseconds) which is difficult.
2.	When the processor speed exceeds a certain threshold, the non-determinism of actually entering the interrupt handler IPQ becomes impractical.

What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
For slower protocols like LED strings and simple embedded systems or some brust I/O. In cases where the processor only needs to handle simple tasks (not containing 'loop' instructions) and the outside of the processor is small. For example, LEDs and pushbuttons (send a signal containing high voltage to power the WS2812).

How do you get data into a PIO state machine?
TX FIFO
Set up the PIO state machine to run the loaded program, get the data from the transfer FIFO buffer and place it in the output Shift Register (OSR), and interact with the state machine once it is running. Data will be transferred one word at a time (32-bit blocks). You can use the PULL and OUT directives.
How do you get data out of a PIO state machine?
Data is first transferred to ISR and then to RX FIFO. This process passes the data to the system. Use the PUSH and IN directives.

How do you program a PIO state machine?
PICO ASM
Get some software (c++ SDK or MicroPython) to set up the PIO state machine to run programs. Writes are done using PIO's 9 instructions, and the PIO state machine performs short binaries for common interfaces like UART, SPI or I2C(available in the PIO library). Determine which PIO instance you want to use. Allocate the instruction to the instruction memory that has enough space and find the available state machine. The result is the cmake file, which describes how these PIO programs and software interact with each other and combines them into an executable on the RP2040-based development board.


In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?

pio_sm_put_blocking(pio,sm,1) (Parses a PIO source file and outputs the assembled version)
The low-level C SDK function is a helper function that blocks the FIFO queue and is responsible for setting the LED to the new color if the queue is full, pushing the data into the TX FIFO of the state machine. To access the function, first include the correct header file, then as it runs, the assembler links the corresponding file, and the LED turns on and off, respectively, as it writes a 1 and a 0.

What role does the pioasm “assembler” play in the example, and how does this interact with CMake?

The pre-booted pioasm "assembler" translates assembly code (input text files) into binaries containing "0s" and "1s" that our machines can understand. It can also be used to generate programs suitable for use with the MicroPython PIO library. The CMake function Pico_generate_pio_header(TARDETPIO_FiLE) calls pioasmand to automatically add the corresponding healder to contain the destination path. Therefore, we don't have to call pioasm directly in the SDK.



# 3.3 Code illustration
![111](https://user-images.githubusercontent.com/113371324/196418504-09bea314-2fb5-4f9a-b376-2f30b960ee88.png)
![222](https://user-images.githubusercontent.com/113371324/196418513-aa2190b0-d24d-4335-be25-023ccbd652d9.png)
![333](https://user-images.githubusercontent.com/113371324/196418517-622a5e96-9994-4cfa-b4a2-065145171495.png)


# 3.4 COLOR BY NUMBER
EXCEL file is uploaded in file 3.4

![image](https://user-images.githubusercontent.com/113371324/209200894-0f7bd99f-684e-4db5-a3bc-b5d84ef51b9e.png)



# 3.5 MODELING TIME 
![image](https://user-images.githubusercontent.com/113371324/209202574-1758bc81-bbed-4f05-9af1-ce744ad579f7.png)

# 3.6 Transmission Spreadsheet
EXCEL file is uploaded in file 3.6

![image](https://user-images.githubusercontent.com/113371324/209203116-bfe94ac5-6175-40cd-bef7-1ad96e398da0.png)


# 3.7 General sequence:
![image](https://user-images.githubusercontent.com/113371324/209203288-33316c29-22e7-4345-96a0-0931e4fdaeeb.png)


# FIFO->SM->WS2812->APDS-9960
## Discussion
What were some strengths/weaknesses of working with paper?

It's easier to draw with more space, but it's harder to adjust the width and length of the sequence diagram. Also, by making comments on paper, it is easier to analyze C code and.pio.h files while understanding the flow of each instruction. Another disadvantage is the need to refer to a large number of worksheets.

What were some strengths/weaknesses of working with spreadsheets?

Spreadsheets help organize data better and make it easier to read, which is one of the main advantages. It's easy to copy and paste for other uses, but the downside is that spreadsheets aren't as simple as charts. One drawback of spreadsheets is the overwhelming amount of data.

How might you approach this task using other tools available to you?

Sequence diagram generator or python write some script files. The SDK documentation is usually a good resource for you to refer to. Take advantage of available ideas to simplify code time.


## Part4 Setup
|  | Environment|
|---    |---|
| OS    |    Windows 11 21H2|
|Laptop | Mi Notebook Pro 15.6 |
|Processor | Intel(R) Core(TM) i7-9750H CPU @ 2.60GHz   2.59 GHz |
