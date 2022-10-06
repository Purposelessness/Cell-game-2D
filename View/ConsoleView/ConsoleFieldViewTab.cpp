#include "ConsoleFieldViewTab.h"

#include <iostream>
#include <utility>

#include "ConsoleFieldViewAdapter.h"
#include "WindowsConsoleHelper.h"

ConsoleFieldViewTab::ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter)
    : _adapter(std::move(adapter)) {}

void ConsoleFieldViewTab::update(const FieldViewMessage& message) {
    if (_adapter == nullptr) {
        Log::instance()("ConsoleFiendViewTab: No adapter!", Log::Warning);
        return;
    }

    if (!message.size.isNull()) {

    }

    for (auto& c : message.changes) {
        WindowsConsoleHelper::setCursorPosition(margin.x + c.first.x, margin.y + c.first.y);
        std::cout << _adapter->symbol(c.second);
    }
}

void ConsoleFieldViewTab::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _adapter = adapter;
}
