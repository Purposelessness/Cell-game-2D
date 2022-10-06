#include "LogViewWidget.h"

#include <iostream>

#include "Helper.h"

namespace console {

    LogViewWidget::LogViewWidget() {
        resize(15, 15);
    }

    void LogViewWidget::update(const ViewMessage& message) {
        Helper::setCursorPosition(0, 30 + _offset++);
        std::cout << "Log: " + message.toString() + '\n';
    }

}
