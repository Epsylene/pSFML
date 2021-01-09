
#include "Sirius.h"

class Drawer: public srs::Simulation
{
    public:

        Drawer(unsigned int width, unsigned int heigth, const char* title)
                : Simulation(width, heigth, title)
        {}

        void update()
        {
            //
        }

        void render()
        {
            //
        }
};

srs::Simulation* srs::createSimulation()
{
    return new Drawer(1024, 576, "Title");
}
