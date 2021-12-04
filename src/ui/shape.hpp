#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SDL.h>

#include "fillable.hpp"
#include "resizable.hpp"
#include "view.hpp"

class Shape : public View, public Fillable, public Resizable
{
private:
public:
    Shape() {}
    ~Shape() {}
};

#endif /* SHAPE_HPP */
