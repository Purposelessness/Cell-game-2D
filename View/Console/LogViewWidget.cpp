#include "LogViewWidget.h"

#include <iostream>

#include "Helper.h"

namespace console {

LogViewWidget::LogViewWidget() : _buffer({}) {}

LogViewWidget& LogViewWidget::operator<<(const InfoMessage& message) {
  auto str = static_cast<std::string>(message);
  std::string new_str{};
  int size = static_cast<int>(str.size());
  int rect_width = rect.width();
  if (size >= rect_width) {
    new_str = str.substr(rect_width);
    str = str.substr(0, rect_width);
  }
  if (static_cast<int>(_buffer.size()) >= rect.height() && rect.height() > 0) {
    _buffer.pop_front();
    _buffer.emplace_back(str);
    for (auto i = 0; i < static_cast<int>(_buffer.size()); ++i) {
      printStr(_buffer.at(i), Point{rect.left(), rect.top() + i});
    }
  } else {
    _buffer.emplace_back(str);
    printStr(str, Point{rect.left(),
                        rect.top() + static_cast<int>(_buffer.size()) - 1});
  }
  return *this;
}

void LogViewWidget::printStr(const std::string& str, const Point& point) {
  std::string flush = std::string(rect.width(), ' ');
  Helper::setCursorPosition(point.x, point.y);
  std::cout << flush;
  Helper::setCursorPosition(point.x, point.y);
  std::cout << str.substr(0, rect.width()) + '\n';
}

}  // namespace console
