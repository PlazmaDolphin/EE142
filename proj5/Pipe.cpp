// A pipe in Flappy Bird. Note that pipes always appear in pairs, and
// we use the same class for both top and bottom pipes (the pipes
// extend past the borders of the window).

#include <Thing.hpp>
#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Timer.hpp>
#include "Wall.h"
#include "Pipe.h"
#include "Goal.h"

using namespace vmi;

// Create a pipe at the given location with constant velocity
// (moving leftward)
Pipe::Pipe(const Vector2d& _x)
    : MovingThing(
        _x,                     // initial position
        Vector2d(-100, 0),      // moving leftward
        Vector2d(),             // no acceleration
        new SpriteShape("proj5/pipe.png"),
        1.0                     // z-ordering, puts pipe behind ground
    )
{
    // intentionally blank
}

Pipe::~Pipe()
{
    delete shape;
}

void Pipe::handleCollision(const Thing* other)
{
    // we die if we hit the wall
    if (typeid(*other) == typeid(Wall))
    {
        die();
    }
}

// Factory function to create pair of pipes. The gap between them
// is 150 pixels, and the location of the top of the gap is
// randomized between 150 and 300. The pipes are spaced between
// 4 and 8 seconds apart.
void Pipe::createPipes()
{
    // pick location of top of the gap
    double topOfGap = rand() % 150 + 150;       // between 150 and 300

    // location of top pipe is 500 above top of gap (pipe is 500 tall)
    new Pipe(Vector2d(800, topOfGap - 500));

    // location of bottom pipe is 150 below top of gap
    new Pipe(Vector2d(800, topOfGap + 150));

    // create a new goal that will follow the pipes
    new Goal();

    // now set up to create the next pipes after a delay
    int delayTime = rand() % 4 + 4;         // between 4 and 8 seconds
    Timer::createTimer(delayTime, []() { Pipe::createPipes(); });
}