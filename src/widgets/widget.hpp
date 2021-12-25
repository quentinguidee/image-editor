#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <string>

#include "../ui/text.hpp"
#include "../ui/vertical_layout.hpp"

using std::string;

class Widget : public VerticalLayout
{
private:
    string title;

    std::shared_ptr<Text> titleText;

public:
    Widget(const string& title);
    ~Widget() {}
};

#endif /* WIDGET_HPP */
