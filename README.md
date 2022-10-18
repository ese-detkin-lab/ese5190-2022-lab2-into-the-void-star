University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    name:Ze Li
    twitter:Kopred7
    Tested on:  MacBook Pro (16-inch, 2021), macOS Monterey 12.6

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)
# Answers for 3.2Q

**Q1:Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?**

A1:First,since the bit-bangning is that uses the software to realize I2C protocol and the bit-bangning can just provide a low inefficient for cpu,cpu in our laptop need a high efficient way to use I/O serials.Ans alos bit-bangning need users are responsible for their own synchronization and timing and so on,which would increase workload for users and decrease sense of user.

**Q2:What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?** 

A2:First, GPIO means General Purpose Input / Output which can allow users to use them to drive the LED light or something directly.But for PIO which is an abstract concept,Users need to define them manually.Therefor,GPIO is better than PIO.

**Q3How do you get data into a PIO state machine?**

A3:For the input,we can use the TXn FIFO to get the data from PIO state machine.And then ,we can use the out command which can allow the state machine move a data from OSR to Scratch register.

**Q4:How do you program a PIO state machine?**

A4:By writting a pio program such as ws2812.pio which will use the pio asm-like instructions,we can generate a .pio.h file while building.In addition,if we want to generate the .pio.h file, we should edit the CMakelists.txt.

**Q5:In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color?**

A5:In ws2812.c, the function is put_pixel(uint32_t pixel_grb).But,actually,pio_sm_put_blocking(PIO pio, uint sm, uint32_t data) is the real function.

**Q6:How is this function accessed from the main “application” code?**

A6:when the main code need to put color to NeoPixel,the program will call the function put_pixel() and the function will call another function named pio_sm_put_blocking which is defined in pio.c.

**Q7:What role does the pioasm “assembler” play in the example, and how does this interact with CMake?**

A7:The pioasm "assembler" allow users to define the function of GPIO to solve the inefficient problem which is caused by different communication rates of each communication protocol.In CMakeLists.txt, we can use pico_generate_pio_header to generate a .pio.h file.Such as pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)


# 3.3 Follow the flow

![img](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/3.3.png)

# 3.4 spreadsheet of initial PIO register states 

By reading the ws2812.pio.h and pio.c/h and ws2812.c, we can find the value of the registers.So,we can get the spreadsheet like the following link:

[spreadsheet of initial PIO register states ](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/3.4_1.xlsx)

# 3.5 MODELING TIME 

![img](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/3_5.jpeg)

# 3.6 ZOOMING IN 
Pick the color 0x800000 in GRB,which can be rewrote to 1000 0000 0000 0000 0000.So, only first bit is 1 and other bit is 0.For convenience,we only take first and second bits as example since other bits' periods as same as second bit's.

[transmission spreadsheet](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/3_6.xlsx)

# 3.7 timing diagram  
pick the RGB color 0x00f000 which can be rewrote 0xf00000 in GRB form.

![img](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/TIMING.jpeg)

# Part 4 Hello Blink

## The first program is USB_C

1.Create a new folder somewhere outside the examples folder

2.Copy the USB_C.c pico_sdk_import.cmake into this folder

3.write the CMakelists.txt as following:


```
cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(test_project)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})
pico_sdk_init()
include(example_auto_set_url.cmake)
add_executable(hello_usb hello_usb.c)
pico_enable_stdio_usb(hello_usb  1)
pico_enable_stdio_uart(hello_usb  1)
pico_add_extra_outputs(hello_usb )
target_link_libraries(hello_usb  pico_stdlib)
``` 

open the terminal and link screen to RP2040, we can see:

![img](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/LAB2A_code/USB_C/hello_world.jpeg)

## Blink
 In set_neopixel_color() function,we need to transfer RGB to GRB.So,the function could be defined in ws2812.c as following:
 
 ```
 void set_neopixel_color(uint32_t color) {
    uint32_t r = color & 0xff0000;
    uint32_t g = color & 0x00ff00;
    uint32_t b = color & 0x0000ff;
    uint32_t grb = ( r>>8| g<<8| b);
    // todo get free sm
    put_pixel(grb);

} 
 ```
 
 The main code is :
 
 ```
 while(true){
    //output example
    int flag = rand() % 3;
    printf(color_table[flag].name);
    printf("\n");
    set_neopixel_color(color_table[flag].color);
    
    /* input example
    while((c=getchar_timeout_us(0))!= EOF){
            putchar_raw(c);
            my_toggle_flag=1;
        }
    
        if(my_toggle_flag==1){
            printf("send a char");
            set_neopixel_color(0xff0000);
            my_toggle_flag=0;
        }
        else{
            set_neopixel_color(0x000000);
        }*/

        sleep_ms(1000);
        //sleep_ms(5);
    }
 ```
 For output example, we can see:
 
 ![gif](https://github.com/kop123meter/ese5190-2022-lab2-into-the-void-star/blob/main/LAB2_A/LAB2A_code/Blink/tutieshi_640x360_11s.gif)
 
 For input example, we can see:
 
 If we press a button in keyboard, we can see the neopixel will be lighted.
