// This is the bird, our main character

#include <sstream>

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Keyboard.hpp>
#include <Game.hpp>

#include "Bird.h"
#include "Ground.h"
#include "Pipe.h"

using namespace vmi;

// Create our bird in the center of the window. Acceleration is due
// to gravity. Use a sprite for the shape
// Create our bird in the center of the window. Acceleration is due
// to gravity. Use a sprite for the shape
Bird::Bird() : MovingThing(
                    Vector2d(375, 275),     // initial position near center
                    Vector2d(),             // no velocity
                    Vector2d(0, 980),       // acceleration from gravity
                    new SpriteShape("proj5/bird.png")     // image for sprite
                )
{
    // set the center of the bird (image is 51x36, so half that)
    center = Vector2d(25, 18);
}

// Delete the bird's shape
Bird::~Bird()
{
    delete shape;
}

// Handle collisions with other things
void Bird::handleCollision(const Thing* other)
{
    // if we hit the ground or the pipe, then we're done for
    if ((typeid(*other) == typeid(Ground))
        || (typeid(*other) == typeid(Pipe)))
    {
        die();  
    }
}

// Move the bird. If the spacebar is pressed, the bird moves
// upward with a constant velocity. Otherwise, use the default
// move() function to apply gravity.
void Bird::move(double dt)
{
    if (Game::isKeyPressed(Key::Space)) {
        // constant velocity upwards
        v.setY(-200); //CHANGE THIS
    }

    // rotate based on speed (trial-and-error to figure out how
    // fast to rotate)
    w = v.getY() / 3.0;

    // now move him
    MovingThing::move(dt);

    // don't rotate too much (trial-and-error to figure out max angle)
    angle = (angle < -15) ? -15
            : (angle > 15) ? 15
            : angle;
}