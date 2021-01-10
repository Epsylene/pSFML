
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
            drawer.drawRectangle(5, 5, 100, 100);
            drawer.drawRectangle(5, -5, 100, -100);
            drawer.drawRectangle(-5, 5, -100, 100);
            drawer.drawRectangle(-5, -5, -100, -100);
        }
};

srs::Simulation* srs::createSimulation()
{
    return new TestSim(1024, 576, "Title");
}
