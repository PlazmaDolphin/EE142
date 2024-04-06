// Our Flappy Bird knock-off
#include <Game.hpp>

#include "FlappyBirdGame.h"
#include "Bird.h"
#include "Ground.h"
#include "Pipe.h"

using namespace vmi;

FlappyBirdGame::FlappyBirdGame()
    : Game("Bird That Flaps", 800, 600), done(false)
{
    startLevel();
}

// per-frame update
void FlappyBirdGame::update(double dt)
{
    // check if bird is still alive
    if (!bird->isAlive()) {
        Key response;

        // display message to user
        do {
            response = Game::createMessage("Play again (Y/N)?",
                            Vector2d(200, 200), 60, Color::Yellow
            );
        } while (response != Key::Y && response != Key::N);

        // do we play again?
        if (response == Key::Y) {
            // first, cancel all active timers
            Timer::cancelAllTimers();

            // next, kill all game characters so we can re-start
            Thing::killAllThings();

            // finally, restart the level
            startLevel();
        }

        else {
            // don't play again
            done = true;
        }
    }
}

// is the game over?
bool FlappyBirdGame::isOver() const
{
    return done;
}

// Start a new level by creating everything
void FlappyBirdGame::startLevel()
{
    new Ground();
   
    bird = new Bird();

    // start creating pipes
    Pipe::createPipes();
}