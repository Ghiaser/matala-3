ghia48.serhan@gmail.com
#include "Player.h"
#include "DevelopmentCard.h"  // Include the full definition of DevelopmentCard

Player::Player(int playerId) : id(playerId), victoryPoints(2), knightsPlayed(0) {
    resources = {
        {ResourceType::WOOD, 0},
        {ResourceType::BRICK, 0},
        {ResourceType::WOOL, 0},
        {ResourceType::GRAIN, 0},
        {ResourceType::IRON, 0}
    };
}

void Player::addResource(ResourceType resource, int count) {
    resources[resource] += count;
}

bool Player::canBuildSettlement() {
    return resources[ResourceType::WOOD] >= 1 &&
           resources[ResourceType::BRICK] >= 1 &&
           resources[ResourceType::WOOL] >= 1 &&
           resources[ResourceType::GRAIN] >= 1;
}

void Player::buildSettlement() {
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

bool Player::canBuildRoad() {
    return resources[ResourceType::WOOD] >= 1 && resources[ResourceType::BRICK] >= 1;
}

void Player::buildRoad() {
    if (canBuildRoad()) {
        resources[ResourceType::WOOD]--;
        resources[ResourceType::BRICK]--;
        std::cout << "Player " << id << " built a road." << std::endl;
    } else {
        std::cout << "Player " << id << " cannot build a road." << std::endl;
    }
}

bool Player::canBuildCity() {
    return resources[ResourceType::IRON] >= 3 && resources[ResourceType::GRAIN] >= 2;
}

void Player::buildCity() {
    if (canBuildCity()) {
        resources[ResourceType::IRON] -= 3;
        resources[ResourceType::GRAIN] -= 2;
        victoryPoints += 2;
        std::cout << "Player " << id << " built a city. Total Victory Points: " << victoryPoints << std::endl;
    } else {
        std::cout << "Player " << id << " cannot build a city." << std::endl;
    }
}

bool Player::canBuildDevCard() {
    return resources[ResourceType::IRON] >= 1 && resources[ResourceType::WOOL] >= 1 && resources[ResourceType::GRAIN] >= 1;
}

void Player::addDevelopmentCard(DevelopmentCard* card) {
    developmentCards.push_back(card);
}

void Player::useDevelopmentCard(int index, std::vector<Player*>& allPlayers) {
    if (index < developmentCards.size()) {
        developmentCards[index]->use(*this, allPlayers);
        delete developmentCards[index];  // Assume one-time use cards, so delete after use
        developmentCards.erase(developmentCards.begin() + index);
    } else {
        std::cout << "Invalid card index." << std::endl;
    }
}

bool Player::trade(Player& otherPlayer, ResourceType giveResource, ResourceType receiveResource, int amount) {
    std::cout << "Player " << id << " trading " << amount << " " << resourceToString(giveResource)
              << " for " << amount << " " << resourceToString(receiveResource) << " with Player " << otherPlayer.id << std::endl;

    if (resources[giveResource] >= amount && otherPlayer.resources[receiveResource] >= amount) {
        resources[giveResource] -= amount;
        otherPlayer.resources[giveResource] += amount;
        resources[receiveResource] += amount;
        otherPlayer.resources[receiveResource] -= amount;
        return true;
    }
    std::cout << "Trade failed - insufficient resources" << std::endl;
    return false;
}

std::string Player::resourceToString(ResourceType resource) {
    switch (resource) {
        case ResourceType::WOOD: return "Wood";
        case ResourceType::BRICK: return "Brick";
        case ResourceType::WOOL: return "Wool";
        case ResourceType::GRAIN: return "Grain";
        case ResourceType::IRON: return "Iron";
        case ResourceType::NONE: return "None";
        default: return "Unknown";
    }
}
