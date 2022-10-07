#include "LogViewWidget.h"

#include <iostream>

#include "Helper.h"

namespace console {

    void LogViewWidget::update(const ViewMessage& message) {
        if (_buffer.size() >= rect.height()) {
            _buffer.pop_front();
            _buffer.emplace_back(message.toString());
            for (auto i = 0; i < _buffer.size(); ++i) {
                Helper::setCursorPosition(rect.left(), rect.top() + i);
                std::cout << _buffer.at(i) + std::to_string(rect.top()) + std::to_string(i) +'\n';
            }
        } else {
            std::string str = message.toString();
            _buffer.emplace_back(str);
            Helper::setCursorPosition(rect.left(), rect.top() + static_cast<int>(_buffer.size()) - 1);
            std::cout << str + '\n';
        }
    }

}
