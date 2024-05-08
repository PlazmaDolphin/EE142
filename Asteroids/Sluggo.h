// Sluggo is the larger alien spaceship. He has two different states to be in -- attacking or retreating.
// When attacking, he moves in a random fashion, and fires a bullet every once in a while. He does not aim
// his bullets -- just fires in a random direction. After a while, he goes to retreat mode, where he moves
// off the left side of the screen. He then disappears.
//
// To get the random motion, we pick a velocity in a random direction, and then set a timer to go off
// to change the direction. We also use timers to decide when to change state.

#pragma once

#include <Vector2d.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Timer.hpp>
#include "Alien.h"

class Sluggo : public Alien
{
public:
	Sluggo();
	~Sluggo();

	int getPoints() const;

private:
	void shoot();	// shoot a bullet
	void retreat(); // run away!
};
