
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

            ////////////////////////////////////
            /// @brief Window constructor
            /// 
            /// @param width The window width
            /// @param heigth The window height
            /// @param title The window title
            Window(unsigned int width, unsigned int heigth, const char* title):
                window({width, heigth}, title), event() {}

            ///////////////////////////////////////////
            /// @brief Creates the window
            /// 
            /// @param width The created window width
            /// @param heigth The created window height
            /// @param title The created window title
            void create(unsigned int width, unsigned int heigth, const char* title);
           
            ///////////////////////////////
            /// @brief Get the window width
            ///
            /// @return The window width
            float getWidth();

            //////////////////////////////////
            /// @brief Get the window height
            ///
            /// @return The window height
            float getHeight();

            /////////////////////////////////////////////////////
            /// @brief Returns whether the windows is open or not
            /// 
            /// @return true or false
            bool isOpen();

            ////////////////////////////////////////////////////////
            /// @brief Poll events for the window
            /// 
            /// @return True if an event was returned, false if not
            bool pollEvent();

            ////////////////////////////////////////////////////////////////////
            /// @brief Closes the window if a window close event was triggered
            /// 
            /// @return True if a window close event was trigerred, false if not  
            bool eventClosed();

            ///////////////////////////
            /// @brief Clear the window
            ///
            /// @param color Clear color
            void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));

            /////////////////////////////////////////
            /// @brief Displays the window
            void display();

            /////////////////////////////////////////
            /// @brief Draw a shape on the window
            /// 
            /// Shapes that can be drawn are sf::Drawable objects, i.e. shapes
            /// provided by SFML.
            ///
            /// @param shape 
            void draw(sf::Drawable& shape);
    };
}