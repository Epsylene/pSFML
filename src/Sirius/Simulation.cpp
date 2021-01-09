
#include "Sirius/Simulation.h"

namespace srs
{
    Simulation::Simulation(unsigned int width, unsigned int heigth,
                           const char* title): simWindow(width, heigth, title)
    {

    }

    Simulation::~Simulation()
    {

    }

    void Simulation::run()
    {
        while (simWindow.isOpen())
        {
            //------- Update -------

            while (simWindow.pollEvent())
            {
                simWindow.eventClosed(); //Checks whether a "close window"
                                         // event has been triggered
            }

            update();

            //------- Render -------

            simWindow.clear();

            render();

            simWindow.display();
        }
    }
}
