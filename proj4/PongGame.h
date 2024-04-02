// Our Pong Game
#pragma once

#include <Game.hpp>

#include "Ball.h"
#include "Wall.h"
#include "Paddle.h"
#include "Goal.h"

class PongGame : public vmi::Game
{
public:
	PongGame();
	~PongGame();

	void update(double dt);

	bool isOver() const;

private:
	Ball *ball;
	Wall *topWall;
	Wall *bottomWall;
	Goal *leftWall;
	Goal *rightWall;
	Paddle *leftPaddle;
    Paddle *rightPaddle;

	bool done;
};

