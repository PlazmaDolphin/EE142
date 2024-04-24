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
}
bool Gyruss::isOver()const{return done;}
void Gyruss::startLevel(){
    player = new Player();
    for(int i=0; i<600; i+=75){
        new Enemy(Vector2d(i, 200+i/2));
    }
}