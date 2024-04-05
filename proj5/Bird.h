// This is the bird, our main character

#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>

class Bird : public vmi::MovingThing
{
public:
    Bird();
    ~Bird();

    void handleCollision(const vmi::Thing* other);

    void move(double dt);
};