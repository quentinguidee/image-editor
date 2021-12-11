#include "size.hpp"

#include <cstdint>

Size1D::Size1D(uint16_t width) :
    width(width)
{
}

bool Size1D::isZero() const
{
    return width == 0;
}

bool Size1D::isInfinite() const
{
    return width == UINT16_MAX;
}

bool Size1D::isUndefined() const
{
    return width == UINT16_MAX - 1;
}

void Size1D::ensureIsSmallerThan(const Size1D& maxWidth)
{
    if (width > maxWidth) this->width = maxWidth;
}

Size1D& Size1D::operator+=(const Size1D& rhs)
{
    width += rhs.width;
    return *this;
}

Size1D operator+(Size1D lhs, const Size1D& rhs)
{
    lhs.width += rhs.width;
    return lhs;
}

const Size1D Size1D::ZERO = Size1D(0);
const Size1D Size1D::INFINITE = Size1D(UINT16_MAX);
const Size1D Size1D::UNDEFINED = Size1D(UINT16_MAX - 1);

Size::Size(uint16_t width, uint16_t height) :
    width(Size1D(width)),
    height(Size1D(height))
{
}

bool Size::isZero() const
{
    return width.isZero() && height.isZero();
}

bool Size::isInfinite() const
{
    return width.isInfinite() && height.isInfinite();
}

bool Size::isUndefined() const
{
    return width.isUndefined() && height.isUndefined();
}

void Size::ensureIsSmallerThan(const Size& maxSize)
{
    width.ensureIsSmallerThan(maxSize.width);
    height.ensureIsSmallerThan(maxSize.height);
}

const Size1D& Size::operator[](uint8_t i) const
{
    return i == 0 ? width : height;
}

Size& Size::operator+=(const Size& rhs)
{
    width += rhs.width;
    height += rhs.height;
    return *this;
}

Size operator+(Size lhs, const Size& rhs)
{
    lhs.width += rhs.width;
    lhs.height += rhs.height;
    return lhs;
}

const Size Size::ZERO = Size(0, 0);
const Size Size::INFINITE = Size(UINT16_MAX, UINT16_MAX);
const Size Size::UNDEFINED = Size(UINT16_MAX - 1, UINT16_MAX - 1);
