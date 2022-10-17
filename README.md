University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yash Budhe
        LinkedIn: https://www.linkedin.com/in/yash-mb-a1723812b
    Tested on: HP Envy x360 Convertible, 11th Gen Intel(R) Core(TM) i7-1165G7 @ 2.80GHz 

# Q4. Hello Blinkenlight

Welcome to our project. We have leveraged the pico-examples - hello_usb.c and ws2812.c, merging them together to work as a single coherent program. You can find all the required files in the "Q4" folder. It's recommended that you download the folder and refer to the setup guide to build the program. Copy-paste the .uf2 file on microcontroller and witness the magic!

## What's happening here?

Depending upon which key is pressed, the program blinks the corresponding color in the LED. Here, we have choosen the keys - 4,5, and 6 which blinks red, green, and blue. The program starts with a message "Enter any number". You need to press the number key and then press enter. After blinking followed by a little pause, it resets and asks for another number.

This can be visualized in the following:

<img src = "Other files/Lab2-Q4.gif" width="600" height="600"/>

