#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <vector>

#include "../ui/color.hpp"

using std::vector;

class Image
{
private:
    vector<Color> pixels;
    uint16_t width, height;

public:
    Image(uint16_t width, uint16_t height);
    ~Image() {}

    const Color& getPixel(uint16_t x, uint16_t y) const;
    const vector<Color>& getPixels() const;
    const int pixelsCount() const;
    const uint16_t getWidth() const;
    const uint16_t getHeight() const;
};

#endif /* IMAGE_HPP */
