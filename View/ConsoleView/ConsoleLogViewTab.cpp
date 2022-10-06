#include "ConsoleLogViewTab.h"

#include <iostream>

#include "WindowsConsoleHelper.h"

void ConsoleLogViewTab::update(const ViewMessage& message) const {
    WindowsConsoleHelper::setCursorPosition(0, 30);
    std::cout << "Log: " + message.toString() + '\n';
}
