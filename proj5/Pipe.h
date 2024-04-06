// A pipe in Flappy Bird. Note that pipes always appear in pairs

#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>

class Pipe : public vmi::MovingThing
{
public:
    Pipe(const vmi::Vector2d& _x);
    ~Pipe();

    void handleCollision(const vmi::Thing* other);

public:
    // factory function to create a pair of pipes
    static void createPipes();
};