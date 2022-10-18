University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) YOUR NAME HERE
        (TODO) LinkedIn, personal website, twitter, etc.
    Tested on: (TODO) MacBook Pro (14-inch, 2021), macOS Monterey 12.5.1

(TODO: Your README)

# ESE-519-Lab-2A
ESE 519 LAB 2A

Akshaya Nidhi Bhati: University of Pennsylvania ESE 5190: Introduction to Embedded Systems, Lab 2A
LinkedIn: https://www.linkedin.com/in/akshaya-nidhi-bhati-6467841b3/?originalSubdomain=in

Tested on:  HP Pavilion 14, Windows 11

# Part 3: #

## PIO ##
 
After reading chapter 3 in the Pico C SDK manual as given in resources of my setup guide https://github.com/AkshayaBhati/ESE-519-Lab-2-Setup-Guide/blob/main/README.md
 we can understand how the PIO Module interacts with a WS2812 module. 
 
 **Why is bit-banging impractical on your laptop, despite it having a
much faster processor than the RP2040?** <br>
Bit Banging is impractical for our laptop as the processor is not designed for it as it has CPU polling on GPIO pins which affects the real-time performance. Even if our laptop has a faster processor nowadays the layers between the processor and the outside world of hardware and software have also increased with time in size and number.Therefore there are thousands of instructions at a time on a single core. This affects the real-time performance of the system. It's even harder to make sure that GPIO read write occurs on the required cycle. <br>

**What are some cases where directly using the GPIO might be a
better choice than using the PIO hardware?** <br> 
The cases where directly using the GPIO might be a better choice than using the PIO hardware includes Blinking of the LED. Then we need to toggle GPIOs via hardware interrupts which are less set of instructions than using PIO. PIO will be a better choice than using GPIO for complex tasks. Other than this going through the PIO adds latency when accessing it for one-time or outside the continuous loop. <br>

**How do you get data into a PIO state machine?** <br>
It is going to OSR from TX FIFO using Pull instruction.<br>

**How do you get data out of a PIO state machine?** <br>
It is going to OSR from TX FIFO using pull instruction.<br>

**How do you program a PIO state machine?** <br>
In the PIO library the programs are included for UART, I2c ,etc that is for common interfaces so we don't have to write a program for these. The PIO has nine instructions in total mentioned below: <br>
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
The low-level C SDK function that is directly responsible for telling the PIO to set the LED to a new color is pio_sm_put_blocking() function. As using this we can directly push data into state machine's TX FIFO as when the TX FIFO is full it stalls the processor this leds to LED being turned on and off when writing 1 and 0 respectively. This function is accessed form the main "application" code using put_pixel() function. As given in the example code we are calling put_pixel() function. <br>

**What role does the pioasm “assembler” play in the example, and
how does this interact with CMake?** <br>
Pioasm: it is the PIO assembler included in the SDK. In the example it processes an input text file of PIO assembly that might contain multiple programs and it writes out the ready-to-use assembled programs. These programs containing constant arrays are emitted in the form of C headers.  
It interacts with the CMake using the pico_generate_pio_header(TARGET PIO_FILE) function as it invokes pioasm and the header is also added in the include path of the target using this. Therefore, we do not have to invoke pioasm in the SDK directly. <br>

## Spreadsheet of initial PIO register states ##

https://docs.google.com/spreadsheets/d/13l0bCfyE5TmSJbdV2kjk0inrah82hIrh6xzRkMsBtd8/edit?usp=sharing <br>

Few general things to know: <br>
Here we are using the PIO0 as the PIO instance. The SM0 state machine will be used with the PIO instance. The default pin of mcu or the pin 2 of mcu is the pin this state machine is configured to control. This states machine's clock cycle is 800KHz. the clock divisor that is this state machine's clock scaled down relative to the system clock is 15.625. In the right shift direction this state machine shift bits out of its "Output shift register"? <br>

## Paper Model: ##

<img width="356" alt="2a1" src="https://user-images.githubusercontent.com/114259992/196343669-858b59a5-b30d-48b3-a3b1-b69cdc92d675.png">

<img width="361" alt="2a2" src="https://user-images.githubusercontent.com/114259992/196343685-3b29457e-4ae9-426d-ab23-cd975bd1d427.png">


The basic circuitry WS2812 LED needs to operate is data pins, a capacitor, a resistoe with value 150 and the supply. You connect a WS2812 to a microcontroller by connecting GNDs of both microcontroller and WS2812, and then to a DI pin of WS2812 the GPIO pin of microcontroller is controlled. It translates bits to color values by making the LED turn On and off really fast so that we can see the color we want as generated. Using the data pin of microcontroller we will make DI high and low. OUT instruction and the low side pin tells a WS2812 that it's data sending is done. To send a single color value 8 bits are used. If we connect DO of one to DI of another module and so on we can send data to more than one WS2812 in a chain. If you send more bits than packet then it will not give the right color. 

# Part 4: #

Follow the setup guide https://github.com/AkshayaBhati/ESE-519-Lab-2-Setup-Guide/blob/main/README.md
After running the Hello World sample code. We will try the LED Blinking sample code. Here in our final code we are combining both of our sample codes to form an output. Here we are taking the input from the keyboard specifically character 'r', 'g' and 'b'. If we are getting an input 'r' then Red LED color will glow, if the input is 'g' then Green LED will glow, and if the input is 'b' then the Blue LED color glow. 

Let's try to get the LED Blinking. So we will make the cmake file and the Build the LED code using the following commands 
```
cmake .. -G "MinGW Makefiles"
.
.
.
mingw32-make -j6

```
Just set the GPIO pin high and add one header file to the Blink Example to make it work. 

Let's get started with our **Final Task**

Here we will try to make this work in a seperate folder. 
We will do the above steps again and copy the pico_sdk_import file to the folder. Then we will generate a build folder, then generate cmake files and the build it to make the UF2 file. Then we will run it using PuTTY. 






https://user-images.githubusercontent.com/114259992/196354763-01e3d8c7-099b-4e12-a0ce-7bcc592962af.mp4




### At the end of your writeup of section 3, reflect on the tools you used for modeling from a user interface design perspective. ###

**What were some strengths/weaknesses of working with paper?**

strengths: 
It is easier to use, Ideas can be jotted down more quickly

weaknesses: 
If something goes wrong then doing changes is difficult, numbering the sheets

**What were some strengths/weaknesses of working with spreadsheets?**

strengths: 
As compared to others much clear, time efficient, easy to share, easier for large data. 	

weaknesses: 
It is not good for small concepts. 

**How might you approach this task using other tools available to you?**

We can use some softwares for making the timing diagram. We can also use tools to form flow charts of the code for better understanding. We can even use an IDE for the code. 
