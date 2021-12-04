#include "resizable.hpp"

Resizable::Resizable(uint16_t width, uint16_t height) :
    size({width, height})
{
}

uint16_t Resizable::getWidth() const
{
    return size.width;
}

uint16_t Resizable::getHeight() const
{
    return size.height;
}

Size Resizable::getSize() const
{
    return size;
}

void Resizable::setWidth(uint16_t value)
{
    size.width = value;
}

void Resizable::setHeight(uint16_t value)
{
    size.height = value;
}

void Resizable::setSize(uint16_t width, uint16_t height)
{
    setWidth(width);
    setHeight(height);
}
