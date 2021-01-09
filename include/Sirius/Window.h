
#pragma once

#include "SFML/Graphics.hpp"

namespace srs
{
    class Window
    {
        private:

            sf::RenderWindow window;
            sf::Event event;

        public:

            Window() = default;

            Window(unsigned int width, unsigned int heigth, const char* title):
                window({width, heigth}, title), event() {}

            void create(unsigned int width, unsigned int heigth, const char* title);

            bool isOpen();
            bool pollEvent();
            bool eventClosed();

            void clear();
            void display();
    };
}