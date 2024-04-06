// This is the ground.

#include <Thing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>

#include "Ground.h"

using namespace vmi;

// Constructor
Ground::Ground() : Thing(
                        Vector2d(0, 550),       // position
                        new SpriteShape("proj5/ground.png")
                    )
{
    // intentionally blank
}

// Destructor
Ground::~Ground()
{
    delete shape;
}

// ignore collisions
void Ground::handleCollision(const Thing* other)
{
    // intentionally blank
}