
#include "Sirius/Utilities/Vector.h"

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

    mag = static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
    angle = static_cast<float>(std::atan2(y, x));
}

Vector::Vector(Vector& vec)
{
    x = vec.x;
    y = vec.y;

    mag = static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
    angle = static_cast<float>(std::atan2(y, x));
}

Vector::Vector(sf::Vector2f vec)
{
    x = vec.x;
    y = vec.y;

    mag = static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
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
    return static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
}

float Vector::getMag(Vector& vec)
{
    return static_cast<float>(std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)));
}

float Vector::getAngle() const
{
    return std::atan2(y, x);;
}

float Vector::getAngle(Vector& vec)
{
    return std::atan2(vec.y, vec.x);
}

std::ostream& operator<<(std::ostream& out, const Vector& vec)
{
    return out << "(" << vec.x << ", " << vec.y << ")";
}
