#include "LogViewWidget.h"

#include <iostream>

#include "Helper.h"

namespace console {

    LogViewWidget::LogViewWidget() : _buffer({}), _flush({}) {}

    void LogViewWidget::update(const ViewMessage& message) {
        if (_buffer.size() >= rect.height() && rect.height() > 0) {
            std::string flush = std::string(rect.width(), ' ');
            _buffer.pop_front();
            _buffer.emplace_back(static_cast<std::string>(message));
            for (auto i = 0; i < _buffer.size(); ++i) {
                Helper::setCursorPosition(rect.left(), rect.top() + i);
                std::cout << flush;
                Helper::setCursorPosition(rect.left(), rect.top() + i);
                std::cout << _buffer.at(i) + '\n';
            }
        } else {
            std::string str = static_cast<std::string>(message);
            _buffer.emplace_back(str);
            Helper::setCursorPosition(rect.left(), rect.top() + static_cast<int>(_buffer.size()) - 1);
            std::cout << str + '\n';
        }
    }

}
