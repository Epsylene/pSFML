
#pragma once

#include "pSFML/Drawer.h"

namespace psf
{
    class Simulation
    {
        private:

            virtual void update() = 0;
            virtual void render() = 0;

        protected:

            Drawer drawer;

        public:

            //////////////////////////////////////////////
            /// @brief Simulation constructor
            /// 
            /// @param width The simulation window width
            /// @param heigth The simulation window height
            /// @param title The simulation window title
            Simulation(unsigned int width, unsigned int heigth, const char* title);
            virtual ~Simulation();

            ///////////////////////////////
            /// @brief Main simulation loop
            void run();
    };

    Simulation* createSimulation();
}
