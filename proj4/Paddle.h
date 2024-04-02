#pragma once
#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <Keyboard.hpp>
#include <Text.hpp>

class Paddle: public vmi::MovingThing{
    public:
    Paddle(vmi::Vector2d pos, vmi::Vector2d norm, vmi::Key up, vmi::Key down);
    ~Paddle(){delete shape;}
    //physics
    void handleCollision(const vmi::Thing* other);
    void move(double dt);
    vmi::Vector2d getNormal() const{return n;}
    //score
    int getScore(){return score;}
    void scorePoint();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    const vmi::Vector2d getServingPosition() const;

    private:
    vmi::Vector2d n;
    vmi::Key upKey;
    vmi::Key downKey;
    const double PADSPEED = 400.0;
    int score;
    vmi::Text scoreText;
};