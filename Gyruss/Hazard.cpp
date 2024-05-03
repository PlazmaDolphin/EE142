#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include "Hazard.h"
#include "Player.h"

using namespace vmi;

Hazard::Hazard(Vector2d _x)
: RotatingThing(_x, Vector2d(0, 200), Vector2d(),
new SpriteShape("Gyruss/enemy_shot.png"), RESOLUTION, 2.0){
    center = Vector2d(3, 4);
}
Hazard::~Hazard(){
    delete shape;
}

void Hazard::move(double dt){
    //move away from center, despawn when outside screen
    angle = 270+360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
    if(x.getY() > RESOLUTION){
        die();
    }
}

void Hazard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the ship
    RotatingThing::draw(target, states);
}

void Hazard::handleCollision(const vmi::Thing* other){
    if(typeid(*other)==typeid(Player)){
        std::cout<<"YOU DEAD";
        die(); //Can't kill 2 birds with one stone
    }
}