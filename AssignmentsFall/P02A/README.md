P02A - Installing ncurses on Windows 11 with WSL

Jhymani Joseph

Description:
This project provides a step-by-step guide for installing ncurses on Windows 11 using Windows Subsystem for Linux (WSL). It includes instructions for setting up WSL, updating Ubuntu, installing ncurses, and running a simple "Hello, World!" program to test the installation. The goal is to ensure that ncurses is properly installed and working.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Screenshot #1.png] |Screenshot of the hello_ncurses program in nano succesfully printing out "Hello World!" |
|   2   | [Screenshot #2.png] |A Screenshot of the C++ program 'hello_ncurses.cpp' that tests the installation of ncurses. |
|   3   | [Screenshot #3.png] |Screenshot of the hello_ncurses program running in WSL. |
|   4   | [README.md] |This README file with setup instructions and details.|



Instructions

I Installed WSL on Windows 11.

After installation, I launched Ubuntu from the Start Menu or by typing wsl in PowerShell/Command Prompt.

I updated the Ubuntu packages.
Then I installed ncurses.

Then I installed the development libraries required for ncurses.

Then I copied the Simple ncurses "Hello World" Program.

Then I created a C++ file using a text editor nano:.

Then I copied  the following code in hello_ncurses.cpp.

#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    printw("Hello, World!"); // Print message on the screen
    refresh();            // Refresh to show the message
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}
Then I ompiled and Ran the Program.

Then I compiled the program with g++.

Then I ran the compiled program.

Then I saw "Hello, World!" displayed in the terminal.

Common Errors:

Missing ncurses libraries: Make sure to install both libncurses5-dev and libncursesw5-dev.

Compilation errors: Ensure that the -lncurses flag is used when compiling to link the ncurses library.

WSL not installed properly: If wsl --install doesn't work, check for Windows updates or use the official WSL documentation for troubleshooting

