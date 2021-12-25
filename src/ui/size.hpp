#ifndef SIZE_HPP
#define SIZE_HPP

#include <stdint.h>

class Size1D
{
public:
    float width;

    static const Size1D ZERO;
    static const Size1D INFINITE;
    static const Size1D UNDEFINED;

    Size1D(float width);
    ~Size1D() {}

    bool isZero() const;
    bool isInfinite() const;
    bool isUndefined() const;

    void ensureIsSmallerThan(const Size1D& maxWidth);

    Size1D& operator+=(const Size1D& rhs);
    friend Size1D operator+(Size1D lhs, const Size1D& rhs);

    operator float() const { return width; }
};

class Size
{
public:
    Size1D width;
    Size1D height;

    static const Size ZERO;
    static const Size INFINITE;
    static const Size UNDEFINED;

    Size(float width, float height);
    ~Size() {}

    bool isZero() const;
    bool isInfinite() const;
    bool isUndefined() const;

    void ensureIsSmallerThan(const Size& maxSize);

    const Size1D& operator[](uint8_t i) const;

    Size& operator+=(const Size& rhs);
    friend Size operator+(Size lhs, const Size& rhs);
};

#endif /* SIZE_HPP */
