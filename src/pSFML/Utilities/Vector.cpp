
#include "pSFML/Utilities/Vector.h"

namespace psf
{
    Vector::Vector()
    {
        this->x = 0.f;
        this->y = 0.f;

        mag = 0.f;
        angle = 0.f;
    }

    Vector::Vector(float x, float y)
    {
        this->x = x;
        this->y = y;

        mag = static_cast<float>(std::sqrt(x * x + y * y));
        angle = static_cast<float>(std::atan2(y, x));
    }

    Vector::Vector(Vector& vec)
    {
        x = vec.x;
        y = vec.y;

        mag = static_cast<float>(std::sqrt(x * x + y * y));
        angle = static_cast<float>(std::atan2(y, x));
    }

    Vector::Vector(sf::Vector2f vec)
    {
        x = vec.x;
        y = vec.y;

        mag = static_cast<float>(std::sqrt(x * x + y * y));
        angle = static_cast<float>(std::atan2(y, x));
    }

    void Vector::setMag(float m)
    {
        this->mag = m;
        this->angle = std::atan2(y, x);

        x = mag * std::cos(angle);
        y = mag * std::sin(angle);
    }

    void Vector::setAngle(float alpha)
    {
        this->angle = alpha;

        x = mag * std::cos(angle);
        y = mag * std::sin(angle);
    }

    void Vector::normalize()
    {
        mag = 1;

        x = std::cos(angle);
        y = std::sin(angle);
    }

    void Vector::normalize(Vector& vec)
    {
        vec.mag = 1;

        vec.x = std::cos(vec.angle);
        vec.y = std::sin(vec.angle);
    }

    float Vector::getMag() const
    {
        return static_cast<float>(std::sqrt(x * x + y * y));
    }

    float Vector::getMag(Vector& vec)
    {
        return static_cast<float>(std::sqrt(vec.x * vec.x + vec.y * vec.y));
    }

    float Vector::getAngle() const
    {
        return std::atan2(y, x);;
    }

    float Vector::getAngle(Vector& vec)
    {
        return std::atan2(vec.y, vec.x);
    }

    float Vector::dot(Vector& v2)
    {
        return x * v2.x + y * v2.y;
    }

    float Vector::dot(Vector& v1, Vector& v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    // ---------- OPERATOR OVERLOADS ---------- //
    
    Vector& Vector::operator=(const Vector& rhs)
    {
        if(*this != rhs)
        {
            x = rhs.x;
            y = rhs.y;
            mag = rhs.mag;
            angle = rhs.angle;
        }

        return *this;
    }

    Vector& Vector::operator=(Vector&& rhs)
    {
        if(*this != rhs)
        {
            x = rhs.x;
            y = rhs.y;
            mag = rhs.mag;
            angle = rhs.angle;
        }

        return *this;
    }

    Vector& Vector::operator-=(const Vector& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;

        mag = static_cast<float>(std::sqrt(x * x + y * y));
        angle = static_cast<float>(std::atan2(y, x));

        return *this;
    }

    Vector& Vector::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;

        mag = static_cast<float>(std::sqrt(x * x + y * y));
        angle = static_cast<float>(std::atan2(y, x));

        return *this;
    }
}