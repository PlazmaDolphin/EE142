#include <cstdlib>
#include <vector>

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <Color.hpp>
#include <SpriteShape.hpp>
#include <Timer.hpp>

#include "Particle.h"

using namespace vmi;

std::vector<Particle*> Particle::stars;
Particle::Particle(double r)
: MovingThing(Vector2d(300,300), Vector2d(cos(r),sin(r))*100, 
  Vector2d(), new SpriteShape("Gyruss/particle.png"), 100){
    scale = 2;
    Timer::createTimer(5.0, [&]() {
		die();
	});
}

Particle::~Particle(){
    delete shape;
}

void Particle::updateStarfield(){
    if(stars.size()<20){
        stars.push_back(new Particle(rand()/360.0));
    }
    for(Particle* star: stars){
        if(!star->isAlive()){
            stars.erase(std::find(stars.begin(), stars.end(), star));
        }
    }
}

void Particle::startStarfield(){
    Timer::createRepeatingTimer(0.33, updateStarfield);
}