#ifndef WIDGETS_PANEL_HPP
#define WIDGETS_PANEL_HPP

#include "../ui/vertical_layout.hpp"
#include "../widgets/transform_widget.hpp"

class WidgetsPanel : public VerticalLayout
{
private:
    TransformWidget transformWidget;

public:
    WidgetsPanel();
    ~WidgetsPanel() {}
};

#endif /* WIDGETS_PANEL_HPP */
