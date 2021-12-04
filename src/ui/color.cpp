#include "color.hpp"

#include <cstdlib>

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
    r(r), g(g), b(b), a(a)
{
}

SDL_Color Color::toSDL()
{
    return {r, g, b, a};
}

uint8_t Color::getR() const
{
    return r;
}

uint8_t Color::getG() const
{
    return g;
}

uint8_t Color::getB() const
{
    return b;
}

uint8_t Color::getA() const
{
    return a;
}

void Color::useAsRenderDrawColor(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

Color Color::gray(uint8_t intensity)
{
    return Color(intensity, intensity, intensity);
}
