University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2A

    Yuxuan Li
        liyux@seas.upenn.edu
        [Yuxuan's LinkedIn](https://www.linkedin.com/in/yuxuan-li-26511b203/)
    Tested on:  OMEN Laptop 15-ek0xxx, Windows-10 Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz   2.59 GHz
    Partner: Yuxin Wang, Xingqi Pan

(TODO: Your README)

Include lab questions, screenshots, analysis, etc. (Remember, this is public, so don't put anything here you don't want to share with the world.)
## Setting Up Terminal

While I was using Windows Operating system, I prefer to use WindowsPowershell simply because of the ease of access. 

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
