University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Zihan Zhang
         zihanzh@seas.upenn.edu
    Tested on: Ubantu

#Part 3.2
  
  Why is bit-banging impractical on your laptop, despite it having a much faster processor than the RP2040?
  If the processor is interrupted to attend to one of the hard peripherals it is also responsible for, it can be fatal to the timing of any bit-banged protocol. And 
  the  ratio between the processor speed and protocol speed is big, so the processor will spend uselessly idling in between GPIO accesses.

  What are some cases where directly using the GPIO might be a better choice than using the PIO hardware?
  The main case where software GPIO access is the best choice is LEDs and push buttons.

  How do you get data into a PIO state machine?
  Use pio_sm_put_blocking() function to push data directly into the state machine’s TXFIFO.

  How do you get data out of a PIO state machine?
  Use pull instruction first to take one data item from the transmit FIFO buffer, and places it in the output shift register (OSR). Then use out instruction to 
  write  that data to some pins.
  
  How do you program a PIO state machine?
  System software loads data into the PIO's instruction memory and then set the i/o mapping.

   In the example, which low-level C SDK function is directly responsible for telling the PIO to set the LED to a new color? How is this function accessed from the 
   main “application” code?
   pio_sm_put_blocking pio_sm_put_blocking() is called with the parameters from the put_pixel().

   What role does the pioasm “assembler” play in the example, and how does this interact with CMake?
   Our program written in C language can be built to assembler with GCC. We can use CMake to generate uf2 file which can be recognized by the board.
 
#Part3.3
   
   I put this document in part3.3.pdf<br>
  
  <img width="276" alt="image" src="https://user-images.githubusercontent.com/114272466/196423941-5cfdee5b-59bc-41ff-942f-385e05bdb895.png"><br>
  <img width="281" alt="image" src="https://user-images.githubusercontent.com/114272466/196424148-a8a5bff1-017b-418a-a24c-1534fd1f5702.png"><br>
  <img width="299" alt="image" src="https://user-images.githubusercontent.com/114272466/196424198-ab6013cc-1a1d-489e-9a9f-64bf1c2d47d0.png"><br>
  <img width="294" alt="image" src="https://user-images.githubusercontent.com/114272466/196424228-672ff8cc-1870-410a-9f0b-ef1c4d61ab29.png"><br>
  <img width="327" alt="image" src="https://user-images.githubusercontent.com/114272466/196424293-e2f0f00f-4699-4787-bbb5-e42a1d6eb6c0.png"><br>
  <img width="311" alt="image" src="https://user-images.githubusercontent.com/114272466/196424352-745eedaa-6374-472d-aa87-c06fbf5938b4.png"><br>
  <img width="307" alt="image" src="https://user-images.githubusercontent.com/114272466/196424391-5b1df5cb-9d57-49cc-b82a-664ba036a73a.png"><br>
  
#Part3.4

  I put this document in part3.4.xlsx<br>
  
#Part3.5

  I put this document in part3.5.pdf<br>
  
  ![image](https://user-images.githubusercontent.com/114272466/196425034-956fe653-a823-48e1-892a-41bf81dc413c.png)#Part3.5<br>
  
#Part3.6

  I put this document in part3.6.xlsx<br>  
  
#Part3.7

  I put this document in part3.7.pdf<br> 
  ![image](https://user-images.githubusercontent.com/114272466/196425697-8027d36a-c7af-4fa4-a831-07cd2b553ab0.png)<br>
    
#Part4 Hello_world<br>
  ![image](https://user-images.githubusercontent.com/114272466/196427660-26ddf1e4-1cd5-432a-9c07-fa4104f092fe.png)<br>

    For this project, I add the gpio in hello_usb.c and add ws2812.h. At the mean time, I add the fuction in ws2812.c. 
    Additionally, I mix two CMakelists.txt into one doucment. Finally, I made it.
    
    


    
    









   
   
   
   
   
   
   
   
   
   





