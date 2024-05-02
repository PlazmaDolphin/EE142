#pragma once

#include <Thing.hpp>
#include <Vector2d.hpp>
#include <MovingThing.hpp>

class Particle : public vmi::MovingThing{
    public:
    Particle(double r); //Starfield, Assumes center
    Particle(vmi::Vector2d start, vmi::Vector2d vel); //Enemy dies
    Particle(vmi::Vector2d start, double r); //Player dies
    ~Particle();
    void handleCollision(const vmi::Thing* other){}//ignore collisions

    static void explode(const vmi::MovingThing *thing);
    static void startStarfield();
    static void updateStarfield();

    private:
    static std::vector<Particle*> stars;
};