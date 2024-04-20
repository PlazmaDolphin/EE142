#include "RotatingThing.h"

using namespace vmi;
using namespace std;
RotatingThing::RotatingThing(const Vector2d _x, const Vector2d _v, const Vector2d _a, Shape* _shape, const int r, double _z)
: MovingThing(_x, _v, _a, _shape, _z){
    resolution = r;
};
const double RotatingThing::getSizeMultiplier() const{
    double C = resolution/3.0;
    return resolution*(C+(x.getY())) / (C+resolution);
}
const Vector2d RotatingThing::polarPosition() const{
    double S = getSizeMultiplier();
    double X = x.getX();
    Vector2d point((cos((2.0/resolution)*X*2*acos(0.0))*S +resolution)/2, 
                   (sin((2.0/resolution)*X*2*acos(0.0))*S +resolution)/2);
    return point; //HR: acos PI hack from geeksforgeeks.org
}
void RotatingThing::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Vector2d pos = polarPosition(); //position transformed to polar coordinates
    // get center of rotation
    Vector2d cntr = pos + center;

    // scale it, rotate, and translate
    states.transform.scale((float) scale, (float)scale, (float) cntr.getX(), (float) cntr.getY());
    states.transform.rotate((float) angle, (float)cntr.getX(), (float)cntr.getY());
    states.transform.translate((float) pos.getX(), (float) pos.getY());

    // now draw it
	shape->draw(target, states);
}