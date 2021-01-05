
#include "Sirius.h"

class Drawer: public srs::Simulation
{
    public:

        Drawer() {}
        ~Drawer() {}

        void update() override
        {
            //
        }

        void render() override
        {
            //
        }
};

srs::Simulation* srs::createSimulation()
{
    return new Drawer();
}
