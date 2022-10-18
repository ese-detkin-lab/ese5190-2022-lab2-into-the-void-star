University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yash Budhe
        LinkedIn: https://www.linkedin.com/in/yash-mb-a1723812b
    Tested on: HP Envy x360 Convertible, 11th Gen Intel(R) Core(TM) i7-1165G7 @ 2.80GHz 

# 3.2 PIO

The questions given in the section 3.2 are answered in the following file - "Answers to Qs in 3.2.pdf". The source for information and learning are RP2040 Datasheet and Raspberry Pi Pico C/C++ SDK manual. 

Link - https://github.com/yash-mb/ese5190-2022-lab2-into-the-void-star/blob/8c79a5e3339b28333234f7ff783bbc1e88a8266b/Answers%20to%20Qs%20in%203.2.pdf


# 3.3 Code Annotations

The codes in ws2812 folder of pico-examples has been annotated and numbered according to instructions given - details can be found in "Lab2_assign.pdf" page 19. For better visualization and flow the annotations are done in microsoft ppt and can be accessed in "Code Annotations.pptx".

Link - https://github.com/yash-mb/ese5190-2022-lab2-into-the-void-star/blob/8c79a5e3339b28333234f7ff783bbc1e88a8266b/Code%20annotation.pptx

# 3.4 Registers

We have selected Pi0 as base and value of registers is found using the RP2040 datasheet.

Link - https://github.com/yash-mb/ese5190-2022-lab2-into-the-void-star/blob/6939f813a4b906ff0e74e16c7b73f252bca62d65/Q3.4%20-%20Registers.xlsx


# 4. Hello Blinkenlight

Welcome to our project. We have leveraged the pico-examples - hello_usb.c and ws2812.c, merging them together to work as a single coherent program. You can find all the required files in the "Q4" folder. It's recommended that you download the folder and refer to the setup guide to build the program. Copy-paste the .uf2 file on microcontroller and witness the magic!

## What's happening here?

Depending upon which key is pressed, the program blinks the corresponding color in the LED. Here, we have choosen the keys - 4,5, and 6 which blinks red, green, and blue. The program starts with a message "Enter any number". You need to press the number key and then press enter. After blinking followed by a little pause, it resets and asks for another number.

This can be visualized in the following:

<img src = "Other files/Lab2-Q4.gif" width="600" height="600"/>

