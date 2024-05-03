#pragma once
#include <Vector2d.hpp>
#include "RotatingThing.h"
#include <Thing.hpp>
#include "Hazard.h"

class Enemy : public RotatingThing{
    public:
    Enemy(vmi::Vector2d spawnPos);
    ~Enemy();
    void handleCollision(const vmi::Thing* other);
    void move(double dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool goToCenter(double dt);
    static int maxSwarm;
    
    private:
    bool isSwarming;//False: chilling in center; True: Attacking the player
    bool charging; //Whether enemy is going into player's space
    double rotate;
    Hazard* shot;
    static bool canSwarm;//Is another enemy allowed to join the swarm?
    static int swarming;//Amount currently attacking the player
};