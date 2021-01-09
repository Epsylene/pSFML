
#pragma once

#include "Sirius/Window.h"

namespace srs
{
    class Simulation
    {
        private:

            virtual void update() = 0;
            virtual void render() = 0;

            Window simWindow;

        public:

            Simulation() = default;
            Simulation(unsigned int width, unsigned int heigth, const char* title);
            ~Simulation();

            void run();
    };

    Simulation* createSimulation();
}
