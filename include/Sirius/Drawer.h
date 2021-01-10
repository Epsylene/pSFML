
#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Utilities/Vector.h"

namespace srs
{
    class Drawer
    {
        private:

            Vector computePos(float x, float y);
            Vector computePos(Vector& pos);

        public:

            Window simWindow;

            Drawer(unsigned int simWindowWidth, unsigned int simWindowHeight, const char* simWindowTitle);
            virtual ~Drawer();

            void drawRectangle(float posX, float posY, float width, float height);
            void drawRectangle(Vector& pos, float width, float height);
            void drawSquare(float posX, float posY, float side);
            void drawSquare(Vector& pos, float side);
            void drawCircle(float posX, float posY, float radius);
            void drawCircle(Vector& pos, float radius);
    };
}
