//Class for the player's ship
#pragma once

#include "RotatingThing.h"
#include "Shot.h"
#include <Thing.hpp>

class Player : public RotatingThing{
    public:
    Player();
    ~Player();
    
    void handleCollision(const vmi::Thing* other);

    void move(double dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
    // list of shots fired by the player
    std::vector<Shot*> shots;
    bool justShot = false;
};