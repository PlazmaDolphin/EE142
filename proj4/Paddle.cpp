#include <Color.hpp>
#include <PolygonShape.hpp>
#include <Game.hpp>
#include <Text.hpp>
#include <sstream>
#include "Paddle.h"
#include "Wall.h"

using namespace vmi;

Paddle::Paddle(Vector2d pos, Vector2d norm, Key up, Key down)
: n(norm), upKey(up), downKey(down),
MovingThing(pos,Vector2d(),Vector2d(),new PolygonShape()){
    PolygonShape *polygon = dynamic_cast<PolygonShape*>(shape);

    polygon->addPoint(Vector2d(0, 0));
    polygon->addPoint(Vector2d(19, 0));
    polygon->addPoint(Vector2d(19, 79));
    polygon->addPoint(Vector2d(0, 79));
    polygon->setFill(Color::White);

    score = 0;
    // set up the text display of the score
    scoreText.setText("0");
    scoreText.setPosition(Vector2d(x.getX(), 50));
    scoreText.setFill(Color::White);
}

void Paddle::handleCollision(const Thing* other){
    if (typeid(*other) == typeid(Wall)) {
        v = Vector2d(0,0);
        x += 10*dynamic_cast<const Wall*>(other)->getNormal();
    }
}

void Paddle::move(double dt){
    // set velocity based on keyboard controls
    if (Game::isKeyPressed(upKey)) {
            // move upwards
            v.setY(-PADSPEED);
    }

    else if (Game::isKeyPressed(downKey)) {
            // move downwards
            v.setY(PADSPEED);
    }

    else {
            // neither key, so stop
            v.setY(0);
    }

    // now move
    MovingThing::move(dt);
}

void Paddle::scorePoint()
{
       score++;
 
       std::stringstream ss;
       ss << score;
       scoreText.setText(ss.str());
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
       // draw the paddle first
       Thing::draw(target, state);
 
       // now draw the score
       scoreText.draw(target, state);
}
const Vector2d Paddle::getServingPosition() const
{
       // Vector math voodoo -- y-position in center of paddle,
       // x-position in front of paddle
       return (this->x + Vector2d(10, 40)) + 30 * this->n;
}

// Reset the score to 0
void Paddle::resetScore()
{
       score = 0;
       // update the text display, too
       std::stringstream ss;
       ss << score;
       scoreText.setText(ss.str());
}