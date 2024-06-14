ghia48.serhan@gmail.com
#ifndef TILE_H
#define TILE_H

#include "ResourceType.h"
#include <string> // Add this line

class Tile {
public:
    ResourceType resourceType;
    int number;

    Tile(ResourceType resource, int num);
    std::string resourceToString() const;
};

#endif // TILE_H
