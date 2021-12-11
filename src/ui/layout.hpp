#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <functional>
#include <vector>

#include "has_background.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "view.hpp"

using std::reference_wrapper;
using std::vector;

class Layout : public View, public HasBackground
{
private:
    vector<reference_wrapper<const View>> views;

public:
    Layout();
    ~Layout() {}

    void addView(const View &view);

    const vector<reference_wrapper<const View>> &getViews() const;
};

#endif /* LAYOUT_HPP */
