
#include "pSFML/Window.h"

namespace psf
{
    void Window::create(unsigned int width, unsigned int heigth, const char *title)
    {
        window.create({width, heigth}, title);
    }

    bool Window::isOpen()
    {
        return window.isOpen();
    }

    bool Window::pollEvent()
    {
        return window.pollEvent(event);
    }

    bool Window::eventClosed()
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
            return true;
        }

        return false;
    }

    void Window::clear(const sf::Color& color)
    {
        window.clear(color);
    }

    void Window::display()
    {
        window.display();
    }

    void Window::draw(sf::Drawable& shape)
    {
        window.draw(shape);
    }

    float Window::getWidth()
    {
        return window.getSize().x;
    }

    float Window::getHeight()
    {
        return window.getSize().y;
    }
}
