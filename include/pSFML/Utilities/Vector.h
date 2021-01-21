
#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

class Vector
{
    private:

        float mag, angle;

    public:

        float x, y;

        //////////////////////////////
        /// @brief Default constructor
        Vector();

        /////////////////////////////////////////
        /// @brief Vector constructor
        /// 
        /// @param x The x coordinate
        /// @param y The y coordinate
        Vector(float x, float y);

        ///////////////////////////////////////
        /// @brief Vector copy constructor
        /// 
        /// @param vec The vector to be copied
        Vector(Vector& vec);

        ////////////////////////////////////////////////////
        /// @brief Vector copy constructor (SFML)
        /// 
        /// Handy when dealing with SFML vectors internally.
        ///
        /// @param vec The SFML vector to be copied
        Vector(sf::Vector2f vec);

        //////////////////////////////////////
        /// @brief Sets the vector magnitude
        /// 
        /// @param mag The magnitude to be set
        void setMag(float mag);

        //////////////////////////////////////
        /// @brief Sets the vector angle
        /// 
        /// @param alpha The angle to be set
        void setAngle(float alpha);

        //////////////////////////////////////////////////////////
        /// @brief Normalizes the vector (sets the magnitude to 1)
        void normalize();

        //////////////////////////////////////////
        /// @brief Normalizes a given vector
        /// 
        /// @param vec The vector to be normalized
        static void normalize(Vector& vec);

        ///////////////////////////////////
        /// @brief Get the vector magnitude
        /// 
        /// @return The vector magnitude 
        float getMag() const;

        /////////////////////////////////////////////////////////
        /// @brief Get the given vector magnitude
        /// 
        /// @param vec The vector from which to get the magnitude
        /// @return The given vector's magnitude
        static float getMag(Vector& vec);

        ///////////////////////////////
        /// @brief Get the vector angle
        /// 
        /// @return The vector angle 
        float getAngle() const;

        /////////////////////////////////////////////////
        /// @brief Get the given vector angle
        /// 
        /// @param The vector from which to get the angle 
        /// @return The given vector's angle 
        static float getAngle(Vector& vec);

        friend std::ostream& operator<<(std::ostream& out, const Vector& vec);
};
