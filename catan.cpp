ghia48.serhan@gmail.com
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

// Enum for Resource Types
enum class ResourceType {
    WOOD,
    BRICK,
    WOOL,
    GRAIN,
    IRON,
    NONE // For desert
};

// Tile Class
class Tile {
public:
    ResourceType resourceType;
    int number;

    Tile(ResourceType resource, int num) : resourceType(resource), number(num) {}
};

// Player Class
class Player {
public:
    int id;
    int victoryPoints;
    std::map<ResourceType, int> resources;

    Player(int playerId) : id(playerId), victoryPoints(2) {
        resources = {
            {ResourceType::WOOD, 0},
            {ResourceType::BRICK, 0},
            {ResourceType::WOOL, 0},
            {ResourceType::GRAIN, 0},
            {ResourceType::IRON, 0}
        };
    }

    void addResource(ResourceType resource, int count) {
        resources[resource] += count;
    }

    bool canBuildSettlement() {
        return resources[ResourceType::WOOD] >= 1 &&
               resources[ResourceType::BRICK] >= 1 &&
               resources[ResourceType::WOOL] >= 1 &&
               resources[ResourceType::GRAIN] >= 1;
    }

    void buildSettlement() {
        if (canBuildSettlement()) {
            resources[ResourceType::WOOD]--;
            resources[ResourceType::BRICK]--;
            resources[ResourceType::WOOL]--;
            resources[ResourceType::GRAIN]--;
            victoryPoints++;
            std::cout << "Player " << id << " built a settlement. Total Victory Points: " << victoryPoints << std::endl;
        } else {
            std::cout << "Player " << id << " cannot build a settlement." << std::endl;
        }
    }
};

// DevelopmentCard Class
class DevelopmentCard {
public:
    virtual void use(Player& player) = 0;
    virtual ~DevelopmentCard() = default;
};

class ProgressCard : public DevelopmentCard {
public:
    void use(Player& player) override {
        // Implement progress card logic
        std::cout << "Player " << player.id << " used a Progress Card." << std::endl;
    }
};

class KnightCard : public DevelopmentCard {
public:
    void use(Player& player) override {
        // Implement knight card logic
        std::cout << "Player " << player.id << " used a Knight Card." << std::endl;
    }
};

class VictoryPointCard : public DevelopmentCard {
public:
    void use(Player& player) override {
        player.victoryPoints++;
        std::cout << "Player " << player.id << " used a Victory Point Card. Total Victory Points: " << player.victoryPoints << std::endl;
    }
};

// Board Class
class Board {
public:
    std::vector<Tile> tiles;

    Board() {
        // Initialize board with tiles
        tiles = {
            Tile(ResourceType::WOOD, 5), Tile(ResourceType::BRICK, 6),
            Tile(ResourceType::WOOL, 8), Tile(ResourceType::GRAIN, 3),
            Tile(ResourceType::IRON, 4), Tile(ResourceType::NONE, 7), // Desert
            // Add other tiles...
        };
    }
};

// Game Class
class Game {
public:
    std::vector<Player> players;
    Board board;

    Game() {
        players = {Player(1), Player(2), Player(3)};
    }

    void play() {
        // Initialize random seed
        std::srand(std::time(0));

        // Implement the game loop
        bool gameEnd = false;
        while (!gameEnd) {
            for (auto& player : players) {
                playerTurn(player);
                if (player.victoryPoints >= 10) {
                    gameEnd = true;
                    std::cout << "Player " << player.id << " wins!" << std::endl;
                    break;
                }
            }
        }
    }

    void playerTurn(Player& player) {
        std::cout << "Player " << player.id << "'s turn." << std::endl;

        // Roll dice
        int diceRoll = rollDice();
        std::cout << "Dice roll: " << diceRoll << std::endl;

        // Gather resources based on dice roll
        gatherResources(diceRoll);

        // Simulate building a settlement
        player.buildSettlement();
    }

    int rollDice() {
        return (std::rand() % 6 + 1) + (std::rand() % 6 +
1);
    }

    void gatherResources(int diceRoll) {
        // Implement resource gathering logic based on dice roll
        for (auto& player : players) {
            // For simplicity, assume each player gets 1 resource for each tile with the rolled number
            for (const auto& tile : board.tiles) {
                if (tile.number == diceRoll) {
                    player.addResource(tile.resourceType, 1);
                    std::cout << "Player " << player.id << " receives 1 " << resourceToString(tile.resourceType) << std::endl;
                }
            }
        }
    }

    std::string resourceToString(ResourceType resource) {
        switch (resource) {
            case ResourceType::WOOD: return "Wood";
            case ResourceType::BRICK: return "Brick";
            case ResourceType::WOOL: return "Wool";
            case ResourceType::GRAIN: return "Grain";
            case ResourceType::IRON: return "Iron";
            case ResourceType::NONE: return "Nothing";
            default: return "Unknown";
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
