ghia48.serhan@gmail.com
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <vector>
#include "ResourceType.h"

// Forward declare DevelopmentCard class
class DevelopmentCard;

class Player {
public:
    int id;
    int victoryPoints;
    int knightsPlayed;
    std::map<ResourceType, int> resources;
    std::vector<DevelopmentCard*> developmentCards;

    Player(int playerId);
    void addResource(ResourceType resource, int count);
    bool canBuildSettlement();
    void buildSettlement();
    bool canBuildRoad();
    void buildRoad();
    bool canBuildCity();
    void buildCity();
    bool canBuildDevCard();
    void addDevelopmentCard(DevelopmentCard* card);
    void useDevelopmentCard(int index, std::vector<Player*>& allPlayers);
    bool trade(Player& otherPlayer, ResourceType giveResource, ResourceType receiveResource, int amount);
    std::string resourceToString(ResourceType resource);
};

#endif // PLAYER_H
