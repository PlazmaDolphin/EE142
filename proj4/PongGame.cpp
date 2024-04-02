// Our Pong Game
#include <Game.hpp>
#include <Vector2d.hpp>
#include <Keyboard.hpp>
#include <Color.hpp>

#include "PongGame.h"
#include "Ball.h"
#include "Wall.h"

using namespace vmi;


// Create the game window
PongGame::PongGame() : Game("Pong-ish", 640, 480), done(false)
{
	// create the ball
	ball = new Ball();

	// create the walls
	topWall = new Wall(Vector2d(0, 0), Vector2d(639, 1), Vector2d(0, 1));
	bottomWall = new Wall(Vector2d(0, 478), Vector2d(639, 479), Vector2d(0, -1));
	leftPaddle = new Paddle(Vector2d(50, 200), Vector2d(1,0), Key::W, Key::S);
	rightPaddle = new Paddle(Vector2d(570, 200), Vector2d(-1,0), Key::Up, Key::Down);
	leftWall = new Goal(Vector2d(0, 1), Vector2d(1, 478), rightPaddle);
	rightWall = new Goal(Vector2d(638, 1), Vector2d(639, 478), leftPaddle);
	// serve the ball
	ball->serve(Vector2d(100, 240), Vector2d(1, 0));
}


PongGame::~PongGame()
{
	delete ball;
	delete topWall;
	delete bottomWall;
	delete leftWall;
	delete rightWall;
	delete leftPaddle;
	delete rightPaddle;
}
// Per-frame update for game play
void PongGame::update(double dt)
{
	// is game over?
	if ((leftPaddle->getScore() >= 10) || (rightPaddle->getScore() >= 10)) {
			Key response;

			// post message to user and get response
			do {
					response = Game::createMessage("Play again (Y/N)?",
								Vector2d(175, 200), 40, Color::Yellow);
			} while ((response != Key::Y) && (response != Key::N));

			if (response == Key::Y) {
					// restart the game
					leftPaddle->resetScore();
					rightPaddle->resetScore();

					// serve the ball
					ball->serve(leftPaddle->getServingPosition(),
										leftPaddle->getNormal());
			}

			else {
					// game is over
					done = true;
			}
	}
}

// Whether or not the game is over
bool PongGame::isOver() const
{
	return done;
}