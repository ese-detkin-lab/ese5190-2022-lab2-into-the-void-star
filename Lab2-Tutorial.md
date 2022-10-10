Name: Meiyi Yu
PennID: 81304595

This is a detail guide to set up the programming environment for RP2040

## 1. Tools to install first:
#### install Homebrew
```
$  /bin/bash -c "$(curl -fsSL
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
（ referrence: https://github.com/homebrew/install#uninstall-homebrew ）

#### install toolchain
```
$ brew install cmake
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```

## 2. Set up Pico
If the computer already have pico setted up, jump directly to step 3.

The pico-examples repository (https://github.com/raspberrypi/pico-examples) provides a set of example applications
that are written using the pico-sdk (https://github.com/raspberrypi/pico-sdk). 

#### Create a pico directory:
```
$ cd ~/
$ mkdir pico
$ cd pico
```
#### Clone pico examples and SDK to the directory:
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```
Pay attention to the output message about tinyusb module. If error message popped out about tinyusb, you need to troubleshoot it, otherwise the usb connection would be affected.

#### Updating the SDK:
```
$ cd pico-sdk
$ git pull
$ git submodule update
```

## 3. Load and run code on RP2040
#### Build the code
We need a 'build' directory to build the code, inside of the pico-examples
```
$ cd pico-examples
$ mkdir build
$ cd build
```
prepare the build repo:
```
$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..
```
You will see:
```
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /home/pi/pico/pico-sdk
...
...
-- Build files have been written to: /home/pi/pico/pico-examples/build
```
Now you have the build directory all set.

if you already has the directory, just cd into it.
```
$ cd build
```
Find the program you want to load in the build 








![image](https://user-images.githubusercontent.com/84453030/194796162-8852026f-2ab3-4162-b41d-a462956adac9.png)

