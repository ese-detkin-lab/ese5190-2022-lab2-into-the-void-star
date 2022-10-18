University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

   Name: Yeqi Chen 
   LinkedIn: https://www.linkedin.com/in/villy-chen97/
   Tested on: Lenovo Legion Y9000, CPU: Ryzen 5700 16 core

Directory
This is the setup log/guide of Villy Chen on ESE 519 Lab2. In this directory I will go through all the detailed steps of setting up the RP2040 broad on the windows laptop using WSL. 
1. Software Installation
2. Downloading the setup script 
3. install the toolchain  
4. update the SDK
5. build up the code for pico
6. build and run hello_world



1. Software Installation 
Putty
https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html 
Downloaded on this website and installed the Putty. I downloaded the 64 bit X86 version. 
Then, open the device manager and find out the corresponding COM port for the device. I failed the first time because I found the baud rate of the device and the port is not the same. Then, we need to adjust the baud rate to the same value and we can successfully open it. 

WSL ubuntu
open powershell on windows as adnimistrrater 
type wsl --install to install the wsl ubuntu.

After the setup of putty and wsl, we can go to the next part. 

2. Downloading the setup script 
Now open up the ubuntu on windows. By following the methods given in the setup for pico, we can download and excetute the steps needed for the lab2. 
   wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh
  After successful execution we can see the following: 
    ‘pico_setup.sh’ saved [3722/3722]
   
   then we run 
    chmod +x pico_setup.sh
    ./pico_setup.sh
   To install pico repositories and required dependencies. 
   we install the vscode by using   snap install code --classic 
   
   Then we download and check the repository by 
   cd~/
   cd pico/pico-sdk 
   git submodule update --init 
   cd ..
   
3. install the toolchain 
    use code below: 
    sudo apt update 
    sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
    sudo apt install libstdc++-arm-none-eabi-newlib

4. update the SDK
    cd pico-sdk 12. git pull 
    git submodule update
   
5. build up the code for pico
    cd .. 
    cd pico-examples 
    mkdir build -p
    cd build
    at this point we will create a build folder to contain all the buildup file of the pico-example. 
    export PICO_SDK_PATH=../../pico-sdk (this is going to create pico-sdk folder in the two upper directory of build. We can also use absolute directory such as home/username/pico/pico-sdk, either one would work)
    then we can run cmake .. to make up files there. 
    Upon successful execution, the cmake command would end with the following message: "-- Build files have been written to:"path to your build folder"
    
    <img width="636" alt="1 setup" src="https://user-images.githubusercontent.com/44985032/195965501-5e4822dd-f856-4a3c-98b4-556e25c0bb5c.png">

6. build and run hello_world
    firstly we open the folder of hello_world
    cd hello_world
    make -j4 
    my laptop has 16 core so I can run make -j16 to run it faster, but as such a small project, the speed does not matter too much. 
    After the build we can various files have been created in the build/hello_world/usb folder, and then we can try to run it on the broad. 
    <img width="651" alt="3 directory" src="https://user-images.githubusercontent.com/44985032/195965512-37170e80-f8db-41bc-b043-b67a04099be1.png">

    First we need to reset our broad by tapping the central button and insert it into usb port at the same time. This time it will be recognized by the laptop as a usb mass storage device. 
    I open up the folder of hello_world/usb, and we drop the hello-usb.uf2 file into that disk, we can see that the broad will automatically disappear. However, it will still be visible on the device manager. Now we can check the COM port it is using, and we can open up the Putty, type the corresponding port and baud rate into it, then we can open the serial communication window to see "hello, world" coming. 
    
    
    <img width="1240" alt="4  serial input" src="https://user-images.githubusercontent.com/44985032/195965519-4a15fb69-ecbf-40d0-a5da-e3b8b8625778.png">

    
