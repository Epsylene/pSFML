
#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Utilities/Vector.h"

namespace psf
{
    class Drawer
    {
        private:

            ////////////////////////////////////////////////////////////////////////
            /// @brief Transforms the user coordinates in window coordinates
            ///
            /// User coordinates place the origin at the center of the
            /// window and have normal (x, y) Y orientation; window coordinates
            /// place the origin at the upper-left corner and have inverse 
            /// (x, -y) Y orientation.
            /// 
            /// @param x The X user coordinate
            /// @param y The Y user coordinate
            /// @return The (x, y) window position
            Vector computePos(float x, float y);

            ///////////////////////////////////////////////////////////////////////
            /// @brief Transforms the user coordinates in window coordinates
            ///
            /// User coordinates place the origin at the center of the
            /// window and have normal (x, y) Y orientation; window coordinates
            /// place the origin at the upper-left corner and have inverse 
            /// (x, -y) Y orientation.
            /// 
            /// @param pos The position in user coordinates
            /// @return The (x, y) window position
            Vector computePos(Vector& pos);

        public:

            Window simWindow;

            ///////////////////////////////////////////////////
            /// @brief Drawer constructor
            /// 
            /// @param simWindowWidth Simulation window width
            /// @param simWindowHeight Simulation window height
            /// @param simWindowTitle Simulation window title
            /// @param color Rectangle color
            Drawer(unsigned int simWindowWidth, unsigned int simWindowHeight, const char* simWindowTitle);
            virtual ~Drawer();

            ////////////////////////////////////////////////////////////////////
            /// @brief Rectangle draw function
            /// @details Rectangles are drawn from the low-left corner. Negative
            ///     width and height are allowed.
            /// 
            /// @param posX X position of the upper-right corner
            /// @param posY Y position of the upper-right corner
            /// @param width Rectangle width
            /// @param height Rectangle height
            /// @param color Rectangle color
            void drawRectangle(float posX, float posY, float width, float height, const sf::Color& color = sf::Color::Black);

            ////////////////////////////////////////////////////////////////////
            /// @brief Rectangle draw function
            /// @details Rectangles are drawn from the low-left corner. Negative
            ///     width and height are allowed.
            /// 
            /// @param pos Position of the upper-right corner 
            /// @param width Rectangle width
            /// @param height Rectangle height
            /// @param color Rectangle color
            void drawRectangle(Vector& pos, float width, float height, const sf::Color& color = sf::Color::Black);

            ////////////////////////////////////////////////////
            /// @brief Square draw function
            /// 
            /// @param posX X position of the upper-right corner
            /// @param posY Y position of the upper-right corner
            /// @param side Size of the square's side
            /// @param color Square color
            void drawSquare(float posX, float posY, float side, const sf::Color& color = sf::Color::Black);

            /////////////////////////////////////////////////
            /// @brief Square draw function
            /// 
            /// @param pos Position of the upper-right corner
            /// @param side Size of the square's side
            /// @param color Square color
            void drawSquare(Vector& pos, float side, const sf::Color& color = sf::Color::Black);

            ///////////////////////////////////////////////
            /// @brief Circle draw function
            /// 
            /// @param posX X position of the circle center
            /// @param posY Y position of the circle center
            /// @param radius Circle radius
            /// @param color Circle color
            void drawCircle(float posX, float posY, float radius, const sf::Color& color = sf::Color::Black);

            ////////////////////////////////////////////
            /// @brief Circle draw function
            /// 
            /// @param pos Position of the circle center
            /// @param radius Circle radius
            /// @param color Circle color
            void drawCircle(Vector& pos, float radius, const sf::Color& color = sf::Color::Black);
    };
}
