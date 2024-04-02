// Class to represent our ball.

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <PolygonShape.hpp>
#include <Color.hpp>
#include <Timer.hpp>

#include "Ball.h"
#include "Wall.h"
#include "Paddle.h"
#include "Goal.h"
using namespace vmi;



// Create ball as a 10x10 rectangle
Ball::Ball() : MovingThing(Vector2d(),  // position
							Vector2d(),	// velocity
							Vector2d(), // acceleration
							new PolygonShape())
{
	// build the shape as a 10x10 square
	PolygonShape *polygon = dynamic_cast<PolygonShape*>(shape);

	polygon->addPoint(Vector2d(0, 0));
	polygon->addPoint(Vector2d(9, 0));
	polygon->addPoint(Vector2d(9, 9));
	polygon->addPoint(Vector2d(0, 9));
	polygon->setFill(Color::White);
}


Ball::~Ball()
{
	// delete the shape
	delete shape;
}


// Handle collisions with other things
void Ball::handleCollision(const Thing* other)
{
	// is this a wall?
	if (typeid(*other) == typeid(Wall)) {
		// bounce off the wall
		bounce(dynamic_cast<const Wall*>(other)->getNormal());
	}
	if (typeid(*other) == typeid(Paddle)) {
		// bounce off the wall
		bounce(dynamic_cast<const Paddle*>(other)->getNormal());
	}
	// is this a goal?
	else if (typeid(*other) == typeid(Goal)) {
			// re-serve the ball
			const Paddle *player =
					dynamic_cast<const Goal*>(other)->getPlayer();

			// get position and direction to serve from
			Vector2d newPos = player->getServingPosition();
			Vector2d newDir = player->getNormal();

			// serve the ball
			// move the ball off screen and stop moving
           x = Vector2d(-100, -100);
           v = Vector2d();
 
           // serve the ball after a 0.5 second delay
           if (player->getScore() < 10)
           {
              Timer::createTimer(0.5, [&, player]() {
                 // get position and direction to serve from
                 Vector2d newPos = player->getServingPosition();
                 Vector2d newDir = player->getNormal();
 
                 // serve the ball
                 serve(newPos, newDir);
              });
           }
	}
	// otherwise, ignore the collision
}

// Bounce off an object in the given direction
void Ball::bounce(const Vector2d& n)
{
	// move away from the object a little bit
	x += 10 * n;

	// reverse our direction
	v -= 2 * v.dot(n) * n;
}

// Serve the ball -- move it to the given position and give it
// a random velocity in the given direction.
// Input: position = new position
//        dir = direction to move
void Ball::serve(const Vector2d& position, const Vector2d& dir)
{
	// move to new location
	x = position;

	// move in the new direction -- this is some 
	//   random number voodoo here
	int y_dir = (rand() % 2) * 2 - 1;		// y_dir is either -1 or +1
	double x_speed = rand() % 100 + 100;	// between 100 and 200
	double y_speed = rand() % 100 + 100;	// between 100 and 200

	v = x_speed * dir + y_speed * Vector2d(0, y_dir);
}