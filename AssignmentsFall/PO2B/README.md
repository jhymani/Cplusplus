### Jhymani Joseph

### Class Design Outline for "Knucklebones" Game

---

#### **Dice Class**

**Data:**
- `sides`: Number of sides on the die (typically 6 for a six-sided die).
- `current_value`: The value of the die after rolling (1 to 6).

**Actions:**
- `roll()`: Randomly set `current_value` to a number between 1 and 6.
- `get_value()`: Return the `current_value` of the die.

**Relationships:**
- **Composition**: A `Player` HAS-A `Dice` for rolling.

---

#### **Player Class**

**Data:**
- `name`: The name of the player.
- `score`: Current score of the player.
- `dice_set`: A collection of `Dice` objects.
- `board`: A 3x3 grid (represented as a 2D array) where dice values are placed.
- `player_stats`: Stats such as wins, losses, and total games played.

**Actions:**
- `roll_dice()`: Roll a die and get its value.
- `place_die(int column, int value)`: Place a rolled die in the specified column on the board.
- `get_score()`: Calculate and retrieve the player's score based on the board, applying any multipliers.
- `update_score()`: Update the score according to the multiplication bonus rules.
- `remove_opponent_die(int column, int value)`: Remove an opponent's die if a matching value is placed in the same column.

**Relationships:**
- **Composition**: `Player` HAS-A `Dice` for rolling.
- **Composition**: `Player` HAS-A `Board` to manage their game state.
- `Player` IS-A participant in the game.

---

#### **Stats Class**

**Data:**
- `grid`: 2D array (3x3) to represent where the player's dice are placed.
- 'played'
- 'wins'
- 'losses'
- 'streak'
**Actions:**
- `place_die(int column, int value)`: Place a die in a specified column.
- `remove_die(int column, int value)`: Remove a die if an opponent places a matching value.
- `calculate_column_score()`: Calculate the score for each column, considering the multiplication bonus.
- `is_full()`: Checks if the board is completely filled (end of game condition).

**Relationships:**
- **Composition**: A `Player` HAS-A `Board` to manage dice placements.
- Used by the `Player` class to place and remove dice.

---

#### **Game Class**

**Data:**
- `players`: An array containing the two `Player` objects.
- `rules`: Set of rules that define the game logic.
- `current_round`: Tracks the current round number.
- `game_state`: Keeps track of whether the game is ongoing or ended.

**Actions:**
- `start_game()`: Begin a new game and set up initial conditions.
- `end_game()`: End the game and declare the winner.
- `get_winner()`: Determine which player has the highest score and declare the winner.
- `play_turn(Player player)`: Manage the flow of a player's turn, including rolling and placing a die.

**Relationships:**
- **Composition**: The `Game` class HAS-A set of `Player` objects.
- A `Game` IS responsible for managing the overall flow and rules of the game.

---

#### **Knucklebones Class**

**Data:**
- `knucklebones_specific_rules`: Rules specific to how Knucklebones is played.
- `round_limit`: The maximum number of rounds (e.g., 9 rounds for filling the grid).

**Actions:**
- `start_round()`: Set up conditions for a new round of Knucklebones.
- `end_round()`: Update scores and proceed to the next round.
- `calculate_winner()`: Calculate the winner based on the score after all rounds.
- `apply_special_rules()`: Apply rules like the multiplication bonus and dice removal.

**Relationships:**
- **Inheritance**: `Knucklebones` inherits from `Game` because it is a specific type of game with particular rules.

---

### Inheritance vs. Composition

- **Inheritance**: 
  - `Knucklebones` inherits from `Game` because it is a specific version of a more general concept of a game, with its own rules and conditions.
  - This allows `Knucklebones` to extend the general game flow while adding rules specific to its gameplay.

- **Composition**:
  - `Player` uses `Dice` to perform rolls, so `Dice` is a component of `Player`.
  - `Player` has a `Board` that tracks dice placements, making `Board` a part of `Player`.
  - `Game` manages `Player` objects, making the players part of the game's flow.

---

### Keywords and Feature Categorization:

- **Necessary:**
  - `name`: Each player needs a name.
  - `score`: Needed to determine the winner.
  - `player stats`: Useful for tracking game history.
  - `winner`: To declare the end result of the game.
  - `dice roll`: Central to the gameplay.
  - `dice removal`: Important for the opponent's dice removal rule.
  - `board`: Needed to manage dice placements for each player.

- **Possible:**
  - `high score`: A nice feature for tracking the highest scores achieved.
  - `leaderboard`: Useful for comparing players' scores.
  - `first name` and `last name`: If a more detailed player profile is needed.
  - `levels`: Could be used if adding difficulty progression to the game.
  - `streak`: To track consecutive wins or losses for a player.

- **Wishful:**
  - `chat` and `messaging`: If integrating a social aspect into the game.
  - `coins`: Could be added as a reward system or in-game currency for customizations.
  - `userid`: If expanding to an online multiplayer platform with login functionality.
  - `team stats` and `teams`: Useful if extending the game to multiplayer teams.

-----
