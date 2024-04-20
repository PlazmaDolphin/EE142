#include "Vector2d.hpp"
#include "MovingThing.hpp"

#pragma once
class RotatingThing : public vmi::MovingThing{
    public:
    RotatingThing(const vmi::Vector2d _x, const vmi::Vector2d _v, const vmi::Vector2d _a,
    vmi::Shape* _shape, const int r, double _z = 0);
    const double getSizeMultiplier() const;
    //Overridden functions
    const vmi::Vector2d polarPosition() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
    int resolution; //needed for position and size conversion, assumes play area is square
};