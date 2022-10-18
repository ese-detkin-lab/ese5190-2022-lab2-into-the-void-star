University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

 Shuhan Qian    
   https://www.linkedin.com/in/shuhan-qian-53014524a/    
   email:qiansh@seas.upenn.edu    
Tested on: XiaoXinPro16 Lenovo, AMD Ryzen 7 5800H(3.2GHZ)  

3.3 PDF for code annotation  
https://github.com/QSHANSSS/ese5190-2022-lab2-into-the-void-star/blob/main/3.3.pdf  
This link is about code and its annotation of ws2812.c and ws2812.pio.h  

3.4 Spreadsheet of PIO register states
To fetch the value of registers. I used pointer to print values that stored at the address(base+offset by for loop) of regs on my serial.  
The code screenshot and serial results are below:

![950a4f49fa070b56a3599f893e51029](https://user-images.githubusercontent.com/64452307/196340079-5e4d1375-e3ff-4976-9340-2b12eb5b4797.png)
<img width="353" alt="image" src="https://user-images.githubusercontent.com/64452307/196340209-a31a284e-6ccb-4258-bf0f-a682fc1fee61.png">

The link is about detailed analysis for each bit of regs.
https://github.com/QSHANSSS/ese5190-2022-lab2-into-the-void-star/blob/main/3.4.xlsx  

3.5 A scan of Model  
This part should understand the code from ws2812.pio. The line18-line26 is the process about 1-bit data transmission(cycles, electrical level change  
etc.). The link includes the description of the process.
https://github.com/QSHANSSS/ese5190-2022-lab2-into-the-void-star/blob/main/3.5.xlsx  

3.6/3.7 packet tranmission/timing diagram  
Generally, the protocol of ws2812 is to send RGB information to the module and light corresponding photodioes(GPIO pin).To represent the color,  
it would implement 24-bit packet for tansmission(8 bits for each natural color). From 3.5, we noticed that one-bit-data transmission would take  
10 cylces, which means that the receiver need to take 240 cycles for getting color data(from FIFO).  

https://github.com/QSHANSSS/ese5190-2022-lab2-into-the-void-star/blob/main/timing%20program_3.6_3.7.jpg  
  
4. blinking and hello world  
Firstly, we need to initialize the ws2812, including GPIO setting and pio configuration.  
Then we shall create the send_pixels for RGB packet transmission.
<img width="411" alt="image" src="https://user-images.githubusercontent.com/64452307/196342692-35b0b1e4-d934-45af-8fa4-cb5fb682df78.png"> 
<img width="626" alt="image" src="https://user-images.githubusercontent.com/64452307/196356757-dfc0d41e-f6d1-4912-ad4b-9de08ef9173b.png">

Display result is below:
![result 00_00_00-00_00_30~1](https://user-images.githubusercontent.com/64452307/196343671-979a2d2a-f1be-4dd2-83f7-7cb3df65b4f4.gif)


