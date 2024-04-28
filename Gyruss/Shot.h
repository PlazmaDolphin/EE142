//Class for shots fired by the player
#pragma once

#include "RotatingThing.h"
#include <Thing.hpp>

class Shot : public RotatingThing{
    public:
    Shot(double x_val);
    ~Shot();
    
    void handleCollision(const vmi::Thing* other); //Skipped
    void move(double dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};