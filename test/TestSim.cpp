
#include "Sirius.h"

class TestSim: public srs::Simulation
{
    public:

        TestSim(unsigned int width, unsigned int heigth, const char* title)
                : Simulation(width, heigth, title)
        {}

        void update()
        {
            //
        }

        void render()
        {
            d.drawRectangle(300, 200, 150, 100);
        }
};

srs::Simulation* srs::createSimulation()
{
    return new TestSim(1024, 576, "Title");
}
