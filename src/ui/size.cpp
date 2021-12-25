#include "size.hpp"

#include <cstdint>
#include <limits>

Size1D::Size1D(float width) :
    width(width)
{
}

bool Size1D::isZero() const
{
    return width == 0;
}

bool Size1D::isInfinite() const
{
    return width == std::numeric_limits<float>::max();
}

bool Size1D::isUndefined() const
{
    return width == std::numeric_limits<float>::max() - 1;
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
const Size1D Size1D::INFINITE = Size1D(std::numeric_limits<float>::max());
const Size1D Size1D::UNDEFINED = Size1D(std::numeric_limits<float>::max() - 1);

Size::Size(float width, float height) :
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
const Size Size::INFINITE = Size(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
const Size Size::UNDEFINED = Size(std::numeric_limits<float>::max() - 1, std::numeric_limits<float>::max() - 1);
