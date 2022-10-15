## Setup
Setup was done for Windows 11.
* Read SDK documentation. In particular section 9.2 in the Getting started with Raspberry Pi Pico guide, titled Building for Windows.
* Installed the toolchain needed. In specific: Arm GNU Toolchain, CMake, Build Tools for Visual Studio 2022, Python 3.10, Git.

## VS Code Initialization
The git hub repo with the SDK examples was cloned on our local system. VS Code was initialiazed with the required steps:
* Program was opened up with the Developer Prompt
* CMake and CMake tools extensions were downloaded.
* CMake tools was configured. The Configure environment option and the CMake Generator option was modified.
* The folder with pico-examples was chosen as the root folder and the configuration was changed too GCC GNU arm-none-eabi for the compiler.

## Hello World
The initial build was done. The first time I did it I got some errors in my build with the following error message:

[cmake] -- Configuring incomplete, errors occurred!
[cmake] See also "D:/Course Stuff/Fall'22/ESE 519/lab_2/SDK/pico-examples/build/CMakeFiles/CMakeOutput.log".
[proc] The command: "C:\Program Files\CMake\bin\cmake.EXE" --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug "-DCMAKE_C_COMPILER:FILEPATH=C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\12.2 mpacbti-bet1\bin\arm-none-eabi-gcc.exe" "-DCMAKE_CXX_COMPILER:FILEPATH=C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\12.2 mpacbti-bet1\bin\arm-none-eabi-g++.exe" "-Sd:/Course Stuff/Fall'22/ESE 519/lab_2/SDK/pico-examples" "-Bd:/Course Stuff/Fall'22/ESE 519/lab_2/SDK/pico-examples/build" -G "NMake Makefiles" exited with code: 1 and signal: null

Upon closing and restarting VS code the issue seemed to resolve itself. Once the build was completed, the hello_world.uf2 file was copied from the build/hello_world folder.  To clear the RP2040, we held the boot and reset button to remove the circuitpython modification. Upon resetting the device its name changes back to RP2040. Paste the copied file. Open PuTTy or any serial console to see the results.

## Hello World Output
![](https://github.com/harishramesh98/ese5190-2022-lab2-into-the-void-star/blob/4944ab9abe0af41b26e23342a059597b3f81ce2e/helloworld.gif)

