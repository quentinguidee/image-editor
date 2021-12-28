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
    std::vector<std::shared_ptr<View>> views;

public:
    Layout();
    ~Layout() {}

    std::vector<std::shared_ptr<View>> getViews() override;
    std::shared_ptr<View> getView(int i);

    template <class V>
    std::shared_ptr<V> getView(int i);

    void addView(std::shared_ptr<View> view);
};

template <class V>
std::shared_ptr<V> Layout::getView(int i)
{
    return std::dynamic_pointer_cast<V>(views[i]);
}

#endif /* LAYOUT_HPP */
