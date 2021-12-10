#include "widgets_panel.hpp"

#include "../ui/color.hpp"
#include "../widgets/transform_widget.hpp"

WidgetsPanel::WidgetsPanel() :
    transformWidget(TransformWidget())
{
    addView(transformWidget);

    setFillColor(BACKGROUND_DARKER);
}
