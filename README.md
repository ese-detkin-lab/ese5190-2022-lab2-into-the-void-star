University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Chongyuan Zhang
    
        Linkedin: https://www.linkedin.com/public-profile/settings?trk=d_flagship3_profile_self_view_public_profile
    Tested on: Lenovo Legion (R9000X), windows 11

# Lab 

## 3.2 Questions Responses
#### 1) Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?

    Because the layer number and size between hardware and software have increased. And now it is a big number. So it will cause errors more easily.
    
#### 2) What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
   
    The PIO is more versatile than GPIO since it can be programmed to be conncected. But GPIO pin has hard-wired connections to one or more (but not all) peripherals. Therefore, LED strings & buttons keeping are better with GPIO.
    
#### 3) How do you get data into a PIO state machine?
    
    I can get the data though the FIFO buffer. And then put them in the output shift register (OSR).
    
#### 4) How do you get data out of a PIO state machine?
    
    The output shift register (OSR) can shift the data out.

#### 5) How do you program a PIO state machine?
   
    We set the PIO instance and load programming with C++ SDK or MicroPython.
    
#### 6) In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the main “application” code?
   
    Use the "pio_sm_put_blocking( )" function. We can link the corresponding files when we include the headers, which will find the value from the state machine, and pop out them.

#### 7) What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
    
    The pioasm assmebler generates the binary file from the .pio files. As the CMake function  pico_generate_pio_header(TARGET PIO_FILE) takes care of invoking pioasm and adding the generated header to the include path of the target TARGET for you.

## 3.3 Photos or Scans of Annotated Code Printouts
WS2812.C

<img width="526" alt="68040018a6363ef4c88a0b6763b01f8" src="https://user-images.githubusercontent.com/114255407/196352892-d7628c9d-80e8-473f-9e09-3dfa514d947f.png">
<img width="488" alt="1573434d743bf39ceadd53d5a74beb8" src="https://user-images.githubusercontent.com/114255407/196352911-beac4202-47d5-48dd-8753-b2da6c576674.png">
<img width="535" alt="0c3bc92885b5ccc0b94b6cd4039284d" src="https://user-images.githubusercontent.com/114255407/196352928-ed199262-e466-4cae-b2d7-09cd018bc7f5.png">

ws2812.pio.h

![403256377260324524](https://user-images.githubusercontent.com/114255407/196355178-663357d4-370b-4c76-8e0c-f46699803f02.jpg)
![280885013862070077](https://user-images.githubusercontent.com/114255407/196355199-6db0dd75-75e4-4dc5-9548-a5080233f7e1.jpg)
![198018244341097675](https://user-images.githubusercontent.com/114255407/196355216-957fecab-e5ff-4bd0-b515-141cad09437f.jpg)

## 3.4 Spreadsheet of initial PIO register states

<img width="524" alt="ff8c0ae2ecfec676a77bed1e3bbaf23" src="https://user-images.githubusercontent.com/114255407/196347547-f09ce83d-b4fb-4af2-953c-f2a396236898.png">
<img width="526" alt="47a9d1be5eb4023fdbbd4dae0e2fcdf" src="https://user-images.githubusercontent.com/114255407/196347565-782115ca-7849-4aa2-8bb5-2aed759a140e.png">

## 3.5 A photo or san of paper model
![image](https://user-images.githubusercontent.com/114255407/196347902-e2c541fa-82fc-4dbb-b7f4-a15a70a3f2a7.png)


## 3.6 Packet Transmission Spreadsheeet
![image](https://user-images.githubusercontent.com/114255407/196348052-b0b67a38-03ff-4b08-b477-7cd5370f8178.png)


## 3.7 Plished Timing Diagram
![image](https://user-images.githubusercontent.com/114255407/196348174-d8784a71-4a0e-4f39-8b00-e8e2c3fbbfa5.png)


## 4 USB + WS2812 Code Folder
 - Uploaded the "pio" Folder.
