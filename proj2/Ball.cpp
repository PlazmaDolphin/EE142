#include "Graphics.h"
#include "Vector2d.h"

#include "Ball.h"


// Constructors -- set up the ball's shape and give it an initial position and velocity
Ball::Ball()
{
	// initial position and velocity
	x = Vector2d(10, 10);
	v = Vector2d(120, 90); //TODO: Change this value!!!

	// make the ball a 10x10 square
	shape.setSize(sf::Vector2f(10, 10));
}

// Getter functions
const Vector2d Ball::getX() const
{
	return x;
}

const Vector2d Ball::getV() const
{
	return v;
}

// Move the ball based on velocity and elapsed time
// Input: dt = elapsed time
void Ball::move(double dt)
{
	// calculate new position
   x += v*dt;
 
   // should we bounce off the left or right wall?
   if (x.getX() < 0) {
      // hit left wall, so bounce in x-direction
      v.setX(-v.getX());

      // put ball back on the wall
      x.setX(0);
   }
   else if (x.getX() >= 630) { // wall is at 639, and ball is 10 pixels wide
      // hit right wall, so bounce in x-direction
      v.setX(-v.getX());

      // put ball back on wall
      x.setX(629);
   }

   // check top and bottom walls
   if (x.getY() < 0) {
      // hit top wall
      v.setY(-v.getY());

      // put ball back on wall
      x.setY(0);
   }
   else if (x.getY() >= 470) { // wall is at 479, and ball is 10 pixels wide
      // hit bottom wall
      v.setY(-v.getY());

      // put ball back on wall
      x.setY(469);
   }
}

// Draw the ball
// Input: target = window to draw on
void Ball::draw(sf::RenderTarget& target)
{
	// translate to ball's current position
	sf::Transform transform;
	transform.translate((float)x.getX(), (float)x.getY());

	// draw it there
	target.draw(shape, transform);
}

// Is the ball colliding with another object?
// Input: ul = coordinates of upper-left corner of other object
//        lr = coordinates of lower-right corner of other object
bool Ball::isCollidingWith(const Vector2d& ul, const Vector2d& lr) const
{
   Vector2d myUl = x;
   Vector2d myLr = x + Vector2d(9, 9);  // ball’s lower right corner
   
   return (myUl.getX() < lr.getX()) && (myUl.getY() < lr.getY())
   && (ul.getX() < myLr.getX()) && (ul.getY() < myLr.getY());
}