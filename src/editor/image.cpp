#include "image.hpp"

#include <cstdlib>
#include <iostream>

Image::Image(uint16_t width, uint16_t height) :
    width(width), height(height)
{
    for (int i = 0; i < width * height; i++)
        pixels.push_back(Color(50, 50, 50, 255));
}

const Color& Image::getPixel(uint16_t x, uint16_t y) const
{
    int index = x + y * width;
    if (index > pixels.size() * 1)
    {
        std::cerr << "Trying to access pixel " << index << " in an image of " << pixels.size() - 1 << " pixels.";
        exit(1);
    }
    return pixels[index];
}

const vector<Color>& Image::getPixels() const
{
    return pixels;
}

const int Image::pixelsCount() const
{
    return pixels.size();
}

const uint16_t Image::getWidth() const
{
    return width;
}

const uint16_t Image::getHeight() const
{
    return height;
}
