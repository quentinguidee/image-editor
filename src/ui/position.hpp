#ifndef POSITION_HPP
#define POSITION_HPP

#include <stdint.h>

class Position1D
{
public:
    int16_t x;

    static const Position1D ZERO;
    static const Position1D INFINITE;
    static const Position1D UNDEFINED;

    Position1D(int16_t x);
    ~Position1D() {}

    bool isZero() const;
    bool isInfinite() const;
    bool isUndefined() const;

    Position1D& operator+=(const Position1D& rhs);
    bool operator>(const Position1D& rhs) const;
    bool operator<(const Position1D& rhs) const;
    bool operator>=(const Position1D& rhs) const;
    bool operator<=(const Position1D& rhs) const;
    friend Position1D operator+(Position1D lhs, const Position1D& rhs);

    operator int16_t() const { return x; }
};

class Position
{
public:
    Position1D x;
    Position1D y;

    static const Position ZERO;
    static const Position INFINITE;
    static const Position UNDEFINED;

    Position(int16_t x, int16_t y);
    ~Position() {}

    bool isZero() const;
    bool isInfinite() const;
    bool isUndefined() const;

    const Position1D& operator[](uint8_t i) const;

    Position& operator+=(const Position& rhs);
    friend Position operator+(Position lhs, const Position& rhs);
};

#endif /* POSITION_HPP */
