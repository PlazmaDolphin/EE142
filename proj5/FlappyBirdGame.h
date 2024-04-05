#pragma once

#include <Game.hpp>
#include "Bird.h"

class FlappyBirdGame : public vmi::Game
{
public:
    FlappyBirdGame();

    // per-frame update
    void update(double dt);

    void startLevel();

    // is the game over?
    bool isOver() const;

private:
    bool done;
    Bird* bird;
};