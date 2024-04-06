// Goal -- the goal is an invisible line just to the right of each pipe.
// The goal moves with the pipes. We use the goals to score points --
// when the bird collides with the goal, then we know it has
// successfully passed through the pipes.

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <PolygonShape.hpp>
#include <Color.hpp>

#include "Wall.h"
#include "Bird.h"
#include "Goal.h"

using namespace vmi;

// The goal is a thin transparent rectangle
Goal::Goal() : MovingThing(
                   Vector2d(900, 0),  // pipe starts at 800, is 50
                                      //   wide, and bird is 50 wide
                   Vector2d(-100, 0), // same velocity as pipes
                   Vector2d(),        // no acceleration
                   new PolygonShape())
{
    // add points to shape to make thin rectangle
    PolygonShape *p = dynamic_cast<PolygonShape *>(shape);
    p->addPoint(Vector2d(0, 0));
    p->addPoint(Vector2d(1, 0));
    p->addPoint(Vector2d(1, 600));
    p->addPoint(Vector2d(0, 600));
    p->setFill(Color::Transparent);
}

Goal::~Goal()
{
    delete shape;
}

void Goal::handleCollision(const Thing *other)
{
    // stop when we hit the wall, and die if we
    // hit the bird (so he only scores 1 point)
    if ((typeid(*other) == typeid(Wall))
                || (typeid(*other) == typeid(Bird)))
    {
        die();
    }
}