#ifndef RESIZABLE_HPP
#define RESIZABLE_HPP

#include <stdint.h>

struct Size
{
    uint16_t width;
    uint16_t height;
};

class Resizable
{
private:
    Size size;

public:
    Resizable(uint16_t width = 0, uint16_t height = 0);
    ~Resizable() {}

    uint16_t getWidth() const;
    uint16_t getHeight() const;
    Size getSize() const;

    void setWidth(uint16_t value);
    void setHeight(uint16_t value);
    void setSize(uint16_t width, uint16_t height);
};

#endif /* RESIZABLE_HPP */
