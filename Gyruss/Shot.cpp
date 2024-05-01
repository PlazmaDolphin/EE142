#define RESOLUTION 600.0

#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include "Shot.h"
#include "Enemy.h"

using namespace vmi;
int Shot::score=0;
Shot::Shot(double x)
: RotatingThing(Vector2d(x, RESOLUTION*0.8), Vector2d(0, -900), Vector2d(),
new SpriteShape("Gyruss/player_shot.png"), RESOLUTION, 3.0){
    center = Vector2d(3, 4);
}
Shot::~Shot(){
    delete shape;
}

void Shot::move(double dt){
    angle = 270+360.0*x.getX()/RESOLUTION;
    MovingThing::move(dt);
    if(x.getY() < 0){
        die();
    }
}

void Shot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the ship
    RotatingThing::draw(target, states);
}

void Shot::handleCollision(const vmi::Thing* other){
    if(typeid(*other)==typeid(Enemy)){
        score += 100;
        die(); //Can't kill 2 birds with one stone
    }
}