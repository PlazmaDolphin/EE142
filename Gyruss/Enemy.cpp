#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Game.hpp>
#include <Keyboard.hpp>
#include "Shot.h"
#include "Enemy.h"
#include "Player.h"

using namespace vmi;
using namespace std;
int Enemy::swarming = 0;
Enemy::Enemy(Vector2d pos)
: RotatingThing(pos, Vector2d(), Vector2d(),
  new SpriteShape("Gyruss/enemy.png"), RESOLUTION, 0.4), shot(new Hazard(x)){
    center = Vector2d(41, 43);
    shot->die(); //Need to initialize shot before checking if it's alive
    isSwarming = false;
}
Enemy::~Enemy(){
    delete shape;
}

void Enemy::move(double dt){
    if(!shot->isAlive() && isSwarming){
        shot = new Hazard(x);
    }
    if(swarming < 3 && !isSwarming && rand()%(int)(3.0/dt)==1){ //join the swarm
        isSwarming = true;
        swarming+=1;
        v.setX(125);
        v.setY(50);
        rotate = 90;
    }
    if(isSwarming && rand()%(int)(30.0/dt)==1){
        rotate += 180; //JUKE EM
        v.setX(-v.getX());
    }
    if(isSwarming && x.getY() > RESOLUTION){ //exit the swarm
        isSwarming=false;
        x.setY(0);
        v = Vector2d();
        swarming-=1;
        rotate = 0;
    }
    //Ensure that 0<=x<RESOLUTION
    x.setX(x.getX()<RESOLUTION ? x.getX(): 0);
    x.setX(x.getX()>=0 ? x.getX(): RESOLUTION);
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
        if(isSwarming){
            isSwarming = false;
            swarming -= 1; //exit the swarm
        }
        die(); //We got shot/hit
    }
}