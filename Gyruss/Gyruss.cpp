#include "Gyruss.h"
#define RESOLUTION 600

using namespace vmi;
Gyruss::Gyruss()
: Game("Gyruss but better v0.1", RESOLUTION, RESOLUTION+200), done(false){
    startLevel();
}
void Gyruss::update(double dt){
    if(Game::isKeyPressed(Key::X)){
        done = true;
    }
}
bool Gyruss::isOver()const{return done;}
void Gyruss::startLevel(){
    player = new Player();
}