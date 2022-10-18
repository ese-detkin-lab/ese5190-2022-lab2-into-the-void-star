# ESE519-Lab2-intoTheVoid
Lab 2 of ESE 5190 Embedded Systems 

## Lab 2A - Part 3 to 5

### 3.2
**• Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?** 
Laptop processors are much faster to handle such instructions with low computational requirement which is why real time executions are not preferred.

**• What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?**
PIO requires the user to program the IO port while GPIO is used in general purpose conditions. Thus, whenever we need a PIN for simple read or write functions, it’s better to use GPIO.

**• How do you get data into a PIO state machine?**
When data is popped from the FIFO queue to the OSR, the PIO can draw one bit at a time from the OSR. This could be the MSB or LSB based on configuration. 

**• How do you get data out of a PIO state machine?**
When the RX Register of FIFO is taking inputs, we can write one bit at a time from PIO to the FIFO

**• How do you program a PIO state machine?**
Using PIO ASM.
 
**• In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?**
pio_sm_put_blocking() is used to set the LED color. The CMAKE file has links to pico_stdlib and hardware_pio which helps “main” access this code.

**• What role does the pioasm “assembler” play in the example, and how does this interact with CMake?**
The pioasm is an assembler, which is used to convert the assembly code in the “.pio” file into low level machine code, used to directly control the PIO module. Within the CMakeLists.txt file, there is an instruction pico_generate_pio_header(TARGET PIO_FILE) which invokes the assembler for us.


### 3.3
The following are the annotated codes for .c and .h files
[ws2812_c_code_annotated.pdf](https://github.com/joyendra/ESE519-Lab2-intoTheVoid/files/9807371/ws2812_c_code_annotated.pdf)
[ws2812_h_annotated.pdf](https://github.com/joyendra/ESE519-Lab2-intoTheVoid/files/9807374/ws2812_h_annotated.pdf)

### 3.4
The registers and its description follows:								
![image](https://user-images.githubusercontent.com/36339255/196361476-9145de6e-ec80-47fe-adcf-42a88baee9cb.png)

### 3.5
Single packet transmission looks something like this!
![image](https://user-images.githubusercontent.com/36339255/196362091-2a1db897-c784-4511-8f43-fe5c5386ea98.png)
![image](https://user-images.githubusercontent.com/36339255/196362146-896cab5d-dfb4-4adb-9d56-3e5ba68f173c.png)

### 3.6 and 3.7
Here is how the timing diagram for GRB LED with a APDS9960 sensor look like:
[3.7-3.6.xlsx](https://github.com/joyendra/ESE519-Lab2-intoTheVoid/files/9807464/3.7-3.6.xlsx)

### 4
The code can be found in this folder. The output as expected was:
![ezgif com-gif-maker](https://user-images.githubusercontent.com/36339255/196365282-9c188911-7d40-4721-8982-7c49ab4d6f52.gif)

