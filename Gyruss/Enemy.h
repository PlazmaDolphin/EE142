#pragma once
#include <Vector2d.hpp>
#include "RotatingThing.h"
#include <Thing.hpp>

class Enemy : public RotatingThing{
    public:
    Enemy(vmi::Vector2d spawnPos);
    ~Enemy();
    void handleCollision(const vmi::Thing* other);
    void move(double dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
    double rotate;
};