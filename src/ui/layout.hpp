#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <functional>
#include <vector>

#include "fillable.hpp"
#include "rectangle.hpp"
#include "view.hpp"

using std::reference_wrapper;
using std::vector;

class Layout : public View, public Fillable
{
private:
    vector<reference_wrapper<const View>> views;

public:
    Layout();
    ~Layout() {}

    void addView(const View &view);

    const vector<reference_wrapper<const View>> &getViews() const;

    void drawFill(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const override;
};

#endif /* LAYOUT_HPP */
