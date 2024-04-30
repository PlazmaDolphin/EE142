#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Keyboard.hpp>
#include <Game.hpp>


#include "Player.h"
using namespace vmi;

Player::Player()
: RotatingThing(Vector2d(RESOLUTION*0.25, RESOLUTION*0.85), Vector2d(), Vector2d(),
new SpriteShape("Gyruss/ship_center.png"), RESOLUTION, 1.5){
    center = Vector2d(20, 21);
}
Player::~Player(){
    delete shape;
}

void Player::handleCollision(const Thing* other){
    return; //nothing else exists yet
}
//Move by rotating in a circle
void Player::move(double dt){
    if( ( Game::isKeyPressed(Key::Space) || Game::isKeyPressed(Key::Slash) )&& shots.size()<3){
        if(!justShot){
            justShot = true;
            shots.push_back(new Shot(x.getX()));
        }
    }
    else justShot=false;
    for(Shot* s: shots){
        if(!s->isAlive()){
            shots.erase(std::find(shots.begin(), shots.end(), s));
        }
    }

    x.setX(x.getX()<RESOLUTION ? x.getX(): 0);
    x.setX(x.getX()>=0 ? x.getX(): RESOLUTION);
    double move; //target angle according to keys
    if(Game::isKeyPressed(Key::W)){
        if(Game::isKeyPressed(Key::A)) move = 135.0;
        else if(Game::isKeyPressed(Key::D)) move = 225.0;
        else move = 180.0;
    }
    else if(Game::isKeyPressed(Key::S)){
        if(Game::isKeyPressed(Key::A)) move = 45.0;
        else if(Game::isKeyPressed(Key::D)) move = 315.0;
        else move = 0.0;
    }
    else if(Game::isKeyPressed(Key::A)) move = 90.0;
    else if(Game::isKeyPressed(Key::D)) move = 270.0;
    else{
        v.setX(0);
        return;
    }
    if(std::fmod(angle-(move-180),360)-180<0) v.setX(200);
    else(v.setX(-200));
    angle = 270+360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the ship
    RotatingThing::draw(target, states);
}