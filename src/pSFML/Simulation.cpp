
#include "pSFML/Simulation.h"

namespace psf
{
    Simulation::Simulation(unsigned int width, unsigned int heigth,
                           const char* title): drawer(width, heigth, title)
    {
    }

    Simulation::~Simulation()
    {

    }

    void Simulation::run()
    {
        while (drawer.simWindow.isOpen())
        {
            //------- Update -------

            while (drawer.simWindow.pollEvent())
            {
                drawer.simWindow.eventClosed(); //Checks whether a "close window"
                                         // event has been triggered
            }

            update();

            //------- Render -------

            drawer.simWindow.clear(sf::Color::White);

            render();

            drawer.simWindow.display();
        }
    }
}
