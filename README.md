University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

Praveen Raj Uma Maheswari Shyam Sundar
    LinkedIn: www.linkedin.com/in/praveen-raj-u-s-317981135
Tested on: Asus ROG Flow X13, Windows 11



# lab2-setup

OS: Ubuntu 22.02.1 LTS
Processor: AMD Ryzen 7

**Setup Guide for the C++ SDK on a Linux based Macine (Ubuntu 22.04.1 in My Case):**
[Note: While the Getting Started with Raspberry Pi Pico Document predominantly uses a Raspberry Pi 4 for the setup, here I have used my linux machine for the same which involves risks including overloading the root folder memory which might affect the OS stability. Therefore, I would suggest to pay attention to the memory comsumption prompts in your terminal and act accordingly.]


The Steps involved in Setting up the SDK are as follows:

i. Downloading the Setup Script,
ii. Installing Toolchain,
iii. Updating the SDK,
iv. Building the Code,
v. Flashing the Code into the Board,
vi. Running it..!


**Step-1: Downloading the Setup Script:**
In the Linux terminal enter the following comand(s);

1. wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh

Upon Successful execution of the (1) We would see the following:

‘pico_setup.sh’ saved [3722/3722]

2. chmod +x pico_setup.sh
3. ./pico_setup.sh

(3) will install the Pico Repositories and required dependencies. The command will start executing with the following warning message: "Not running on a Raspberry Pi. Use at your own risk!" [Ensure that your root folder has more than 3GB of Free Space]

The execution might end with the following error message: "No apt package "code", but there is a snap with that name." Now executive the following command:

3.a.) snap install code --classic

(3.a) would install vscode.

4. cd~/
5. cd pico/pico-sdk
6. git submodule update --init
7. cd ..

At this point we would have successfully downloaded/cloned all the necessary pico repositories


**Step-2: Installing Toolchain**
Now we would install the addition tools necessary to build applications in the pico-examples library.

8. sudo apt update
9. sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
10. sudo apt install libstdc++-arm-none-eabi-newlib

**Step-3: Updating the SDK***
11. cd pico-sdk
12. git pull
13. git submodule update


**Step-4: Building the Code**
14. cd ..
15. cd pico-examples
16. cd build
17. export PICO_SDK_PATH="Path of your pico sdk" (Example: "/home/praveen/pico/pico-sdk")
18. cmake ..

![Screenshot from 2022-10-10 22-46-34](https://user-images.githubusercontent.com/114270637/194985503-1743f35f-2a91-46b4-a0b5-5f223353e9d7.png)

Upon successful execution, the cmake command would end with the following message: "-- Build files have been written to:"path to your build folder"

19. cd hello_world/
20. make -j4

![image](https://user-images.githubusercontent.com/114270637/194985869-65b9c789-2312-409f-a5a1-5f28558b0660.png)

We could see that various files including hello_usb.uf2, hello_serial.usf etc has been listed in our build/hello-world directory.


**Step-5: Flashing the Code into the board:
* Plug-in the Qt-py or (any supported board e.g: Pico) while pressing down the "Boot" button on the board,
* The board would now show up as a USB Mass Storage device in your linux system, 
* Drag and drop the "hello-usb.uf2" file from the build directory to the board (shown as USB device),
* The board would get automatically unmounted and the corresponding code would start running and pushing "Hello world" to the serial monitor of our linux macine.

**Step-6: Running it..!**
In order to open serial monitor in linux:

21. sudo apt install minicom
22. sudo minicom -b 115200 -o -D /dev/ttyACM0

This will open the serial monitor where "Hello World" would already have started getting printed.

![Screenshot from 2022-10-10 21-57-25](https://user-images.githubusercontent.com/114270637/194987398-98b0798d-64cd-4479-8208-0b214d1fbd6f.png)



(We did it..!)

