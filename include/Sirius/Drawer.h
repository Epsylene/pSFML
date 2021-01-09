
#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"

namespace srs
{
    class Drawer
    {
        public:

            Window simWindow;

            Drawer(unsigned int simWindowWidth, unsigned int simWindowHeight, const char* simWindowTitle);
            virtual ~Drawer();

            void drawRectangle(float posX, float posY, float width, float height);
            void drawSquare(float posX, float posY, float side);
            void drawCircle(float posX, float posY, float radius);
    };
}
