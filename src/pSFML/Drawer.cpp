
#include "pSFML/Drawer.h"

namespace psf
{
    Drawer::Drawer(unsigned int simWindowWidth, unsigned int simWindowHeight,
                   const char* simWindowTitle): simWindow(simWindowWidth, simWindowHeight, simWindowTitle)
    {}

    Drawer::~Drawer()
    {}

    void Drawer::drawRectangle(float posX, float posY, float width, float height, const sf::Color& color)
    {
        sf::RectangleShape r {{width, -height}};
        Vector realPos = computePos(posX, posY);
        r.setPosition(realPos.x, realPos.y);
        r.setFillColor(color);
        simWindow.draw(r);
    }

    void Drawer::drawRectangle(Vector& pos, float width, float height, const sf::Color& color)
    {
        drawRectangle(pos.x, pos.y, width, height);
    }

    void Drawer::drawSquare(float posX, float posY, float side, const sf::Color& color)
    {
        drawRectangle(posX, posY, side, side);
    }

    void Drawer::drawSquare(Vector& pos, float side, const sf::Color& color)
    {
        drawSquare(pos.x, pos.y, side);
    }

    void Drawer::drawCircle(float posX, float posY, float radius, const sf::Color& color)
    {
        sf::CircleShape c {radius};
        Vector realPos = computePos(posX, posY);
        c.setOrigin(radius, radius);
        c.setPosition(realPos.x, realPos.y);
        c.setFillColor(color);
        simWindow.draw(c);
    }

    void Drawer::drawCircle(Vector& pos, float radius, const sf::Color& color)
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
