#include <Thing.hpp>
#include "Paddle.h"

class Goal : public vmi::Thing{
    public:
    Goal(const vmi::Vector2d& ul, const vmi::Vector2d& lr, Paddle* owner);
    ~Goal();
    Paddle* getPlayer() const{return pad;}
    void handleCollision(const Thing* other);
    
    private:
    Paddle* pad;
};