
#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

class Vector
{
    private:

        float mag, angle;

    public:

        float x, y;

        Vector();
        Vector(float x, float y);
        Vector(Vector& vec);
        Vector(sf::Vector2f vec);

        void setMag(float mag);
        void setAngle(float alpha);
        void normalize();
        static void normalize(Vector& vec);

        float getMag() const;
        static float getMag(Vector& vec);
        float getAngle() const;
        static float getAngle(Vector& vec);

        friend std::ostream& operator<<(std::ostream& out, const Vector& vec);
};
