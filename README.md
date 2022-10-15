University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Aurunima Samaddar
        www.linkedin.com/in/aurunima-samaddar-600157232
    Tested on: Thinkpad X1 Carbon 2nd Gen, Windows 10 Education

## Computer Specs

|   System      |Spec                                                      |
|--------------:|----------------------------------------------------------|
|   Windows     | 10 Education                                             |
|   Computer    | Thinkpad X1 Carbon 2nd Gen                               |
|   Processor   | 2.1 GHz Dual Core Intel(R) Core i7                       |
|   Memory      | 8 GB DDR3                                                |
|   StatUp Disk | Samsung MZNTD256HAGL-000L9                               |
|   Graphics    | Intel(R) HD Graphics Family                              |
|   Board       | Adafruit QT Py                                           |

## Windows Subsystem for Linux
- If you alreday have it installed (like I did), skip to the 'Check the version' step
- Install WSL through Windows powershell\
  + `$ wsl --install`
  + In Windows Powershell (as admin)\
    `$ dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart`
  + Restart your machine to complete the WSL install and update to WSL 2
  + Download and run kernel package from https://learn.microsoft.com/en-us/windows/wsl/install-manual#step-3---enable-virtual-machine-feature
  + Set WSL2 as the default version\
    `$ wsl --set-default-version 2`
  + Install Linux distribution form here https://apps.microsoft.com/store/detail/ubuntu-2004/9N6SVWS3RX71?hl=en-us&gl=us \
    OR\
    Use this command in Powershell\
    `$ Invoke-WebRequest -Uri https://aka.ms/wslubuntu2004 -OutFile Ubuntu.appx -UseBasicParsing`
- **Check the version**\
  `$ wsl -l -v`
- Set WSL2 as the default version\
  `$ wsl --set-default-version 2`
- Upgrade the WSL version for Ubuntu\
  `$ wsl --set-version Ubuntu 2`
  ![image](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/img/Lab2_Ubuntu_WSL2.png)
- If you want to set Ubuntu as default, use\
  `$ wsl -s Ubuntu`
- To use the WSL Ubuntu simply use\
  `$ ubuntu` \
  OR\
  you may even start the program from Windows Start menu\
*Refer this link for any other information: https://learn.microsoft.com/en-us/windows/wsl/install*

## Using Ubuntu
- Open Ubuntu
- Create a folder\
  `$ mkdir Aurchie`
- Navigate to the newly created folder\
  `$ cd Aurchie`
- Create a new text file\
  `$ nano test.txt`
- Write something in the file, save it (Ctrl-O) and close it (Ctrl-X)
- Print out the text in the file\
  `$ cat test.txt`
- This will display the text in the command window
![image](https://github.com/Aurunima/ESE5190_Fall22_Lab2/blob/main/img/Lab2_Ubuntu_p2dot2.png)

### Install GVim on Ubuntu
- `$ gvim` (if you don't have it, this will list variants of vim)
- `$ sudo apt-get update` (especially important if you had installed Ubuntu long before attempting to install gvim)
- `$ sudo apt install vim-gtk3` (install gvim)
- `$ gvim` (open the gvim editor)\
*The networking subsystem in WSL2 is different than the used in WSL1.*
  - *In WSL1, Linux uses the same IP addresses than the Windows host, then, you can access the applications using localhost or 127.0.0.1*
  - *In WSL2, Linux runs on a lightweight virtual machine and has a different IP address. To access networking apps running on the Windows Host you must use the Windows IP address. to check IP address of Windows host:* `$ cat /etc/resolv.conf` \
    *Which results in*> nameserver 172.24.144.1 \
    *To set the DISPLAY variable in your ~/.profile file*
    ```
    if grep -q WSL2 /proc/version; then
      #execute route.exe in the windows to determine its IP address
      DISPLAY=$(route.exe print | grep 0.0.0.0 | head -1 | awk '{print $4}'):0.0
    else
      #In WSL1 the DISPLAY can be the localhost address
      if grep -q icrosoft /proc/version; then
        DISPLAY=127.0.0.1:0.0
      fi
    fi
    ```

## Install Putty
- Download from here: https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html
- And follow installation steps.
