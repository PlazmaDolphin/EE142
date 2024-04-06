// The wall is off the left side of the screen. Its purpose is to be an
// obstacle for the pipes so they can be destroyed after they move
// off screen

#pragma once

#include <Thing.hpp>

class Wall : public vmi::Thing
{
public:
    Wall();
    ~Wall();

    void handleCollision(const vmi::Thing* other);
};