P02A - Installing ncurses on Windows 11 with WSL
Jhymani Joseph
Description:
This project provides a step-by-step guide for installing ncurses on Windows 11 using Windows Subsystem for Linux (WSL). It includes instructions for setting up WSL, updating Ubuntu, installing ncurses, and running a simple "Hello, World!" program to test the installation. The goal is to ensure that ncurses is properly installed and working.

Files
#	File	Description
1	hello_ncurses.cpp	A C++ program that tests the installation of ncurses.
2 Screenshot 2024-10-10 133153	Screenshot of the hello_ncurses program running in WSL.
3	README.md	This README file with setup instructions and details.

Instructions
I Installed WSL on Windows 11:

Open PowerShell as Administrator and run:
bash

After installation, I launched Ubuntu from the Start Menu or by typing wsl in PowerShell/Command Prompt.

I updated the Ubuntu packages:
bash

sudo apt update
sudo apt upgrade

Then I installed ncurses:

Then I installed the development libraries required for ncurses:

bash

sudo apt install libncurses5-dev libncursesw5-dev
Create a Simple ncurses "Hello World" Program:

Then I created a C++ file using a text editor nano:

bash

nano hello_ncurses.cpp
Then I wrote the following code in hello_ncurses.cpp:
cpp
Copy code
#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    printw("Hello, World!"); // Print message on the screen
    refresh();            // Refresh to show the message
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}
Then I ompiled and Ran the Program:

Then I compiled the program with g++:
bash

g++ hello_ncurses.cpp -o hello_ncurses -lncurses

Then I ran the compiled program:
bash

./hello_ncurses

Then I saw "Hello, World!" displayed in the terminal.

Common Errors:

Missing ncurses libraries: Make sure to install both libncurses5-dev and libncursesw5-dev.

Compilation errors: Ensure that the -lncurses flag is used when compiling to link the ncurses library.

WSL not installed properly: If wsl --install doesn't work, check for Windows updates or use the official WSL documentation for troubleshooting

Screenshots:
![Screenshot 2024-10-10 133153](https://github.com/user-attachments/assets/63997b26-a45a-4b5f-a9fa-31a9a4b3a5cb)
![Screenshot 2024-10-10 133019](https://github.com/user-attachments/assets/c9591d64-8916-4535-8693-2b4b435ad96a)
![Screenshot 2024-10-10 132933](https://github.com/user-attachments/assets/8c5a5c92-4519-4e54-900a-f07924ed6f4a)
