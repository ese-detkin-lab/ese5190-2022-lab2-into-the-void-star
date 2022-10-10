University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yuxuan Li
        liyux@seas.upenn.edu
        [Yuxuan's LinkedIn](https://www.linkedin.com/in/yuxuan-li-26511b203/)
    Tested on:  OMEN Laptop 15-ek0xxx, Windows-10 Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz   2.59 GHz

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)
## Setting Up Terminal

While I was using Windows Operating system, I prefer to use WindowsPowershell simply because of the ease of access.  
Moreover, we need to follow the steps below to install the C/C++ SDK, using the repository for pico-examples and then run the "hello_usb.c" program.

We can follow the following steps to configure our PC:  
    1.  [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) you need the filename ending with -arm-none-eabi.exe.
        ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/ARM_GNU_SetUp.PNG)  
        
    This will help us complete the setup process of the ARM GNU Toolchain.
    
   2. [Cmake](https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2-windows-x86_64.msi)  
    
   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_CMake.PNG) 


   3. Installing Build Tools for Visual Studio 2022  
   
       [Build Tools for Visual Studio 2022](https://aka.ms/vs/17/release/vs_BuildTools.exe)
        
        ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_VSCode.PNG) 
        
   4.  Installing Python 3.10
   
        [Latest Python 3 Release - Python 3.10.7](https://www.python.org/downloads/release/python-3107/) 
        
   5. Installing Git
        
        Download git as: [64-bit Git for Windows Setup](https://github.com/git-for-windows/git/releases/download/v2.38.0.windows.1/Git-2.38.0-64-bit.exe) 
        
        Ensure you tick the checkbox to allow Git to be used from 3rd-party software and, when installing Git check the box "Checkout as is, commit as-is".  
        
        Select Windows' default console window", and " Enable experiemental support for pseusdo consoles" during the installation process. 
        
   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Install_Git.PNG)
   
   ![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Git_Setup.PNG)
   
   6. Building "Hello World" From the Command Line
   
   Go ahead and open a Developer Command Prompt window from the Windows menu, by selecting ‘**Windows > Visual Studio 2022 > Developer Command Prompt    for VS 2022**’ from the menu.  
   Then set the path to the SDK as follows:
```
   C:\Users\pico\Downloads> setx PICO_SDK_PATH "..\..\pico-sdk"
```
At this stage, the command window will prompt a hint information which indicating that the setup for the environment variable is completed.
You now need to *Close your current Command Prompt Window* and open a second Developer command window and then Navigating to the  <span style="color:red">some **pico-examples file.** text</span>. The code for getting th
```
C:\Users\pico\Downloads> cd pico-examples
C:\Users\pico\Downloads\pico-examples> mkdir build
C:\Users\pico\Downloads\pico-examples> cd build
C:\Users\pico\Downloads\pico-examples\build> cmake -G "NMake Makefiles" ..
C:\Users\pico\Downloads\pico-examples\build> nmake

```
Wait until the building process is completed(This may take some time...)

![alt text](https://github.com/Yuxuan-Li295/ese5190-2022-lab2-into-the-void-star/blob/main/Media/Pico_Build.PNG)
   
   
        
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
