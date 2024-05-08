//HR: Started from MrBill.cpp
#include <cmath>

#include <Thing.hpp>
#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <Timer.hpp>
#include <VertexShape.hpp>

#include "Alien.h"
#include "Wall.h"
#include "Bullet.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Asteroid.h"
#include "Particle.h"

using namespace vmi;

Alien::Alien(const vmi::Vector2d& x, const vmi::Vector2d& v, const vmi::Vector2d& retreatv)
: MovingThing(x, v, Vector2d(), new VertexShape()),
retreating(false),
retreatVelocity(retreatv)// retreat to the right
{
	// initialize timer to shoot after 2-5 seconds
	int time = rand() % 3 + 2;
	shootTimer = Timer::createTimer(time, [&]() {
		shoot();
	});

	// initialize timer to turn after 3-8 seconds
	time = rand() % 5 + 3;
	turnTimer = Timer::createTimer(time, [&]() {
		turn();
	});

	// and timer to retreat after 15-20 seconds
	time = rand() % 5 + 15;
	retreatTimer = Timer::createTimer(time, [&]() {
		retreat();
	});
}

Alien::~Alien()
{
	// cancel all the timers
	if (shootTimer != nullptr)
		shootTimer->cancel();
	if (turnTimer != nullptr)
		turnTimer->cancel();
	if (retreatTimer != nullptr)
		retreatTimer->cancel();
	delete shape;
}

void Alien::handleCollision(const Thing *other)
{
	// is this a wall?
	if (typeid(*other) == typeid(Wall))
	{
		// are we retreating or attacking?
		if (retreating)
		{
			// we go away when we hit the wall to hide
			die();
		}
		else
		{
			// wraparound our location
			const Wall *wall = dynamic_cast<const Wall *>(other);

			// add offset vector from wall
			x += wall->getOffset();
		}
	}

	// anything else hit is fatal
	else if ((typeid(*other) == typeid(Player)) || (typeid(*other) == typeid(Asteroid)) || (typeid(*other) == typeid(Bullet)) || (typeid(*other) == typeid(PlayerBullet)))
	{
		die();
	}
}

// Explode when we die
void Alien::die()
{
	Particle::explode(this);

	Thing::die();
}

// Turn in a random direction
void Alien::turn()
{
	const double pi = 3.1415926;
	double ang = (rand() % 360) * (pi / 180.0);

	v = 100 * Vector2d(sin(ang), -cos(ang));

	// re-load the timer to turn again
	int time = rand() % 5 + 5; // 5 - 10 seconds
	turnTimer = Timer::createTimer(time, [&]() {
		turn();
	});
}

// Retreat -- move offscreen until we hit a wall
void Alien::retreat()
{
	retreating = true;

	// move to the right
	v = retreatVelocity;

	// cancel any pending turns
	if (turnTimer)
	{
		turnTimer->cancel();
		turnTimer = nullptr;
	}

	// and we only retreat once
	retreatTimer = nullptr;
}
