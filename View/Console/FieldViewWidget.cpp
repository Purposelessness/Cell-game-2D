#include "FieldViewWidget.h"

#include <iostream>
#include <utility>

#include "FieldViewAdapter.h"
#include "Helper.h"
#include "../../Utility/Log/Log.h"

namespace console {

    FieldViewWidget::FieldViewWidget(std::shared_ptr<FieldViewAdapter> adapter)
        : _adapter(std::move(adapter)) {}

    void FieldViewWidget::update(const FieldViewMessage& message) {
        if (_adapter == nullptr) {
            LOG_WARNING << "ConsoleFieldViewTab: No adapter!";
            return;
        }

        if (!message.size.isNull()) {
            resize(message.size);
        }

        for (auto& c : message.changes) {
            Helper::setCursorPosition(rect.top_left + c.first);
            std::cout << _adapter->symbol(c.second);
        }
    }

    void FieldViewWidget::setAdapter(std::shared_ptr<FieldViewAdapter> adapter) {
        _adapter = std::move(adapter);
    }

}
