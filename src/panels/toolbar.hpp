#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include "../ui/horizontal_layout.hpp"
#include "../ui/text.hpp"

class Toolbar : public HorizontalLayout
{
private:
    Text logo;

public:
    Toolbar();
    ~Toolbar() {}
};

#endif /* TOOLBAR_HPP */
