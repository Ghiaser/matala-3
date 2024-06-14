ghia48.serhan@gmail.com
# Catan Game README

## Introduction

This project is a simplified version of the popular board game "Catan" implemented in C++. The game involves three players who trade, build, and compete to reach 10 victory points to win the game. The implementation includes various classes to represent the game board, players, tiles, and development cards.

## Class and Method Descriptions

### Board Class

**Header File: `Board.h`**
**Source File: `Board.cpp`**

The `Board` class represents the game board consisting of 19 tiles.

#### Methods

- **Constructor: `Board()`**
  - Initializes the board with 19 predefined tiles representing different resources and numbers.
  
- **`void printBoard() const`**
  - Prints the layout of the board, showing each tile's resource type and number.

### DevelopmentCard Class

**Header File: `DevelopmentCard.h`**
**Source File: `DevelopmentCard.cpp`**

The `DevelopmentCard` class is an abstract base class for different types of development cards in the game.

#### Derived Classes and Their Methods

- **MonopolyCard**
  - **`void use(Player& player, std::vector<Player*>& allPlayers)`**
    - Allows the player to choose a resource and take all of that resource from other players.

- **RoadBuildingCard**
  - **`void use(Player& player, std::vector<Player*>& allPlayers)`**
    - Allows the player to build two roads for free.

- **YearOfPlentyCard**
  - **`void use(Player& player, std::vector<Player*>& allPlayers)`**
    - (Empty implementation to satisfy pure virtual function requirement).
  - **`void use(Player& player, std::vector<Player*>& allPlayers, ResourceType resource1, ResourceType resource2)`**
    - Allows the player to choose two resources to gain.

- **KnightCard**
  - **`void use(Player& player, std::vector<Player*>& allPlayers)`**
    - Allows the player to move the robber and potentially earn additional victory points.

- **VictoryPointCard**
  - **`void use(Player& player, std::vector<Player*>& allPlayers)`**
    - Grants the player one additional victory point.

### Game Class

**Header File: `Game.h`**
**Source File: `Game.cpp`**

The `Game` class manages the overall gameplay, including player turns, resource gathering, and determining the winner.

#### Methods

- **Constructor: `Game()`**
  - Initializes the game with three players.
  
- **`void play()`**
  - Manages the main game loop, allowing players to take turns until one player reaches 10 victory points.
  
- **`void playerTurn(Player& player)`**
  - Handles the actions taken by a player during their turn.
  
- **`int rollDice()`**
  - Simulates rolling two six-sided dice.
  
- **`void gatherResources(int diceRoll)`**
  - Allocates resources to players based on the dice roll and the tiles' numbers.
  
- **`DevelopmentCard* drawDevelopmentCard()`**
  - Draws a random development card.

- **`std::string resourceToString(ResourceType resource)`**
  - Converts a resource type to its string representation.

### Player Class

**Header File: `Player.h`**
**Source File: `Player.cpp`**

The `Player` class represents a player in the game, managing their resources, development cards, and actions.

#### Methods

- **Constructor: `Player(int playerId)`**
  - Initializes a player with a given ID, initial victory points, and empty resources.
  
- **`void addResource(ResourceType resource, int count)`**
  - Adds a specified amount of a resource to the player's inventory.
  
- **`bool canBuildSettlement()`**
  - Checks if the player has enough resources to build a settlement.
  
- **`void buildSettlement()`**
  - Builds a settlement, deducting the necessary resources and adding a victory point.
  
- **`bool canBuildRoad()`**
  - Checks if the player has enough resources to build a road.
  
- **`void buildRoad()`**
  - Builds a road, deducting the necessary resources.
  
- **`bool canBuildCity()`**
  - Checks if the player has enough resources to build a city.
  
- **`void buildCity()`**
  - Builds a city, deducting the necessary resources and adding two victory points.
  
- **`bool canBuildDevCard()`**
  - Checks if the player has enough resources to build a development card.
  
- **`void addDevelopmentCard(DevelopmentCard* card)`**
  - Adds a development card to the player's inventory.
  
- **`void useDevelopmentCard(int index, std::vector<Player*>& allPlayers)`**
  - Uses a development card from the player's inventory.

- **`bool trade(Player& otherPlayer, ResourceType giveResource, ResourceType receiveResource, int amount)`**
  - Facilitates trading resources between players.

- **`std::string resourceToString(ResourceType resource)`**
  - Converts a resource type to its string representation.

### Tile Class

**Header File: `Tile.h`**
**Source File: `Tile.cpp`**

The `Tile` class represents a single tile on the game board, holding a resource type and a number.

#### Methods

- **Constructor: `Tile(ResourceType resource, int num)`**
  - Initializes a tile with a given resource type and number.
  
- **`std::string resourceToString() const`**
  - Converts the tile's resource type to its string representation.

## Running the Game

To run the game, compile the source files and execute the main program:
g++  main.cpp Game.cpp Board.cpp Player.cpp DevelopmentCard.cpp Tile.cpp -o catan
./catan


to run tests :
g++ -std=c++17 -o runTests Main.cpp TestPlayer.cpp  Board.cpp DevelopmentCard.cpp Game.cpp player.cpp Tile.cpp -I.
./runtests
```cpp
#include "Game.h"

int main() {
    Game game;
    game.play();
    return 0;
}
```

The game will simulate turns for three players, allowing them to gather resources, build, and use development cards until one player reaches 10 victory points and wins the game.

## Conclusion

This implementation of Catan provides a simplified but functional version of the game, demonstrating key concepts of object-oriented programming and game mechanics. Future enhancements could include more sophisticated AI for player actions, a graphical interface, and networked multiplayer support.