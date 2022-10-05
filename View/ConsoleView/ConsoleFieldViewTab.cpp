#include "ConsoleFieldViewTab.h"

#include <iostream>
#include <utility>

#include "ConsoleFieldViewAdapter.h"
#include "WindowsConsoleHelper.h"

ConsoleFieldViewTab::ConsoleFieldViewTab() : ConsoleFieldViewTab(nullptr) {}

ConsoleFieldViewTab::ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter)
    : _adapter(std::move(adapter)), _margin_x(0), _margin_y(0) {}

void ConsoleFieldViewTab::update(const FieldViewMessage& message) {
    if (_adapter == nullptr) {
        // TODO: Log warning: no adapter
        return;
    }
    for (auto& c : message.changes) {
        WindowsConsoleHelper::setCursorPosition(_margin_x + c.first.x, _margin_y + c.first.y);
        std::cout << _adapter->symbol(c.second);
    }
}

void ConsoleFieldViewTab::setMargin(int x, int y) {
    _margin_x = x;
    _margin_y = y;
}

void ConsoleFieldViewTab::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _adapter = adapter;
}
