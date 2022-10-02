#include "ConsoleLogViewTab.h"

#include <iostream>

#include "ConsoleHelper.h"

void ConsoleLogViewTab::update(const ViewMessage& message) const {
    ConsoleHelper::setCursorPosition(_x_margin, _y_margin);
    std::cout << "Log: " + message.toString() + '\n';
}

void ConsoleLogViewTab::setMargin(int x, int y) {
    _x_margin = x;
    _y_margin = y;
}
