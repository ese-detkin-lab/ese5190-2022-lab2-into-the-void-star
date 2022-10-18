University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    (TODO) Zhuoling Li Working with Chenye Xiong 
        (TODO) zhuoling@seas.upenn.edu
    Tested on: (TODO) MacBook Pro (13-inch, 2018), macOS Monterey 12.6

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)

# 1. Tools to install first:
#### install homebrew
$  /bin/bash -c "$(curl -fsSL
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
（ referrence: https://github.com/homebrew/install#uninstall-homebrew ）
#### install toolchain
```
$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```
And you will see

<img width="431" alt="Screen Shot 2022-10-13 at 19 03 14" src="https://user-images.githubusercontent.com/114199800/195726267-fcad1916-b1f0-488f-9385-ab363e3ced7d.png">

<img width="457" alt="Screen Shot 2022-10-13 at 19 03 25" src="https://user-images.githubusercontent.com/114199800/195726326-c1b050a8-8457-4160-b2bd-6c145e87108a.png">

## 2. Set up the Pico
if your devicesd already setted up, move to the step 3
According to the lab mannual, navigate to the pico examples repos: https://github.com/raspberrypi/pico-examples
They provide a series of exampls that can be easily used
#### Create the pico directory
```
$ cd ~/
$ mkdir pico
$ cd pico
```
#### Copy the pico examples and SDK to the directory
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```
and when the process done you will see 
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /Users/lizhuoling/pico/pico-sdk
Defaulting PICO_PLATFORM to rp2040 since not specified.

...
...
lwIP available at /Users/lizhuoling/pico/pico-sdk/lib/lwip
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/lizhuoling/pico/pico-examples/build
```
Pay attention to the output message about tinyusb module. If error message popped out about tinyusb, you need to troubleshoot it, otherwise the usb connection would be affected.
#### then update the SDK
```
$ cd pico-sdk
$ git pull
$ git submodule update
```
## 3. loadin the code to the RP2040 and run
First, create a "build" directory to contain the pico examples to build the code
```
$ cd pico-examples
$ mkdir build
$ cd build
```
conitune to the build repo
```
$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..
```
and you will see and then the build directory are already set up
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /home/pi/pico/pico-sdk
...
...
-- Build files have been written to: /home/pi/pico/pico-examples/build
```
and then open the terminal,find the 'build' directory
```
$ cd build
```
find the program hello_world to load under the build repo,
```
$ cd hello_wolrd
$ make -j4
```
The make -j4 will build the files and make to seperate examples programs in the hello_world/serial and hello_world hello_world/usb/ directories
you will see the result

<img width="523" alt="Screen Shot 2022-10-13 at 19 03 38" src="https://user-images.githubusercontent.com/114199800/195731134-56539814-32ca-4433-a69b-217fd9eb3630.png">

###Important infroamtion when run the RP2040
First you need to let the RP2040 into storyge mode. After you plug in your RP2040 to your device, You can press Boot button and hold until press the reset button once, you will see the the Rp2040 recognized as RP1 /RP2 on your computer.
And the you can drag the hello_usb.uf2 to the RP1/Rp2, then you can see the RP1/Rp2 quit automatically.

Now you use the terminal to run the code.
first use code below to find your device
```
$ ls /dev/tty.*
```
you can find your device name
like /dev/tty.usbmodem141441
and then use the code below to see the output
```
$ screen /dev/tty.board_name 115200
```
to run the code, the speed required by the board is 115200 bits per second.
you can see the output below

<img width="583" alt="Screen Shot 2022-10-13 at 01 03 36" src="https://user-images.githubusercontent.com/114199800/195733012-81619749-7bd7-41d1-b184-2efb95155653.png">









# Part3
### Part 3.2 Brief response to the reading questions in 3.2 of the PICO C SDK Mannual
#### Q1. Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
ANS: Laptop processors are not designed for bit-tapping. As processors have become faster and faster in terms of overwhelming data processing power, the layers of software and hardware between processors and the outside world have grown in number and size. To cope with the increasing distance between processor and memory, PC-grade processors keep hundreds of running instructions simultaneously on a single core, which is a drawback when trying to switch quickly between hard real-time tasks. That's why it's impractical to use bit tapping on our laptops.
#### Q2. What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
ANS: For slower protocols. In early days when processors were much slower and less tasks,the distance between the processor and memory was shorter, or the layer of software and hardware between processor and the outside was less and smaller, the GPIO could be a better choice. Or On simpler embedded system. LEDs and push buttons.
#### Q3 How do you get data into a PIO state machine?
ANS: From the transfer FIFO buffer, we take a data item and place it in the output Shift Register (OSR). This data is moved one word (32 bits) at a time from FIFO to OSR. OSR is able to move data one or more bits at a time to more distant destinations.\
#### Q4 How do you get data out of a PIO state machine?
ANS :First the state machine neeed to be told which GPIO to output to. and the GPIO also needs to be told that PIO is in control of it. If only pins are used for output, you need to ensure that the PIO driver output enable line is high. The PIO can programmatically drive the line up or down.
#### Q5 How do you program a PIO state machine?
ANS :First, select the PIO instance you want to use. Second, use pio_add_program() to load the program into PIO's instruction memory. Third, use pio_claim_unused_sm() to find the free state machine. Finally, you configure the out state machine to start and run the program by using the helper functions included in the.PIO file.
#### Q6 In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
ANS:  In the example, the pio_sm_put_blocking() function is responsible at the lowest level for telling the PIO to set the LED to a new color. It takes its input from the pixel_rgb.
#### Q7 What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
ANS: We use the pioasm tool to convert assembler code into binary code. We use the CMake function to call pioasm and add the resulting header file to the target's include path. The actual function used pico_generate_pio_header(TARGETPIO_FILE).
### Part 3.3 Make notation on the two document baseed on the information on the pico_SDK mannul
![Page1](https://user-images.githubusercontent.com/114199800/196409969-8d3dbfa4-df53-49d7-aa33-014f95b37a81.jpg)
![Page2](https://user-images.githubusercontent.com/114199800/196410017-aee16013-28cd-48fb-b309-2d7669e9a953.jpg)
![Page3](https://user-images.githubusercontent.com/114199800/196410085-5d5e784d-9643-4dec-b35f-8416ba35670b.jpg)
![Page4](https://user-images.githubusercontent.com/114199800/196410110-cd15ab81-6d1d-4060-bca6-1a524d4498f2.jpg)

### Part 3.4 Color by number
The following excel contains the information that from the RP2040 Datasheet

[Part 3.4 Zhuoling Li.xlsx](https://github.com/Zhuoling11/ese5190-2022-lab2-into-the-void-star/files/9809564/Part.3.4.Zhuoling.Li.xlsx)

### Part 3.5 Modelling Time
By reading the information on the chapter 3 of Pico_C_SDK, leanrned many usefal information like FIFO items, and learning their baisc functions and how it used. after rewriting the code in the part before, I drew the charts below


![Page1 2](https://user-images.githubusercontent.com/114199800/196411477-f90ee673-eae2-4d4d-a972-da984f0c21f1.jpg)
![Page2 2](https://user-images.githubusercontent.com/114199800/196411499-691a2ae1-6e68-4112-871c-cfe341dafc8a.jpg)

### Part 3.6 Zooming IN
After learning from part 5, I assumed some basic information in the charts like the voltage 

<img width="2049" alt="Screen Shot 2022-10-18 at 06 58 32" src="https://user-images.githubusercontent.com/114199800/196412317-1b69d018-5929-4866-85c9-183b93b7e904.png">

[3.6Zhuoling Li.xlsx](https://github.com/Zhuoling11/ese5190-2022-lab2-into-the-void-star/files/9809616/3.6Zhuoling.Li.xlsx)
### Part 3.7 Timing diagram
![3 7](https://user-images.githubusercontent.com/114199800/196412993-36ea3736-f00f-42ae-98af-c4925d400d8c.jpg)

## Conclusion
In this lab, I would prefer use papaer to work. 
The strenths of working with paper: I can draw the plot more clearly and more reader confortale. And for user, it is more easy to operate.
The Weaknesses of working with paper: The data shown drawn on the papaer may not be very accutrate
The stengths of working with spreadsheet: It can show the data relationship very accurate and more easy to konw the information
The Weaknesses of working with spreadsheet: Very hard to use when try to draw the clcok signal map
The Tools: some vedios from the internet and the mannuls contains on this lab.

## PART4 HELLO, BLINKENLIGHT
Some steps when finish this part guided by the lab
1. Creating a new folder outside the pico-examples, in my condition, it called 'test'
2. Coping some documents from the pico-examples folder and modifying the CMakelists files, WS 2812C code
3. Make a new Build folder to contain the program
4. Drop the new uf2 file to the RP2040 and Run the file as mentioned in the Part 1
The code is below


The out put

![IMG_5437](https://user-images.githubusercontent.com/114199800/196416614-6f0809eb-544b-4cfa-88a2-79422d2576a8.GIF)

