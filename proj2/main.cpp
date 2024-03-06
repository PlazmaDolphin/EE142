#include "Graphics.h"
 
#include "Ball.h"
#include "Vector2d.h"
#include "TopWall.h"
#include "BottomWall.h"
#include "LeftWall.h"
#include "RightWall.h"
 
int main()
{
    // create a new window to display the game
    sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncy bouncy!");
 
    // get a clock we can use to measure elapsed time 
    sf::Clock clock;

    // Create the ball
    Ball ball;
     
    // Create the walls
    TopWall topWall;
    BottomWall bottomWall;
    LeftWall leftWall;
    RightWall rightWall;

    // Repeat until the window is closed
    while (window.isOpen())
    {
       // handle any pending events
       sf::Event event;
       while (window.pollEvent(event))
       {
          if (event.type == sf::Event::Closed)
               window.close();
       }

       // get elapsed time
       double dt = clock.restart().asSeconds();
       dt = (dt > 0.04) ? 0.04 : dt;  // make sure dt is a sane value

       // move everything
       ball.move(dt);

       // erase everything in the window
       window.clear();

       // draw everything in new locations
       ball.draw(window);
       topWall.draw(window);
       bottomWall.draw(window);
       leftWall.draw(window);
       rightWall.draw(window);

       // display the updated window
       window.display();
    }

    return 0;
} 