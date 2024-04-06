// This is the bird, our main character
#pragma once

#include <Graphics.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Text.hpp>

class Bird : public vmi::MovingThing
{
public:
    Bird();
    ~Bird();

    void handleCollision(const vmi::Thing* other);

    void move(double dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int getScore() const;

private:
    int score;              // how many pipes we've passed
    vmi::Text scoreText;    // display of current score

    void scorePoint();
};