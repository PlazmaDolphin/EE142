// Class for drawing the background for our game

#include <Vector2d.hpp>
#include <Thing.hpp>
#include <SpriteShape.hpp>

#include "Background.h"

using namespace vmi;

Background::Background() : Thing(Vector2d(),            // position
                                new SpriteShape("proj5/background.png"),  // sprite
                                2)                      // put in background
{
    // intentionally blank
}                        

Background::~Background()
{
    delete shape;
}

void Background::handleCollision(const Thing* other)
{
    // intentionally  blank
}