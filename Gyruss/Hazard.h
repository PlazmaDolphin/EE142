//Class for shots fired by the enemy
#pragma once

#include "RotatingThing.h"
#include <Thing.hpp>
#include <Vector2d.hpp>

class Hazard : public RotatingThing{
    public:
    Hazard(vmi::Vector2d _x);
    ~Hazard();
    
    void handleCollision(const vmi::Thing* other);
    void move(double dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};