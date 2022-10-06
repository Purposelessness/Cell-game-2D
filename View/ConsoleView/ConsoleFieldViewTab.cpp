#include "ConsoleFieldViewTab.h"

#include <iostream>
#include <utility>

#include "ConsoleFieldViewAdapter.h"
#include "WindowsConsoleHelper.h"

ConsoleFieldViewTab::ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter)
    : _adapter(std::move(adapter)), _margin(Size{0, 0}) {}

void ConsoleFieldViewTab::update(const FieldViewMessage& message) {
    if (_adapter == nullptr) {
        Log::instance()("ConsoleFiendViewTab: No adapter!", Log::Warning);
        return;
    }

    if (!message.size.isNull()) {

    }

    for (auto& c : message.changes) {
        WindowsConsoleHelper::setCursorPosition(_margin.x + c.first.x, _margin.y + c.first.y);
        std::cout << _adapter->symbol(c.second);
    }
}

void ConsoleFieldViewTab::resize(const Size& size) {

}

void ConsoleFieldViewTab::setMargin(const Size& margin) {
    _margin = margin;
}

void ConsoleFieldViewTab::setMargin(int x, int y) {
    _margin.x = x;
    _margin.y = y;
}

void ConsoleFieldViewTab::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _adapter = adapter;
}
