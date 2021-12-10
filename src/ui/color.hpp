#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL.h>

#include <cstdint>

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
};

static const Color BLACK = Color::gray(0);
static const Color WHITE = Color::gray(255);

static const Color RED = Color(255, 0, 0);
static const Color GREEN = Color(0, 255, 0);
static const Color BLUE = Color(0, 0, 255);

static const Color BACKGROUND = Color(18, 19, 21);
static const Color BACKGROUND_DARK = Color(10, 10, 11);
static const Color BACKGROUND_DARKER = Color(7, 8, 8);

#endif /* COLOR_HPP */
