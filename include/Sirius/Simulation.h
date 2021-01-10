
#pragma once

#include "Sirius/Drawer.h"

namespace srs
{
    class Simulation
    {
        private:

            virtual void update() = 0;
            virtual void render() = 0;

        protected:

            Drawer drawer;

        public:

            Simulation(unsigned int width, unsigned int heigth, const char* title);
            virtual ~Simulation();

            void run();
    };

    Simulation* createSimulation();
}
