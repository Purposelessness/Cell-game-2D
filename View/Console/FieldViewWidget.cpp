#include "FieldViewWidget.h"

#include <iostream>
#include <utility>

#include "../../Utility/Log/Log.h"
#include "FieldViewAdapter.h"
#include "Helper.h"

namespace console {

FieldViewWidget& FieldViewWidget::operator<<(const FieldInfoMessage& message) {
  if (!message.size.isNull()) {
    resize(message.size);
  }

  for (const auto& c : message.changes) {
    Helper::setCursorPosition(rect.top_left + c.first);
    std::cout << FieldViewAdapter::encode(c.second);
  }
  return *this;
}

}  // namespace console
