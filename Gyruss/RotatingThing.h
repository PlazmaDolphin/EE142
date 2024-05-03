#pragma once
#include <Vector2d.hpp>
#include <MovingThing.hpp>
#include <BoundingBox.hpp>
#include <Thing.hpp>
class RotatingThing : public vmi::MovingThing{
    public:
    RotatingThing(const vmi::Vector2d _x, const vmi::Vector2d _v, const vmi::Vector2d _a,
    vmi::Shape* _shape, const int r, double fullSize=1.0, double _z = 0.0);
    const double getScaleFactor() const;
    const double getSizeMultiplier() const;
    //Overridden functions
    const vmi::Vector2d polarPosition() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool actuallyTouching(const RotatingThing* other) const;
    double getAngle() const;
    const vmi::BoundingBox getBounds() const;
    private:
    int resolution; //needed for position and size conversion, assumes play area is square
    double fullSize; //default scaling factor to blow up sprites
};