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
    for(Enemy* bad: badGuys){//remove from list if dead
        if(!bad->isAlive()){
            badGuys.erase(std::find(badGuys.begin(), badGuys.end(), bad));
        }
    }
    if(badGuys.size() == 0){//if there are no more bad guys, make new ones
        player->warp();
        if(player->animDone()){
            stage++;
            player->updateStage(stage);
            player->reset();
            Enemy::maxSwarm = stage;
            genStage();
        }
    }

    if (!player->isAlive()) {
        Key response;

        // display message to user
        do {
            response = Game::createMessage("Play again (Y/N)?",
                            Vector2d(50, 200), 50, Color::Yellow
            );
        } while (response != Key::Y && response != Key::N);

        // do we play again?
        if (response == Key::Y) {
            Shot::score = 0;
            // first, cancel all active timers
            Timer::cancelAllTimers();
            for(Enemy* guy : badGuys){
                guy->goToCenter(dt);
            }

            // next, kill all game characters so we can re-start
            Thing::killAllThings();

            // finally, restart the level
            startLevel();
        }

        else {
            // don't play again
            done = true;
        }
    }
}
bool Gyruss::isOver()const{return done;}
void Gyruss::startLevel(){
    player = new Player();
    stage = 1;
    genStage();
}
//Generate the stage
void Gyruss::genStage(){
    for(int i=0; i<600; i+=(600.0/(2+stage*2))){
        badGuys.push_back(new Enemy(Vector2d(i, 0)));
    }
}