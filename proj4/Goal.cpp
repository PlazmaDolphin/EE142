#include <PolygonShape.hpp>
#include "Goal.h"
#include "Ball.h"
using namespace vmi;

Goal::Goal(const Vector2d& ul, const Vector2d& lr, Paddle* owner)
:Thing(ul, new PolygonShape()), pad(owner) //HR: Col. Baker added pad(owner) to fix segfault
{
	// figure out size of wall
	double width = lr.getX() - ul.getX() + 1;
	double height = lr.getY() - ul.getY() + 1;

	// make the shape a rectangle
	PolygonShape* polygon = dynamic_cast<PolygonShape*>(shape);

	polygon->addPoint(Vector2d(0, 0));
	polygon->addPoint(Vector2d(width - 1, 0));
	polygon->addPoint(Vector2d(width - 1, height - 1));
	polygon->addPoint(Vector2d(0, height - 1));

	// make the wall yellow
	polygon->setFill(Color::Yellow);
}
Goal::~Goal(){
	delete shape;
}

void Goal::handleCollision(const Thing* other){
	if (typeid(*other) == typeid(Ball)) {
		pad->scorePoint();
	}
}