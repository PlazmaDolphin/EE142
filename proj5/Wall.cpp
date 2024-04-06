// The wall is off the left side of the screen. Its purpose is to be
// an obstacle for the pipes so they can be destroyed after they move
// off screen.

#include <Thing.hpp>
#include <Vector2d.hpp>
#include <PolygonShape.hpp>
#include <Color.hpp>

#include "Wall.h"

using namespace vmi;

// put the wall off screen as a thin rectangle
Wall::Wall() : Thing(Vector2d(-50, 0), new PolygonShape())
{
    // add points to the shape
    PolygonShape *p = dynamic_cast<PolygonShape*>(shape);

    p->addPoint(Vector2d(0, 0));
    p->addPoint(Vector2d(1, 0));
    p->addPoint(Vector2d(1, 600));
    p->addPoint(Vector2d(0, 600));
    p->setFill(Color::Transparent);
}

Wall::~Wall()
{
    delete shape;
}

void Wall::handleCollision(const Thing* other)
{
    // ignore collisions
}