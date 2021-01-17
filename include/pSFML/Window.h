
#pragma once

#include "SFML/Graphics.hpp"

namespace psf
{
    class Window
    {
        private:

            sf::RenderWindow window;
            sf::Event event {};

        public:

            Window() = default;
            Window(unsigned int width, unsigned int heigth, const char* title):
                window({width, heigth}, title), event() {}

            void create(unsigned int width, unsigned int heigth, const char* title);
            float getWidth();
            float getHeight();

            bool isOpen();
            bool pollEvent();
            bool eventClosed();

            void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));
            void display();
            void draw(sf::Drawable& shape);
    };
}