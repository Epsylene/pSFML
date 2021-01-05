
#pragma once

#include <iostream>

namespace srs
{
    class Simulation
    {
        private:

            virtual void update() = 0;
            virtual void render() = 0;

        public:

            Simulation();
            ~Simulation();

            void run();
    };

    Simulation* createSimulation();
}
