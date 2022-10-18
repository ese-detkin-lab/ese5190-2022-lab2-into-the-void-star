University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Akshaya Nidhi Bhati
    LinkedIn: https://www.linkedin.com/in/akshaya-nidhi-bhati-6467841b3/?originalSubdomain=in
    Tested on: HP Pavilion (14-inch, 2021), Windows 11
    
# Part 3: #

## PIO ##
 
After reading chapter 3 in the Pico C SDK manual as given in the resources of my setup guide https://github.com/AkshayaBhati/ESE-519-Lab-2-Setup-Guide/blob/main/README.md
 we can understand how the PIO Module interacts with a WS2812 module. 
 
 **Why is bit-banging impractical on your laptop, despite it having a
much faster processor than the RP2040?** <br>
Bit Banging is impractical for our laptop as the processor is not designed for it as it has CPU polling on GPIO pins which affect the real-time performance. Even if our laptop has a faster processor nowadays the layers between the processor and the outside world of hardware and software have also increased with time in size and number. Therefore there are thousands of instructions at a time on a single core. This affects the real-time performance of the system. It's even harder to make sure that GPIO read-write occurs on the required cycle. <br>

**What are some cases were directly using the GPIO might be a
better choice than using the PIO hardware?** <br> 
The cases where directly using the GPIO might be a better choice than using the PIO hardware includes Blinking of the LED. Then we need to toggle GPIOs via hardware interrupts which are fewer sets of instructions than using PIO. PIO will be a better choice than using GPIO for complex tasks. Other than this going through the PIO adds latency when accessing it for one-time or outside the continuous loop. <br>

**How do you get data into a PIO state machine?** <br>
It is going to OSR from TX FIFO using Pull instruction.<br>

**How do you get data out of a PIO state machine?** <br>
It is going to OSR from TX FIFO using pull instructions.<br>

**How do you program a PIO state machine?** <br>
In the PIO library, the programs included for UART, I2c, etc that is for common interfaces so we don't have to write a program for these. The PIO has nine instructions in total mentioned below: <br>
1.	JMP <br>
2.	WAIT <br>
3.	PUSH <br>
4.	PULL <br>
5.	IN <br>
6.	OUT <br>
7.	SET <br>
8.	IRQ <br>
9.	MOV <br>

PIO assembly is the textual format describing a PIO program. In the output, each command has one instruction. <br>

**In the example, which low-level C SDK function is directly
responsible for telling the PIO to set the LED to a new color? How
is this function accessed from the main “application” code?** <br>
The low-level C SDK function that is directly responsible for telling the PIO to set the LED to a new color is the pio_sm_put_blocking() function. By using this we can directly push data into the state machine's TX FIFO as when the TX FIFO is full it stalls the processor which leads to LED being turned on and off when writing 1 and 0 respectively. This function is accessed from the main "application" code using the put_pixel() function. As given in the example code we are calling the put_pixel() function. <br>

**What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?** <br>
Pioasm: it is the PIO assembler included in the SDK. In the example, it processes an input text file of PIO assembly that might contain multiple programs and it writes out the ready-to-use assembled programs. These programs containing constant arrays are emitted in the form of C headers.  
It interacts with the CMake using the pico_generate_pio_header(TARGET PIO_FILE) function as it invokes pioasm and the header is also added in the include path of the target using this. Therefore, we do not have to invoke pioasm in the SDK directly. <br>

## Follow the flow ##

The explanation for the files below is done thoroughly in the uploaded PDFs for each along with the Line wise execution of the Program. <br>
• ws2812.c <br>
• generated/ws2812.pio.h <br>

https://github.com/AkshayaBhati/ese5190-2022-lab2-into-the-void-star/tree/main/3.3%20Scans%20of%20annotated%20code%20printouts
Here is a link to access those files

## Spreadsheet of initial PIO register states ##

https://docs.google.com/spreadsheets/d/13l0bCfyE5TmSJbdV2kjk0inrah82hIrh6xzRkMsBtd8/edit?usp=sharing <br>

Few general things to know: <br>
Here we are using the PIO0 as the PIO instance. The SM0 state machine will be used with the PIO instance. The default pin of MCU or pin 2 of MCU is the pin this state machine is configured to control. This states machine's clock cycle is 800KHz. the clock divisor that is this state machine's clock scaled-down relative to the system clock is 15.625. In the right shift direction this state machine shift bits out of its "Output shift register"? <br>

## Paper Model: ##

<img width="356" alt="2a1" src="https://user-images.githubusercontent.com/114259992/196343669-858b59a5-b30d-48b3-a3b1-b69cdc92d675.png">

<img width="361" alt="2a2" src="https://user-images.githubusercontent.com/114259992/196343685-3b29457e-4ae9-426d-ab23-cd975bd1d427.png">


The basic circuitry WS2812 LED needs to operate is data pins, a capacitor, a resistor with a value of 150, and the supply. You connect a WS2812 to a microcontroller by connecting the GNDs of both microcontroller and WS2812, and then to a DI pin of WS2812 the GPIO pin of the microcontroller is controlled. It translates bits to color values by making the LED turn On and off really fast so that we can see the color we want as generated. Using the data pin of the microcontroller we will make DI high and low. OUT instruction and the low side pin tell a WS2812 that its data sending is done. To send a single color value 8 bits are used. If we connect the DO of one to the DI of another module and so on we can send data to more than one WS2812 in a chain. If you send more bits than a packet then it will not give the right color. <br>

![Part 3 5](https://user-images.githubusercontent.com/114259992/196408750-732a5116-5209-4b6d-aedc-787e2aa0aec4.jpeg)

As you can see Here I'm taking Green Color so according to the Loop example given the first Current Instruction L1 will occur right shift and therefore the value will become 0X007F8000, here LED pin state will be low. So after that when L2 occurs then the value remains the same. After that L3 will occur and the value will remain same. Lastly L4 but the loop still goes on. Then again right shift will occur. The LED pin state changes to low again after high ones in the middle. The FIFO is always Full as there is always some value in it.  <br>

The Timing Diagram is as shown below: <br> 

![Part 3 5 diag](https://user-images.githubusercontent.com/114259992/196409947-02d70c26-f6c0-49de-aad5-90dba4d2e1ed.jpeg)

## Your complete packet transmission spreadsheet ##

Here the values we were calculating earlier for 1-bit are now calculated for 32-bit. You can access the Spreadsheet using the following link: <br>
https://github.com/AkshayaBhati/ese5190-2022-lab2-into-the-void-star/blob/main/Part%203.6%20ESE%20519.xlsx

## Your polished timing diagram ##

The timing diagram to summarize the behavior of the system from the FIFO message delivery all the way to the LED visibly changing color is as follows: <br>
![Timing Diagram  3 7](https://user-images.githubusercontent.com/114259992/196412038-66dddbea-b16f-42d9-9ede-90da9e9e1e1f.PNG)

# Part 4: #

Follow the setup guide https://github.com/AkshayaBhati/ESE-519-Lab-2-Setup-Guide/blob/main/README.md
After running the Hello World sample code. We will try the LED Blinking sample code. Here in our final code, we are combining both of our sample codes to form an output. Here we are taking the input from the keyboard specifically characters 'r', 'g', and 'b'. If we are getting an input 'r' then Red LED color will glow, if the input is 'g' then Green LED will glow, and if the input is 'b' then the Blue LED color glow. 

Let's try to get the LED Blinking. So we will make the cmake file and the Build the LED code using the following commands 
```
cmake .. -G "MinGW Makefiles"
.
.
.
mingw32-make -j6

```
Just set the GPIO pin high and add one header file to the Blink Example to make it work. As you can see below:



![LED](https://user-images.githubusercontent.com/114259992/196418727-6ccecc6b-3b34-449b-975d-711fc7ed3722.gif)




Let's get started with our **Final Task**

Here we will try to make this work in a separate folder. 
We will do the above steps again and copy the pico_sdk_import file to the folder. Then we will generate a build folder, then generate cmake files, and the build it to make the UF2 file. Then we will run it using PuTTY. 






https://user-images.githubusercontent.com/114259992/196354763-01e3d8c7-099b-4e12-a0ce-7bcc592962af.mp4




### At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective. ###

**Brief discussion of decisions you made while working with your modeling documents.**
While working on my modeling document discussion of decision were like the register values especially the assumptions that we should take to calculate them, and how the timing diagram works.

**What were some strengths/weaknesses of working with paper?**

strengths: 
It is easier to use, and Ideas can be jotted down more quickly

weaknesses: 
If something goes wrong then doing changes is difficult, numbering the sheets

**What were some strengths/weaknesses of working with spreadsheets?**

strengths: 
As compared to others much clear, time efficient, easy to share, and easier for large data. 	

weaknesses: 
It is not good for small concepts. 

**How might you approach this task using other tools available to you?**

We can use some software for making the timing diagram. We can also use tools to form flow charts of the code for better understanding. We can even use an IDE for the code. 
