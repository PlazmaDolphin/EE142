#pragma once

#include <Vector2d.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Timer.hpp>

#include "Player.h"

class Alien : public vmi::MovingThing
{
public:
	Alien(const Player *player);
	~Alien();
	void handleCollision(const vmi::Thing *other);

	void die();

	int getPoints() const;

private:
	bool retreating;			   // whether or not we're retreating
	vmi::Vector2d retreatVelocity; // speed and direction when retreating
	vmi::Timer *shootTimer;		   // when to shoot next
	vmi::Timer *turnTimer;		   // when to change direction
	vmi::Timer *retreatTimer;	   // when to retreat

	const Player *player; // need to know where the player is to aim

	void turn();	// change direction
	void shoot();	// shoot a bullet
	void retreat(); // run away!
};
