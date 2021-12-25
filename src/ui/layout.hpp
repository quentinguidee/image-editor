#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <functional>
#include <vector>

#include "has_background.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "view.hpp"

class Layout : public View, public HasBackground
{
private:
    Views views;

public:
    Layout();
    ~Layout() {}

    Views getSubviews() override;

    void addView(std::shared_ptr<View> view);
};

#endif /* LAYOUT_HPP */
