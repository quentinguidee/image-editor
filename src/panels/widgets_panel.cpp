#include "widgets_panel.hpp"

#include "../widgets/transform_widget.hpp"

WidgetsPanel::WidgetsPanel() :
    transformWidget(TransformWidget())
{
    addView(transformWidget);
}
