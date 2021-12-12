#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "has_background.hpp"
#include "view.hpp"

class Button : public View, public HasBackground
{
private:
public:
    Button();
    ~Button() {}
};

#endif /* BUTTON_HPP */
