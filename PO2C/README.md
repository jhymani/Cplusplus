# Knucklebones Game - C++ Implementation

Jhymani Joseph

This C++ program implements the Knucklebones dice game from *Cult of the Lamb* using the Ncurses library for interactive console gameplay. The game is played between two players on a 3x3 grid, where each player rolls a 6-sided die and places it in one of the columns. The goal is to score more points by strategically placing dice, with bonuses for matching dice values in the same column. The game features a dynamic interface with color, player turns, dice rolling, grid updates, and real-time score calculations. The player with the highest score at the end of the game wins.

## Files

| File                        | Description                                                      |
| --------------------------- | --------------------------------------------------------------- |
| `button_class.hpp`           | Helper class for creating buttons in the game interface.         |
| `color_class.hpp`            | Helper class to define color pairs and manage color usage.       |
| `dice_class.hpp`             | Class to animate and handle dice functionality (cheesy dice square). |
| `game.cpp`                   | Example usage of helper classes to run the Knucklebones game.    |
| `grid_class.hpp`             | Manages placement of dice values on the 3x3 grid.                |
| `input_class.hpp`            | Captures player input, similar to a text box.                    |
| `log.txt`                    | Log file for debugging program activities.                       |
| `logger_class.hpp`           | Assists with logging debug statements.                           |
| `AssignmentKnuckleBones.cpp` | Main game logic that integrates all classes and runs the game. |

## Instructions

### Install Dependencies

Ensure you have the Ncurses library installed on your machine.

- On Linux, use: `sudo apt-get install libncurses5-dev libncursesw5-dev`
- On macOS, use: `brew install ncurses`

### Compile and Run the Program

To compile the program, navigate to the folder where your files are located and run the following command:

bash
g++ -o Knucklebones PROGRAM_Assignmentknucklebones.cpp -lncurses

Execute the Program
Once compiled, you can run the game by executing the following command:

./Knucklebones
This will start the game in an interactive console window, where you can play the game by following the on-screen instructions.

Common Errors

Ncurses Library Missing

If you receive an error about Ncurses not being found, ensure you have it installed as mentioned in the instructions above.

File Not Found (log.txt)

If the log file log.txt is missing, it will be automatically generated the first time the program is run. Ensure that the program has proper permissions to write to the directory.

Grid Index Out of Range

When placing dice on the grid, ensure you enter a column number between 1 and 3. Entering a number outside this range may cause unexpected behavior.

Example Command

To start the game, run the compiled binary:
./Knucklebones

Additional Notes

Game Flow: The game alternates between two players, who roll a die and place it in one of the available columns. The game continues until all grid spaces are filled, and the player with the higher score wins.

Debugging: If you encounter issues or need to check the internal workings, refer to the log.txt file for debug information.
