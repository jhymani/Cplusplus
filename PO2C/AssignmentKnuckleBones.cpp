// Jhymani Joseph PO2C
// Assignment 06
// Due Date: March 06
// This C++ program implements the **Knucklebones** dice game from 
//*Cult of the Lamb* using the Ncurses library for interactive console gameplay. 
//The game is played between two players on a 3x3 grid, where 
//each player rolls a 6-sided die and places it in one of the columns. 
//The goal is to score more points by strategically placing dice, with
//bonuses for matching dice values in the same column. The game features a dynamic interface with color, 
//player turns, dice rolling, grid updates, and real-time score calculations. 
//The player with the highest score at the end of the game wins.

#include <ncurses.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "game_class.hpp"
#include "player_class.hpp"
#include "dice_class.hpp"
#include "grid_class.hpp"
#include "color_class.hpp"
#include "input_class.hpp"
#include "logger_class.hpp"

using namespace std;

// Game class that controls the flow of the game
class Game {
public:
    Game() {
        srand(time(0));  // Seed the random number generator for dice rolls
        current_player = &players[0];  // Player 1 starts by default
    }

    // Main method to start and manage the game
    void start() {
        // Initialize the game window and other settings using Ncurses
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        start_color();
        keypad(stdscr, TRUE);
        mousemask(ALL_MOUSE_EVENTS, NULL);
        setlocale(LC_ALL, "");

        // Initialize colors for the game interface
        Colorly::init_colors();

        // Initialize players and game grid
        initialize_players("Player 1", "Player 2");
        grid = Grid();

        // Main game loop
        while (true) {
            display_game_state();  // Display current game state (grid and scores)
            take_turn();           // Execute the current player's turn
            if (check_win()) {     // Check if the game has ended
                end_game();         // If game ends, display results
                break;
            }
            switch_turn();         // Switch turn to the other player
        }

        endwin();  // End Ncurses session and close the game window
    }

    // Initialize players with given names
    void initialize_players(string player1_name, string player2_name) {
        players[0] = Player(player1_name);
        players[1] = Player(player2_name);
    }

    // Method for executing a player's turn
    void take_turn() {
        current_player->take_turn(*this);
    }

    // Check if the grid is full (game over condition)
    bool check_win() {
        return grid.is_full();
    }

    // Display the current state of the game (grid and scores)
    void display_game_state() {
        clear();  // Clear the window for refreshing
        grid.display();  // Display the current grid state
        // Display player scores
        mvprintw(0, 0, "%s's score: %d", players[0].get_name().c_str(), players[0].get_score());
        mvprintw(1, 0, "%s's score: %d", players[1].get_name().c_str(), players[1].get_score());
        refresh();  // Refresh the window to update the display
    }

    // End the game and display the result
    void end_game() {
        int score1 = players[0].get_score();
        int score2 = players[1].get_score();

        // Display the winner based on the scores
        if (score1 > score2) {
            mvprintw(3, 0, "%s wins!", players[0].get_name().c_str());
        } else if (score2 > score1) {
            mvprintw(3, 0, "%s wins!", players[1].get_name().c_str());
        } else {
            mvprintw(3, 0, "It's a draw!");
        }
        refresh();
        getch();  // Wait for user input before exiting
    }

    // Switch the current player after each turn
    void switch_turn() {
        current_player = (current_player == &players[0]) ? &players[1] : &players[0];
    }

    // Getter methods for game components (grid, dice, and current player)
    Grid& get_grid() { return grid; }
    Dice& get_dice() { return dice; }
    Player* get_current_player() { return current_player; }

private:
    Dice dice;  // Dice object to generate random rolls
    Grid grid;  // Grid object to hold dice placements
    Player* current_player;  // Pointer to track the current player
    Player players[2];  // Array to store both players
};

// Player class that manages player-specific actions
class Player {
public:
    Player(string name) : name(name), score(0) {}

    // Method for taking a turn
    void take_turn(Game& game) {
        string input;
        mvprintw(5, 0, "%s's turn. Roll the dice!", name.c_str());
        refresh();

        // Roll the dice and display the roll
        int roll = game.get_dice().roll();
        mvprintw(6, 0, "Rolled a %d", roll);
        refresh();

        // Ask the player for input on where to place the dice
        mvprintw(7, 0, "Choose a column (1-3): ");
        refresh();

        // Use the Input class to capture the player's choice
        Input input_box("Enter column:", 3, 30, 9, 30);
        input_box.printBorder();
        input_box.printInput(9, 45);
        input_box.captureInput();
        input = input_box.get_input();

        int col = std::stoi(input) - 1;  // Convert to 0-based index

        // Place the dice in the selected column and update the score
        if (game.get_grid().place_dice(roll, col)) {
            add_to_score(roll);  // Add points to the score if the dice is placed successfully
        }

        game.display_game_state();  // Refresh game display
    }

    // Method to add points to the player's score
    void add_to_score(int points) {
        score += points;
    }

    // Getter methods for player name and score
    string get_name() const { return name; }
    int get_score() const { return score; }

private:
    string name;  // Player's name
    int score;    // Player's score
};

// Dice class that simulates the rolling of a die
class Dice {
public:
    Dice() : current_value(0) {}

    // Roll the dice and return the result (1 to 6)
    int roll() {
        current_value = rand() % 6 + 1;
        return current_value;
    }

private:
    int current_value;  // The current value of the dice roll
};

// Grid class that manages the placement of dice
class Grid {
public:
    Grid() {
        // Initialize the grid to be empty (0 represents empty)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cells[i][j] = 0;
            }
        }
    }

    // Place the dice in the specified column (stacking vertically)
    bool place_dice(int roll, int col) {
        for (int i = 2; i >= 0; i--) {
            if (cells[i][col] == 0) {  // If the cell is empty
                cells[i][col] = roll;  // Place the dice here
                return true;
            }
        }
        return false;  // If the column is full
    }

    // Check if the grid is full (no empty cells)
    bool is_full() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cells[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Display the grid with the current dice placements
    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mvprintw(i + 3, j * 5, "[%d]", cells[i][j]);
            }
        }
    }

private:
    int cells[3][3];  // 3x3 grid to hold dice values
};

// Main function to start the game
int main() {
    Game game;
    game.start();  // Start the game
    return 0;
}
