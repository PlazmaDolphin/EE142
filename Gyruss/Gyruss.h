#pragma once

#include <Game.hpp>
#include "Player.h"
#include "Enemy.h"

class Gyruss : public vmi::Game
{
public:
    Gyruss();

    // per-frame update
    void update(double dt);

    void startLevel();
    void genStage();
    // is the game over?
    bool isOver() const;

private:
    bool done;
    Player* player;
    std::vector<Enemy*> badGuys;
    int stage;
};