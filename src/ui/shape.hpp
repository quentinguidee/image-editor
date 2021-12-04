#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SDL.h>

#include "fillable.hpp"
#include "view.hpp"

class Shape : public View, public Fillable
{
private:
public:
    Shape() {}
    ~Shape() {}
};

#endif /* SHAPE_HPP */
