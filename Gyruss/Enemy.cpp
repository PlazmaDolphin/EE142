#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Game.hpp>
#include <Keyboard.hpp>
#include "Shot.h"
#include "Enemy.h"
#include "Player.h"

using namespace vmi;

Enemy::Enemy(Vector2d pos)
: RotatingThing(pos, Vector2d(), Vector2d(),
  new SpriteShape("Gyruss/enemy.png"), RESOLUTION, 0.5), shot(new Hazard(x)){
    center = Vector2d(41, 43);
    shot->die(); //Need to initialize shot before checking if it's alive
}
Enemy::~Enemy(){
    delete shape;
}

void Enemy::move(double dt){
    if(!shot->isAlive()){
        shot = new Hazard(x);
    }
    angle = rotate+270+360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
}
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the ship
    RotatingThing::draw(target, states);
}

void Enemy::handleCollision(const vmi::Thing* other){
    if(typeid(*other)==typeid(Shot)
    || typeid(*other)==typeid(Player)){
        die(); //We got shot/hit
    }
}