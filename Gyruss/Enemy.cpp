#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Game.hpp>
#include <Keyboard.hpp>
#include <Timer.hpp>
#include "Shot.h"
#include "Enemy.h"
#include "Player.h"

using namespace vmi;
using namespace std;
int  Enemy::swarming = 0;
bool Enemy::canSwarm = true;
Enemy::Enemy(Vector2d pos)
: RotatingThing(pos, Vector2d(), Vector2d(),
  new SpriteShape("Gyruss/enemy.png"), RESOLUTION, 0.55), shot(new Hazard(x)){
    center = Vector2d(41, 43);
    shot->die(); //Need to initialize shot before checking if it's alive
    isSwarming = false;
    charging = false;
    canSwarm = true;
}
Enemy::~Enemy(){
    delete shape;
}

void Enemy::move(double dt){
    if(!shot->isAlive() && isSwarming){
        shot = new Hazard(x);
    }
    if(swarming < 3 && !isSwarming && canSwarm && rand()%30==1){ //join the swarm
        isSwarming = true;
        canSwarm = false;
        Timer::createTimer(1, [&](){canSwarm=true;});
        swarming+=1;
        v.setX(125);
        v.setY(75);
        rotate = 90;
    }
    if(isSwarming && rand()%(int)(20.0/dt)==1){
        rotate += 180; //JUKE EM
        v.setX(-v.getX());
    }
    if(isSwarming && x.getY() > RESOLUTION*0.5 && !charging){
        if(rand()%2==0){ //Head straight for the player
            v=Vector2d(0, 120);
            rotate = 0;
            charging = true;
        }
        else{ //Quickly return to the center
            v=Vector2d(20, -180);
            rotate = 180;
        }
    }
    if(isSwarming && (x.getY() > RESOLUTION || 0 > x.getY())){ //exit the swarm
        isSwarming=false;
        charging=false;
        x.setY(0);
        v = Vector2d();
        swarming-=1;
        rotate = 0;
    }
    if(!isSwarming) v.setX(10); //Center enemies rotate slowly
    //Ensure that 0<=x<RESOLUTION
    x.setX(x.getX()<RESOLUTION ? x.getX():0);
    x.setX(x.getX()>=0?x.getX(): RESOLUTION);
    angle = rotate+270+360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
}

bool Enemy::goToCenter(double dt){
    //head to center
    v=Vector2d(20, -250);
    rotate = 180;
    //set flag variables so nobody tries to swarm
    isSwarming = false;
    canSwarm = false;
    charging = false;
    swarming = 0;
    //If enemy has returned to center, return true
    if(isSwarming && (x.getY() > RESOLUTION || 0 > x.getY())){ //exit the swarm
        x.setY(0);
        v = Vector2d();
        rotate = 0;
        return true;
    }
    return false;
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