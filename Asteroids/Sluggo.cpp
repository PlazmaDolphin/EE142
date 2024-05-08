// Sluggo is the larger alien spaceship. He has two different states to be in -- attacking or retreating.
// When attacking, he moves in a random fashion, and fires a bullet every once in a while. He does not aim
// his bullets -- just fires in a random direction. After a while, he goes to retreat mode, where he moves
// off the left side of the screen. He then disappears.
//
// To get the random motion, we pick a velocity in a random direction, and then set a timer to go off
// to change the direction. We also use timers to decide when to change state.

#include <cmath>

#include <Thing.hpp>
#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <Timer.hpp>
#include <VertexShape.hpp>

#include "Sluggo.h"
#include "Wall.h"
#include "Bullet.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Asteroid.h"
#include "Particle.h"

using namespace vmi;

Sluggo::Sluggo() : Alien(Vector2d(-40, 50), Vector2d(100, 0), Vector2d(-100, 0))
{
	// build the shape
	VertexShape *vs = dynamic_cast<VertexShape *>(shape);
	vs->moveTo(Vector2d(-24, 4));
	vs->lineTo(Vector2d(-8, -4));
	vs->lineTo(Vector2d(-5, -13));
	vs->lineTo(Vector2d(5, -13));
	vs->lineTo(Vector2d(8, -4));
	vs->lineTo(Vector2d(24, 4));
	vs->lineTo(Vector2d(12, 13));
	vs->lineTo(Vector2d(-12, 13));
	vs->lineTo(Vector2d(-24, 4));
	vs->moveTo(Vector2d(-8, -4));
	vs->lineTo(Vector2d(8, -4));
}

//Alien does the work for us
Sluggo::~Sluggo(){}

// Sluggo is worth 200 points
int Sluggo::getPoints() const
{
	return 200;
}

// Shoot in a random direction, and then reload to shoot again in 2-5 seconds
void Sluggo::shoot()
{
	const double pi = 3.1415926;
	double ang = (rand() % 360) * (pi / 180.0); // random direction

	Vector2d dir(sin(ang), -cos(ang));

	// shoot the bullet
	new Bullet(x + 40 * dir, dir);

	// re-load the timer to shoot again
	int time = rand() % 3 + 2; // 2 - 5 seconds
	shootTimer = Timer::createTimer(time, [&]() {
		shoot();
	});
}