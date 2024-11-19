// Jhymani Joseph PO2C
// Assignment 06
// Due Date: November 18th
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

class Game {
public:
    Game() {
        srand(time(0));  // Seed the random number generator for dice rolls
        current_player = &players[0];  // Player 1 starts by default
    }

    // Main method to start and manage the game
    void start() {
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        start_color();
        keypad(stdscr, TRUE);
        mousemask(ALL_MOUSE_EVENTS, NULL);
        setlocale(LC_ALL, "");

        Colorly::init_colors();

        initialize_players("Player 1", "Player 2");
        grid = Grid();

        while (true) {
            display_game_state();
            take_turn();
            if (check_win()) {
                end_game();
                break;
            }
            switch_turn();
        }

        endwin();  // End Ncurses session
    }

    void initialize_players(string player1_name, string player2_name) {
        players[0] = Player(player1_name);
        players[1] = Player(player2_name);
    }

    void take_turn() {
        current_player->take_turn(*this);
    }

    bool check_win() {
        return grid.is_full();
    }

    void display_game_state() {
        clear();
        grid.display();
        mvprintw(0, 0, "%s's score: %d", players[0].get_name().c_str(), players[0].get_score());
        mvprintw(1, 0, "%s's score: %d", players[1].get_name().c_str(), players[1].get_score());
        refresh();
    }

    void end_game() {
        int score1 = players[0].get_score();
        int score2 = players[1].get_score();

        if (score1 > score2) {
            mvprintw(3, 0, "%s wins!", players[0].get_name().c_str());
        } else if (score2 > score1) {
            mvprintw(3, 0, "%s wins!", players[1].get_name().c_str());
        } else {
            mvprintw(3, 0, "It's a draw!");
        }
        refresh();
        getch();
    }

    void switch_turn() {
        current_player = (current_player == &players[0]) ? &players[1] : &players[0];
    }

    Grid& get_grid() { return grid; }
    Dice& get_dice() { return dice; }
    Player* get_current_player() { return current_player; }

private:
    Dice dice;
    Grid grid;
    Player* current_player;
    Player players[2];
};

class Player {
public:
    Player(string name) : name(name), score(0) {}

    void take_turn(Game& game) {
        string input;
        mvprintw(5, 0, "%s's turn. Roll the dice!", name.c_str());
        refresh();

        int roll = game.get_dice().roll();
        mvprintw(6, 0, "Rolled a %d", roll);
        refresh();

        mvprintw(7, 0, "Choose a column (1-3): ");
        refresh();

        Input input_box("Enter column:", 3, 30, 9, 30);
        input_box.printBorder();
        input_box.printInput(9, 45);
        input_box.captureInput();
        input = input_box.get_input();

        int col = std::stoi(input) - 1;

        if (game.get_grid().place_dice(roll, col)) {
            add_to_score(roll);

            // Check for opponent's dice removal if matching dice are placed
            if (game.get_grid().remove_opponent_dice(col, roll, *this)) {
                // Opponent's dice are removed
            }
        }

        game.display_game_state();
    }

    void add_to_score(int points) {
        score += points;
    }

    string get_name() const { return name; }
    int get_score() const { return score; }

private:
    string name;
    int score;
};

class Dice {
public:
    Dice() : current_value(0) {}

    int roll() {
        current_value = rand() % 6 + 1;
        return current_value;
    }

private:
    int current_value;
};

class Grid {
public:
    Grid() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cells[i][j] = 0;
            }
        }
    }

    bool place_dice(int roll, int col) {
        for (int i = 2; i >= 0; i--) {
            if (cells[i][col] == 0) {
                cells[i][col] = roll;
                return true;
            }
        }
        return false;
    }

    bool remove_opponent_dice(int col, int roll, Player& current_player) {
        for (int i = 0; i < 3; i++) {
            if (cells[i][col] != 0 && cells[i][col] == roll) {
                if (current_player.get_name() == "Player 1") {
                    // Player 1 removes opponent's dice
                    cells[i][col] = 0;
                } else {
                    // Player 2 removes opponent's dice
                    cells[i][col] = 0;
                }
                return true;
            }
        }
        return false;
    }

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

    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mvprintw(i + 3, j * 5, "[%d]", cells[i][j]);
            }
        }
    }

private:
    int cells[3][3];
};

int main() {
    Game game;
    game.start();
    return 0;
}
