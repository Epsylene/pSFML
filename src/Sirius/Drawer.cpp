
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
        sf::RectangleShape r {{width, -height}};
        Vector realPos = computePos(posX, posY);
        r.setPosition(realPos.x, realPos.y);
        r.setFillColor(sf::Color::Black);
        simWindow.draw(r);
    }

    void Drawer::drawRectangle(Vector& pos, float width, float height)
    {
        drawRectangle(pos.x, pos.y, width, height);
    }

    void Drawer::drawSquare(float posX, float posY, float side)
    {
        drawRectangle(posX, posY, side, side);
    }

    void Drawer::drawSquare(Vector& pos, float side)
    {
        drawSquare(pos.x, pos.y, side);
    }

    void Drawer::drawCircle(float posX, float posY, float radius)
    {
        sf::CircleShape c {radius};
        Vector realPos = computePos(posX, posY);
        c.setPosition(realPos.x, realPos.y);
        c.setFillColor(sf::Color::Black);
        simWindow.draw(c);
    }

    void Drawer::drawCircle(Vector& pos, float radius)
    {
        drawCircle(pos.x, pos.y, radius);
    }

    Vector Drawer::computePos(float x, float y)
    {
        return Vector(x + simWindow.getWidth() / 2,
                      -y + simWindow.getHeight() / 2);
    }

    Vector Drawer::computePos(Vector& pos)
    {
        return computePos(pos.x, pos.y);
    }
}
