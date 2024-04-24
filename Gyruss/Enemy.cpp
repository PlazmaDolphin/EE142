#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Game.hpp>
#include <Keyboard.hpp>
#include "Enemy.h"

using namespace vmi;

Enemy::Enemy(Vector2d pos)
: RotatingThing(pos, Vector2d(), Vector2d(), new SpriteShape("Gyruss/enemy.png"), RESOLUTION, 0.5){
    center = Vector2d(41, 43);
}
Enemy::~Enemy(){
    delete shape;
}

void Enemy::move(double dt){
    if(Game::isKeyPressed(Key::Q)){
        rotate += 5;
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
    std::cout<<"HIT!"<<rand()<<std::endl;
}