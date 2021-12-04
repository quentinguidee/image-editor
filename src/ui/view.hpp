#ifndef VIEW_HPP
#define VIEW_HPP

#include <SDL.h>
#include <unistd.h>

struct Position
{
    int16_t x;
    int16_t y;
};

class View
{
private:
    Position position;

public:
    View();
    ~View() {}

    virtual void draw(SDL_Renderer *renderer) const = 0;

    int16_t getX() const;
    int16_t getY() const;
    Position getPosition() const;

    void setX(int16_t x);
    void setY(int16_t y);
    void setPosition(int16_t x, int16_t y);
};

#endif /* VIEW_HPP */
