Zhuoling Li
MacBook Pro (13-inch, 2018, Four Thunderbolt 3 Ports) 2.3 GHz Quad-Core Intel Core i5
MacOS Monterey Version 12.6

# 1. Tools to install first:
#### install homebrew
$  /bin/bash -c "$(curl -fsSL
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
（ referrence: https://github.com/homebrew/install#uninstall-homebrew ）
#### install toolchain
```
$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```
And you will see

<img width="431" alt="Screen Shot 2022-10-13 at 19 03 14" src="https://user-images.githubusercontent.com/114199800/195726267-fcad1916-b1f0-488f-9385-ab363e3ced7d.png">

<img width="457" alt="Screen Shot 2022-10-13 at 19 03 25" src="https://user-images.githubusercontent.com/114199800/195726326-c1b050a8-8457-4160-b2bd-6c145e87108a.png">

## 2. Set up the Pico
if your devicesd already setted up, move to the step 3
According to the lab mannual, navigate to the pico examples repos: https://github.com/raspberrypi/pico-examples
They provide a series of exampls that can be easily used
#### Create the pico directory
```
$ cd ~/
$ mkdir pico
$ cd pico
```
#### Copy the pico examples and SDK to the directory
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```
and when the process done you will see 
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /Users/lizhuoling/pico/pico-sdk
Defaulting PICO_PLATFORM to rp2040 since not specified.

...
...
lwIP available at /Users/lizhuoling/pico/pico-sdk/lib/lwip
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/lizhuoling/pico/pico-examples/build
```
Pay attention to the output message about tinyusb module. If error message popped out about tinyusb, you need to troubleshoot it, otherwise the usb connection would be affected.
#### then update the SDK
```
$ cd pico-sdk
$ git pull
$ git submodule update
```
## 3. loadin the code to the RP2040 and run
First, create a "build" directory to contain the pico examples to build the code
```
$ cd pico-examples
$ mkdir build
$ cd build
```
conitune to the build repo
```
$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..
```
and you will see and then the build directory are already set up
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /home/pi/pico/pico-sdk
...
...
-- Build files have been written to: /home/pi/pico/pico-examples/build
```
and then open the terminal,find the 'build' directory
```
$ cd build
```
find the program hello_world to load under the build repo,
```
$ cd hello_wolrd
$ make -j4
```
The make -j4 will build the files and make to seperate examples programs in the hello_world/serial and hello_world hello_world/usb/ directories
you will see the result

<img width="523" alt="Screen Shot 2022-10-13 at 19 03 38" src="https://user-images.githubusercontent.com/114199800/195731134-56539814-32ca-4433-a69b-217fd9eb3630.png">

###Important infroamtion when run the RP2040
First you need to let the RP2040 into storyge mode. After you plug in your RP2040 to your device, You can press Boot button and hold until press the reset button once, you will see the the Rp2040 recognized as RP1 /RP2 on your computer.
And the you can drag the hello_usb.uf2 to the RP1/Rp2, then you can see the RP1/Rp2 quit automatically.

Now you use the terminal to run the code.
first use code below to find your device
```
$ ls /dev/tty.*
```
you can find your device name
like /dev/tty.usbmodem141441
and then use the code below to see the output
```
$ screen /dev/tty.board_name 115200
```
to run the code, the speed required by the board is 115200 bits per second.
you can see the output below

<img width="583" alt="Screen Shot 2022-10-13 at 01 03 36" src="https://user-images.githubusercontent.com/114199800/195733012-81619749-7bd7-41d1-b184-2efb95155653.png">

