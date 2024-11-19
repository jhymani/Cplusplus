
# P02 - Knucklebones Game  
### Jhymani Joseph

### Description:

This C++ program implements the **Knucklebones** dice game from *Cult of the Lamb* using the Ncurses library for interactive console gameplay. The game is played between two players on a 3x3 grid, where each player rolls a 6-sided die and places it in one of the columns. The goal is to score more points by strategically placing dice, with bonuses for matching dice values in the same column. The game features a dynamic interface with color, player turns, dice rolling, grid updates, and real-time score calculations. The player with the highest score at the end of the game wins.

### Files

| #   | File              | Description                                                                 |
| --- | ----------------- | --------------------------------------------------------------------------- |
| 1   | `button_class.hpp` | Use to add a button to your game.                                           |
| 2   | `color_class.hpp`  | Use to easily make color pairs and use colors.                              |
| 3   | `dice_class.hpp`   | Animate a cheesy dice square (rectangle).                                   |
| 4   | `game.cpp`         | Example usage of helper classes to run the Knucklebones game.               |
| 5   | `grid_class.hpp`   | Where you place dice values in a 3x3 grid.                                  |
| 6   | `input_class.hpp`  | Captures input from users like a text box.                                  |
| 7   | `log.txt`          | Log file to help debug programs.                                            |
| 8   | `logger_class.hpp` | Class to assist in logging debug statements.                                |
| 9   | `PROGRAM_Assignmentknucklebones.cpp` | Main game logic that integrates all classes and runs the game. |

### Instructions

1. **Install Dependencies**  
   Ensure you have the `Ncurses` library installed on your machine.  
   - On Linux, use: `sudo apt-get install libncurses5-dev libncursesw5-dev`
   - On macOS, use: `brew install ncurses`

2. **Compile and Run the Program**  
   To compile the program, navigate to the folder where your files are located and run the following command:
   ```bash
   g++ -o Knucklebones PROGRAM_Assignmentknucklebones.cpp -lncurses
   ```

3. **Execute the Program**  
   Once compiled, you can run the game by executing the following command:
   ```bash
   ./Knucklebones
   ```

   This will start the game in an interactive console window, where you can play the game by following the on-screen instructions.

### Common Errors

1. **Ncurses Library Missing**  
   If you receive an error about Ncurses not being found, ensure you have it installed as mentioned in the instructions above.

2. **File Not Found (log.txt)**  
   If the log file `log.txt` is missing, it will be automatically generated the first time the program is run. Ensure that the program has proper permissions to write to the directory.

3. **Grid Index Out of Range**  
   When placing dice on the grid, ensure you enter a column number between 1 and 3. Entering a number outside this range may cause unexpected behavior.

### Example Command:
- To start the game, run the compiled binary:
   ```bash
   ./Knucklebones
   ```

### Additional Notes
- **Game Flow**: The game alternates between two players, who roll a die and place it in one of the available columns. The game continues until all grid spaces are filled, and the player with the higher score wins.
- **Debugging**: If you encounter issues or need to check the internal workings, refer to the `log.txt` file for debug information.
