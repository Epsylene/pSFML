
#include "Sirius/Window.h"

namespace srs
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

    void Window::clear()
    {
        window.clear();
    }

    void Window::display()
    {
        window.display();
    }
}
