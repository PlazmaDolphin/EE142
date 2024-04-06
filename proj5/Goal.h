// Goal -- the goal is an invisible line just to the right of each pipe.
// The goal moves with the pipes. We use the goals to score points --
// when the bird collides with the goal, then we know it has
// successfully passed through the pipes.

#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>

class Goal : public vmi::MovingThing
{
public:
    Goal();
    ~Goal();

    void handleCollision(const vmi::Thing* other);
};