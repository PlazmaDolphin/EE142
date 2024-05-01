//Class for the player's ship
#pragma once

#include "RotatingThing.h"
#include "Shot.h"
#include <Text.hpp>
#include <Thing.hpp>

class Player : public RotatingThing{
    public:
    Player();
    ~Player();
    
    void handleCollision(const vmi::Thing* other);

    void move(double dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void reset();
    void warp(); //level clear animation
    bool animDone();//whether animation is complete
    void updateStage(int stage);
    private:
    // list of shots fired by the player
    std::vector<Shot*> shots;
    bool justShot = false;
    vmi::Text scoreText;
    vmi::Text stageText;
    int anim; //Animation state
};