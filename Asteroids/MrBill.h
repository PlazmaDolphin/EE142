// Mr. Bill is the smaller alien spaceship. He has two different states to be in -- attacking or retreating.
// When attacking, he moves in a random fashion, and fires a bullet every once in a while. He aims
// his bullets toward the player's ship. After a while, he goes to retreat mode, where he moves
// off the right side of the screen. He then disappears.
//
// To get the random motion, we pick a velocity in a random direction, and then set a timer to go off
// to change the direction. We also use timers to decide when to change state.

#pragma once

#include <Vector2d.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Timer.hpp>

#include "Player.h"
#include "Alien.h"

class MrBill : public Alien
{
public:
	MrBill(const Player *player);
	~MrBill();


	int getPoints() const;

private:
	const Player *player; // need to know where the player is to aim
	void shoot();	// shoot a bullet
	void retreat(); // run away!
};
