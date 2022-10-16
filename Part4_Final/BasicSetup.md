# ese519_lab2_setup
University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yuxuan Li
        liyux@seas.upenn.edu
        [Yuxuan's LinkedIn](https://www.linkedin.com/in/yuxuan-li-26511b203/)
    Tested on:  OMEN Laptop 15-ek0xxx, Windows-10 Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz   2.59 GHz
## Setting Up for SDK on your Windows Machine for Raspberry Pi Pico.

While I was using Windows Operating system, I prefer to use WindowsPowershell simply because of the ease of access.  
Moreover, we need to follow the steps below to install the C/C++ SDK, using the repository for pico-examples and then run the "hello_usb.c" program.

We can follow the following steps to configure our PC:  
    1.  [**Arm GNU Toolchain**](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) you need the filename ending with -arm-none-eabi.exe.**
        ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/ARM_GNU_SetUp.PNG)  
        
    This will help us complete the setup process of the ARM GNU Toolchain.
    
   2. [**Cmake**](https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2-windows-x86_64.msi) 
    
   ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Install_Cmake.PNG) 

   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_CMake.PNG) 


   3. **Installing Build Tools for Visual Studio 2022**
   
       [Build Tools for Visual Studio 2022](https://aka.ms/vs/17/release/vs_BuildTools.exe)
        
        ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_VSCode.PNG) 
        
   4.  **Installing Python 3.10**
   
        [Latest Python 3 Release - Python 3.10.7](https://www.python.org/downloads/release/python-3107/) 
        ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Install_Python.PNG) 
        
        
   5. **Installing Git**
        
        Download git as: [64-bit Git for Windows Setup](https://github.com/git-for-windows/git/releases/download/v2.38.0.windows.1/Git-2.38.0-64-bit.exe) 
        ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Install_Git.PNG)
        
        
        Ensure you tick the checkbox to allow Git to be used from 3rd-party software and, when installing Git check the box "Checkout as is, commit as-is".  
        
        Select Windows' default console window", and " Enable experiemental support for pseusdo consoles" during the installation process. 
        
   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_Git.PNG)
   
   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Git_Setup.PNG)  
   
   #**Installing the C SDK**

   The next step involves installing the C SDK onto the Adafruit QT Py board. The following PDF is a extremely helpful guide for this part:https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf. For my instruction, I have omitted the unnecessary instruction for the Pico breakout board and mainly focus on the RP2040 board for the lab purpose. 
For this first part, you can start with the board unplugged. In your terminal input the following commands to create a new folder on your computer in a specific location by your preference. 

```
cd ~/
mkdir pico
cd pico
```
From here we will need to clone the pico-sdk and pico-examples git repositories.
```
git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
cd ..
git clone -b master https://github.com/raspberrypi/pico-examples.git
```

   6. **Building "Hello World" From the Command Line**
   
   
   Go ahead and open a Developer Command Prompt window from the Windows menu, by selecting ‘**Windows > Visual Studio 2022 > Developer Command Prompt    for VS 2022**’ from the menu.  
   Then set the path to the SDK as follows:
```
   C:\Users\pico\Downloads> setx PICO_SDK_PATH "..\..\pico-sdk"
```
At this stage, the command window will prompt a hint information which indicating that the setup for the environment variable is completed.
You now need to *Close your current Command Prompt Window* and open a second Developer command window and then Navigating to the  <span style="color:red">some **pico-examples file.** text</span>. The code for getting the build files for the "hello_usb.c" is listed as follows:
```
C:\Users\pico\Downloads> cd pico-examples
C:\Users\pico\Downloads\pico-examples> mkdir build
C:\Users\pico\Downloads\pico-examples> cd build
C:\Users\pico\Downloads\pico-examples\build> cmake -G "NMake Makefiles" ..
C:\Users\pico\Downloads\pico-examples\build> nmake

```
Wait until the building process is completed(This may take some time...)

![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Pico_Build.PNG)
   
 This building process will produce the **elf,bin** and **uf2** targets.  
 In order to find the corresponding file, we can access: <p><red> hello_world/serial and also hello_world/usb</red> directories in the directory named **Build**. 
 ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Access_Build_Uf2_Files.PNG)  
  
    
**7. SERIAL CONSOLE – PUTTY.** <br />  
    While not the most *powerful* serial port software, putty does a good job and is a handy tool(telnet and ssh) and in my setup process, I choose it as my serial console.  Morover, I found the following link is extremly helpful as a guide to connect to RP2040's REPL via Windows(https://learn.adafruit.com/welcome-to-circuitpython/advanced-serial-console-on-windows).  
    
    PUTTY can be assessed and download through [putty](https://www.putty.org/) and open up the installer once the download process is over. 
    ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/PUTTY_INSTALLER.PNG)
    
The default installation settings are pretty good for the purpose of this lab already:  
    
    
   ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/PUTTY_INSTALL_DEFAULT.PNG)
    
    The Windows Device Manager is the tool chosen to determine which port the board is using. As shown in the below picture, click on Ports(COM & LPT) option, we can see the (C0M#) number corresponding to your device(Remeber to put your device connect to your laptop via MicroUSB cable).  
    
   ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Device_Connection.jpg)
   ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Device_Manager.PNG)  
    The next step is to open the software PuTTy and configure it as the following:  
    (-In the box under the serial line, and enter the serial port that you found your board is using)
    ![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/PUTTY_SETTING.PNG)  
**8. Flashing the board and running the "hello-usb.c".** <br />  
    
For this step, we just connect our RP2040 Raspberry Pi Pico to the computer via the Micro-USB and hold down the **BOOTSEL** button so that the USB will be forced into the USB Mass Storage Mode.   
After that, the board will appear as an external driver and we can just drag and drop the binary file named as the ‘hello_usb.uf2’. Then the USB will disappear as the external drive and start running the import flashed code and we can see the following things happen in puTTY:
![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/Hello_World_Final_Setup.PNG)  
    As seen from the above graph, the button on the opposite end of the board from the USB connector is the RST button. To enter the bootloader and create the drive that name start with the RPI.  
    There are two methods listed as follows:  
###### Method 1: 
To create that file we need to keep holding the 'BOOT'button in the plugging process of our USB and at the same time click the 'RESET' button for once.
###### Method 2: 
When plugging in, press and hold the BOOTSEL button (highlighted in red above),keep holding it while plugging it into USB, and wait for the drive to appear before releasing the button.  
    Then, we can see the RPI drive shows:

![alt text](https://github.com/Yuxuan-Li295/ese519_lab2_setup/blob/main/Media/RPI.PNG)

 Notes:
- Keep in the mind to hold down the ''BOOT'' button while uploading code to the Python version.  
    
- Pay attention to the instruction version, if you computer has Windows System, do not work on version for 'macOS' or 'Linux'!

***This marks the end of our basic setup, going forward we will be using this for programming the RP2040.***
## Setting Up a Text Editor

After the terminal setup, the two first command I am used are “ls” and "cd". "ls" enable you to look over the folders that you navigate to and "cd****<File_Path>" enable you to navigate to the destination that you want to go.  

The first step for this prelab is to navigate yourelf to a location of your choosing(In this prelab, I choose the folder as: D:\ESE519 (cd D:\ESE519). I then use the command " mkdir PreLab2" to creater a folder that can be used to hold all the content file needed for this lab2. After that, I use the "cd" command again to navigate to my newly created folder(cd D:\ESE519\PreLab2). I then made a ".txt" file with the command: "New-Item -Path "D:\ESE519\PreLab2" -Name "testfile1.txt" -ItemType File" Command to creat it. Then with the same method, I create another file in that folder that named "testfile.txt".   

After the file folder and the corresponding file created. I use the "ls" command to check whehter the file being created successfully or not. If I want, I can just go ahead to either one of the ".txt" file and open up on the windows text editor(Notebook). As a further check I entered some contents in the "testfile.txt" and save it and then exit out of my text editor.  

In order to input content directly from the command line: Input whatever the words you want and then save the wrok with the follwing command:
 "XXXXXX" | Out-File <Data-Path that you want to save with>"
 
To view the content of the text in the ".txt" file, the following command should be entered:"cat testfile.txt” to view the contents of my file directly in the WindowsPowerShell without having to open the file. A flow of all the commands Used are shown below:

```
mkdir PreLab2
cd D:\ESE519\PreLab2
New-Item -Path "D:\ESE519\PreLab2" -Name "testfile1.txt
cat testfile.txt
```  
## Summary  
    
For the serial monitor part, I personallly recommend using the Putty tool which has strightforward setting proces and pay attention to the port #number when configure the serial console and if the text editor and the command line is a lit bit hard for you. For this lab purpose, it is also acceptable for us using the high level folder directly as a visulaziation.
    

