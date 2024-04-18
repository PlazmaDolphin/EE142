// Class for drawing the background for our game
#pragma once

#include <Thing.hpp>

class Background : public vmi::Thing
{
public:
    Background();
    ~Background();

    void handleCollision(const Thing* other);
};