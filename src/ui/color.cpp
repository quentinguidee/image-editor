#include "color.hpp"

#include <cstdlib>
#include <iostream>

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
    r(r), g(g), b(b), a(a)
{
}

SDL_Color Color::toSDL() const
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
    if (SDL_SetRenderDrawColor(renderer, r, g, b, a))
        std::cerr << SDL_GetError() << std::endl;
}

Color Color::gray(uint8_t intensity)
{
    return Color(intensity, intensity, intensity);
}

const Color Color::BLACK = Color::gray(0);
const Color Color::WHITE = Color::gray(255);

const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);

const Color Color::BACKGROUND = Color(18, 19, 21);
const Color Color::BACKGROUND_DARK = Color(10, 10, 11);
const Color Color::BACKGROUND_DARKER = Color(7, 8, 8);
