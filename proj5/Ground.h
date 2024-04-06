// This is the ground
#pragma once

#include <Thing.hpp>

class Ground : public vmi::Thing
{
public:
    Ground();
    ~Ground();

    void handleCollision(const vmi::Thing* other);
};