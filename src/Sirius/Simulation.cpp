
#include "Sirius/Simulation.h"

namespace srs
{
    Simulation::Simulation(unsigned int width, unsigned int heigth,
                           const char* title): d(width, heigth, title)
    {
    }

    Simulation::~Simulation()
    {

    }

    void Simulation::run()
    {
        while (d.simWindow.isOpen())
        {
            //------- Update -------

            while (d.simWindow.pollEvent())
            {
                d.simWindow.eventClosed(); //Checks whether a "close window"
                                         // event has been triggered
            }

            update();

            //------- Render -------

            d.simWindow.clear(sf::Color::White);

            render();

            d.simWindow.display();
        }
    }
}
