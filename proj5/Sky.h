// The sky -- we just use this as a border the bird might run into

#pragma once

#include <Thing.hpp>
#include <Vector2d.hpp>

class Sky : public vmi::Thing
{
public:
    Sky();
    ~Sky();

    void handleCollision(const vmi::Thing* other);
};