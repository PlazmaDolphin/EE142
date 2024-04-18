// The sky -- we use this so we can kill the bird if it flies off the window

#include <Vector2d.hpp>
#include <Thing.hpp>
#include <PolygonShape.hpp>
#include <Color.hpp>

#include "Sky.h"

using namespace vmi;

// Constructor -- the sky is a transparent 1-pixel rectangle
Sky::Sky() : Thing(Vector2d(), new PolygonShape())
{
    // build the polygon
    PolygonShape *p = dynamic_cast<PolygonShape*>(shape);

    p->addPoint(Vector2d(0, 0));
    p->addPoint(Vector2d(799, 0));
    p->addPoint(Vector2d(799, 1));
    p->addPoint(Vector2d(0, 1));
    p->setFill(Color::Transparent);
}

Sky::~Sky()
{
    delete shape;
}

// ignore any collisions
void Sky::handleCollision(const Thing* other)
{
    // intentionally blank
}