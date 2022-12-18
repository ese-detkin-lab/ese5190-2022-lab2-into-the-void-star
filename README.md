University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

Praveen Raj Uma Maheswari Shyam Sundar
    LinkedIn: www.linkedin.com/in/praveen-raj-u-s-317981135
Tested on: Asus ROG Flow X13, Windows 11
---------------------------------------------------------------------------------------------------------------------------------------------
# 3.2
----------------------------------------------------------------------------------------------------------------------------------------------
**1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?**
A: Bit-banging is actually the method of data-transmission that leverages the software in place of the hardware. The reason why our laptop is not ideal for the case is because the processor is not customized for big-banging inspite of it's high processing power. For Bit-banging to work properly the processor would have to be customly set to the unique time-loop. And other parallel processes might interrupt the bit-banging.

**2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?**
A: Cases where using the GPIO might be better are when the hardware uses general peripherals such as I2C, UART etc or when bit-banging is used. 

**3. How do you get data into a PIO state machine?**
A: Data can be taken into the a PIO State machine by moving it from the FIFO buffer to the Output Shift Register.

**4. How do you get data out of a PIO state machine?**
A: Pull Instruction -> To take out the data from the TX FIFO buffer 
   Out Instruction -> Data out from TX FIFO.
   
**5. How do you program a PIO state machine?**
A: We can program a PIO State machine by Writing a ".PIO" file in PIO assembly language. 

**6. In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?**
A: pio_sm_put_blocking() -> Sets the LED 
   put_pixel() -> Defines the RGB Values
   
**7. What role does the pioasm “assembler” play in the example, and how does this interact with CMake?**
A: The Pioasm is the assembler that converts machine code to binary. It Processess the PIO input assembly file and generates functions for every program.

---------------------------------------------------------------------------------------------------------------------------------------------------------------
# 3.3: Follow the Flow
---------------------------------------------------------------------------------------------------------------------------------------------------------------
![image](https://user-images.githubusercontent.com/114270637/202805664-57207d31-1cab-48d2-8ef3-5c05815c58e7.png)

![image](https://user-images.githubusercontent.com/114270637/202805768-1f6f58ab-a5dd-433b-a52b-69da087ae700.png)


![image](https://user-images.githubusercontent.com/114270637/202805838-3acd3634-6de9-4ec9-bbed-fcb3ca4e19f5.png)


![image](https://user-images.githubusercontent.com/114270637/202805853-db823212-8ccc-4bd3-abd6-05939a58dbe0.png)


---------------------------------------------------------------------------------------------------------------------------------------------------------------

# 3.4: Registers Color:
[3.4 Registers.xlsx](https://github.com/Praveen-Raj-u-s/ese5190-2022-lab2-into-the-void-star/files/10254670/3.4.Registers.xlsx)

--------------------------------------------------------------------------------------------------------------------------------------------------------------

# 3.5: Bitloop Paper Modelling:

![Bitloop](https://user-images.githubusercontent.com/114270637/208320784-a4bcd657-4c31-45d2-a606-050a8837447f.jpg)


--------------------------------------------------------------------------------------------------------------------------------------------------------
# PART 4
---------------------------------------------------------------------------------------------------------------------------------------------------------

![Part4](https://user-images.githubusercontent.com/114270637/202566242-f4b87490-ab9c-466d-b8fa-78984efcb94c.gif)
