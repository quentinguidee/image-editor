#include "position.hpp"

#include <limits>

Position1D::Position1D(float x) :
    x(x)
{
}

bool Position1D::isZero() const
{
    return x == 0;
}

bool Position1D::isInfinite() const
{
    return x == std::numeric_limits<float>::max();
}

bool Position1D::isUndefined() const
{
    return x == std::numeric_limits<float>::max() - 1;
}

Position1D& Position1D::operator+=(const Position1D& rhs)
{
    x += rhs.x;
    return *this;
}

bool Position1D::operator>(const Position1D& rhs) const
{
    return x > rhs.x;
}

bool Position1D::operator<(const Position1D& rhs) const
{
    return x < rhs.x;
}

bool Position1D::operator>=(const Position1D& rhs) const
{
    return x >= rhs.x;
}

bool Position1D::operator<=(const Position1D& rhs) const
{
    return x <= rhs.x;
}

Position1D operator+(Position1D lhs, const Position1D& rhs)
{
    lhs.x += rhs.x;
    return lhs;
}

const Position1D Position1D::ZERO = Position1D(0);
const Position1D Position1D::INFINITE = Position1D(std::numeric_limits<float>::max());
const Position1D Position1D::UNDEFINED = Position1D(std::numeric_limits<float>::max() - 1);

Position::Position(float x, float y) :
    x(Position1D(x)), y(Position1D(y))
{
}

bool Position::isZero() const
{
    return x.isZero() && y.isZero();
}

bool Position::isInfinite() const
{
    return x.isInfinite() && y.isInfinite();
}

bool Position::isUndefined() const
{
    return x.isUndefined() && y.isUndefined();
}

const Position1D& Position::operator[](uint8_t i) const
{
    return i == 0 ? x : y;
}

Position& Position::operator+=(const Position& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Position operator+(Position lhs, const Position& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

const Position Position::ZERO = Position(0, 0);
const Position Position::INFINITE = Position(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
const Position Position::UNDEFINED = Position(std::numeric_limits<float>::max() - 1, std::numeric_limits<float>::max() - 1);
