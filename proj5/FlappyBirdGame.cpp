// Our Flappy Bird knock-off
#include <Game.hpp>

#include "FlappyBirdGame.h"
#include "Bird.h"

using namespace vmi;

FlappyBirdGame::FlappyBirdGame()
    : Game("Bird That Flaps", 800, 600), done(false)
{
    startLevel();
}

// per-frame update
void FlappyBirdGame::update(double dt)
{
    // blank for now
}

// is the game over?
bool FlappyBirdGame::isOver() const
{
    return done;
}

// Start a new level by creating everything
void FlappyBirdGame::startLevel()
{
    bird = new Bird();
}