
#pragma once

#include "psfpch.h"
#include "SFML/Graphics.hpp"

namespace psf
{
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

            ////////////////////////////////////////////////////
            /// @brief Dot product with another vector
            /// 
            /// @param v2 The vector to do the dot product with
            /// @return The dot product scalar result
            float dot(Vector& v2);

            //////////////////////////////////////////
            /// @brief Dot product between two vectors
            /// 
            /// @param v1 The left operand
            /// @param v2 The right operand
            /// @return The dot product scalar result
            static float dot(Vector& v1, Vector& v2);

            Vector& operator=(Vector rhs);
            Vector& operator+=(const Vector& rhs);
            Vector& operator-=(const Vector& rhs);
            Vector& operator*=(float scalar);
        
            friend bool operator==(const Vector& lhs, const Vector& rhs)
            {
                return (rhs.x == lhs.x) && (rhs.y == lhs.y);
            }

            friend bool operator!=(const Vector& rhs, const Vector& lhs)
            {
                return !(rhs == lhs);
            }

            friend Vector operator+(Vector lhs, const Vector& rhs)
            {
                lhs += rhs;

                lhs.mag = static_cast<float>(std::sqrt(lhs.x * lhs.x + lhs.y * lhs.y));
                lhs.angle = static_cast<float>(std::atan2(lhs.y, lhs.x));

                return lhs;
            }

            friend Vector operator-(const Vector& vec)
            {
                return { -vec.x, -vec.y };
            }

            friend Vector operator-(Vector lhs, Vector& rhs)
            {
                return lhs + (-rhs);
            }

            friend Vector operator*(float scalar, const Vector& vec)
            {
                return { vec.x * scalar, vec.y * scalar };
            }

            friend Vector operator*(const Vector& vec, float scalar)
            {
                return { vec.x * scalar, vec.y * scalar };
            }

            friend std::ostream& operator<<(std::ostream& out, const Vector& vec)
            {
                return out << "(" << vec.x << ", " << vec.y << ")";
            }
    };
}
