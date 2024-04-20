#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Keyboard.hpp>
#include <Game.hpp>


#include "Player.h"
using namespace vmi;

Player::Player()
: RotatingThing(Vector2d(RESOLUTION, RESOLUTION), Vector2d(), Vector2d(),
new SpriteShape("Gyruss/ship_center.png"), RESOLUTION){
    center = Vector2d(20, 21);
}
Player::~Player(){
    delete shape;
}

void Player::handleCollision(const Thing* other){
    return; //nothing else exists yet
}

void Player::move(double dt){
    if(Game::isKeyPressed(Key::A)){
        v.setX(-200);
    }
    else if(Game::isKeyPressed(Key::D)){
        v.setX(200);
    }
    else{
        v.setX(0);
    }
    angle = 270.0 + 360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the ship
    RotatingThing::draw(target, states);
}