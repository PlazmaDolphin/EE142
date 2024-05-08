//HR: Started from MrBill.h
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Timer.hpp>

#include "Player.h"

class Alien : public vmi::MovingThing
{
public:
	Alien(const vmi::Vector2d& x, const vmi::Vector2d& v, const vmi::Vector2d& retreat);
	~Alien();
	void handleCollision(const vmi::Thing *other);

	void die();

	virtual int getPoints() const = 0;

protected:
    void turn();	// change direction
	virtual void shoot();	// shoot a bullet
	void retreat(); // run away!
	bool retreating;			   // whether or not we're retreating
	vmi::Vector2d retreatVelocity; // speed and direction when retreating
	vmi::Timer *shootTimer;		   // when to shoot next
	vmi::Timer *turnTimer;		   // when to change direction
	vmi::Timer *retreatTimer;	   // when to retreat
};
