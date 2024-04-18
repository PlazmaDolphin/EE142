// This is the bird, our main character
#include <sstream>

#include <Graphics.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include <Keyboard.hpp>
#include <Game.hpp>
#include <Text.hpp>
#include <Color.hpp>
#include <BoundingBox.hpp>

#include "Bird.h"
#include "Ground.h"
#include "Pipe.h"
#include "Goal.h"
#include "Sky.h"
using namespace vmi;

// Create our bird in the center of the window. Acceleration is due
// to gravity. Use a sprite for the shape
Bird::Bird() : MovingThing(
                    Vector2d(375, 275),     // initial position near center
                    Vector2d(),             // no velocity
                    Vector2d(0, 980),       // acceleration from gravity
                    new SpriteShape("proj5/bird.png")     // image for sprite
                ),
                score(0)
{
    // set the center of the bird (image is 51x36, so half that)
    center = Vector2d(25, 18);

    // set up the text display of the score
    scoreText.setText("0");
    scoreText.setCharacterSize(60);
    scoreText.setPosition(Vector2d(50, 25));
    scoreText.setFill(Color::White);
}

// Delete the bird's shape
Bird::~Bird()
{
    delete shape;
}

// Handle collisions with other things
void Bird::handleCollision(const Thing* other)
{
    // if we hit the ground or the pipe, then we're done for
    if ((typeid(*other) == typeid(Ground))
        || (typeid(*other) == typeid(Pipe))
        || (typeid(*other) == typeid(Sky)))
    {
        // see if we really hit it. The bird is mostly a circle
        // with a radius = ~20, so see if center of bird is inside
        // the other bounding box, plus an extra 20 pixels
        BoundingBox otherBox = other->getBounds();

        // extend by 40 pixels (20 per side)
        otherBox += otherBox.getUl() + Vector2d(-20, -20);
        otherBox += otherBox.getLr() + Vector2d(20, 20);

        if (otherBox.contains(x + center)) {
            die();
        }
    }

    // if we hit a goal, then score a point
    else if (typeid(*other) == typeid(Goal)) {
        scorePoint();
    }
}

// Move the bird. If the spacebar is pressed, the bird moves
// upward with a constant velocity. Otherwise, use the default
// move() function to apply gravity.
void Bird::move(double dt)
{
    if (Game::isKeyPressed(Key::Space)) {
        // constant velocity upwards
        v.setY(-200);
    }

    // rotate based on speed (trial-and-error to figure out how
    // fast to rotate)
    w = v.getY() / 3.0;

    // now move him
    MovingThing::move(dt);

    // don't rotate too much (trial-and-error to figure out max angle)
    angle = (angle < -15) ? -15
            : (angle > 15) ? 15
            : angle;
}

// Draw the bird. We override this function to also display the score
void Bird::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the bird
    Thing::draw(target, states);

    // draw the score
    scoreText.draw(target, states);
}

// Score a point and update the display
void Bird::scorePoint()
{
    score++;

    // update the display, too
    std::stringstream ss;
    ss << score;
    scoreText.setText(ss.str());
}

// Getter function
int Bird::getScore() const
{
    return score;
}