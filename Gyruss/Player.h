//Class for the player's ship
#pragma once

#include <Graphics.hpp>
#include "RotatingThing.h"
#include <Thing.hpp>
#include <Text.hpp>

class Player : public RotatingThing{
    public:
    Player();
    ~Player();
    
    void handleCollision(const vmi::Thing* other);

    void move(double dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};