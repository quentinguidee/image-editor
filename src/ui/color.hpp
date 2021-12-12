#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

#include "SDL.h"

class Color
{
private:
    uint8_t r, g, b, a;

public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    ~Color() {}

    SDL_Color toSDL() const;

    uint8_t getR() const;
    uint8_t getG() const;
    uint8_t getB() const;
    uint8_t getA() const;

    void useAsRenderDrawColor(SDL_Renderer* renderer) const;

    static Color gray(uint8_t intensity);

    static const Color BLACK;
    static const Color WHITE;

    static const Color TRANSPARENT;

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;

    static const Color BACKGROUND;
    static const Color BACKGROUND_DARK;
    static const Color BACKGROUND_DARKER;
};

#endif /* COLOR_HPP */
