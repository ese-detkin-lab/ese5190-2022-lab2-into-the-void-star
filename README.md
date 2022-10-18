# ESE 519-LAB 2A
```   
 Muyuan sheng
 Email:shmuyuan@seas.upenn.edu
 Tested on: Legion Y9000 (i7), windows 11    

```  
## 3.2
* Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?   
    The computer has many other processes running; if the processor is interrupted will have lots of communication errors.
* What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?  
    GPIOs are better suited for less complex tasks such as input and output, I2C or SPI data lines, outputting PWM waveforms, etc.
* How do you get data into a PIO state machine?  
    Pull instruction takes a data item from the transmit FIFO buffer and places it in the output shift register.
* How do you get data out of a PIO state machine?  
   OSR uses the out instruction to shift this data out.
* How do you program a PIO state machine?  
   We can create a .pio file using C to set up the PIO state machine.
* In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?  
   "pio_sm_put_blocking", Write data to the TX FIFO queue. Block the TX FIFO queue if it is full.  
* What role does the pioasm “assembler” play in the example, and how does this interact with CMake?  
    To compile assembly code into a human-readable format. 
 ## 3.3
Please check the [ws2812.c](https://github.com/ILandingI/519-LAB2A/blob/14f140667492abf46f4ceb0ca74163ff75d310b6/ws2812.c) and [ws2812.h](https://github.com/ILandingI/519-LAB2A/blob/c693200a85aa2aecf698b595c7afc3d4ef9877b1/ws2812.h)

##  3.4
Please check [3.4.xlsx](https://github.com/ILandingI/519-LAB2A/blob/90f021a891cc5453c4455721e70423a7f292f400/3.4.xlsx)

## 3.5
![3 5](https://user-images.githubusercontent.com/96441697/196379968-d00d1451-ed26-4b53-9dc9-f3d11494ece7.PNG)

## 3.6
Please check [3.6.xlsx](https://github.com/ILandingI/519-LAB2A/blob/b896ce90ec667b72470129840af3a3eff7c5f0e7/3.6.xlsx)

## 3.7
![3 7](https://user-images.githubusercontent.com/96441697/196389416-46116d35-33b4-4ba8-8316-1d08bcfdd872.png)

## 4 Hello, Blinkenlight!  
It will blinken while print Hello World.
![Screenshot 2022-10-14 225735](https://user-images.githubusercontent.com/96441697/196393627-b2a7fa48-d0e4-44c5-b92f-593e1a1c6ace.png)
  [GIF](https://user-images.githubusercontent.com/96441697/196393320-c1b593d3-fcc5-4953-a8ff-e53d7e21b608.gif)



