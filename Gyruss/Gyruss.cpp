#include "Gyruss.h"
#define RESOLUTION 600

using namespace vmi;
Gyruss::Gyruss()
: Game("Gyruss but better v0.1", RESOLUTION, RESOLUTION), done(false){
    startLevel();
}
void Gyruss::update(double dt){
    if(Game::isKeyPressed(Key::X)){
        done = true;
    }
    for(Enemy* bad: badGuys){//remove from list if dead
        if(!bad->isAlive()){
            badGuys.erase(std::find(badGuys.begin(), badGuys.end(), bad));
        }
    }
    if(badGuys.size() == 0){//if there are no more bad guys, make new ones
        for(int i=0; i<600; i+=75){
            badGuys.push_back(new Enemy(Vector2d(i, 0)));
        }
    }
}
bool Gyruss::isOver()const{return done;}
void Gyruss::startLevel(){
    player = new Player();
    for(int i=0; i<600; i+=75){
        badGuys.push_back(new Enemy(Vector2d(i, 0)));
    }
}