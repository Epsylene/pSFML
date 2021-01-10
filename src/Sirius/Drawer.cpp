
#include "Sirius/Drawer.h"

namespace srs
{
    Drawer::Drawer(unsigned int simWindowWidth, unsigned int simWindowHeight,
                   const char* simWindowTitle): simWindow(simWindowWidth, simWindowHeight, simWindowTitle)
    {}

    Drawer::~Drawer()
    {}

    void Drawer::drawRectangle(float posX, float posY, float width, float height)
    {
        sf::RectangleShape r {{width, height}};
        r.setPosition(posX, posY);
        r.setFillColor(sf::Color::Black);
        simWindow.draw(r);
    }

    void Drawer::drawSquare(float posX, float posY, float side)
    {
        drawRectangle(posX, posY, side, side);
    }

    void Drawer::drawCircle(float posX, float posY, float radius)
    {
        sf::CircleShape c {radius};
        c.setPosition(posX, posY);
        c.setFillColor(sf::Color::Black);
        simWindow.draw(c);
    }

    void Drawer::centeredPos(float posX, float posY)
    {

    }
}
