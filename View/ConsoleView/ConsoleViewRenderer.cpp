#include "ConsoleViewRenderer.h"

#include "WindowsConsoleHelper.h"

ConsoleViewRenderer::ConsoleViewRenderer()
    : _field_view_tab(std::make_unique<ConsoleFieldViewTab>()),
      _log_view_tab(std::make_unique<ConsoleLogViewTab>()),
      _helper({}), _window_size({}) {
    WindowsConsoleHelper::hideCursor();
    // TODO: remove hard coded values (maybe create grid...)
    _field_view_tab->setObserver(this);
    _log_view_tab->setObserver(this);
    _field_view_tab->setMargin(5, 0);
    _log_view_tab->setMargin(5, 30);
}

void ConsoleViewRenderer::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _field_view_tab->setAdapter(adapter);
}

void ConsoleViewRenderer::onSizeUpdated() {
    _window_size = _field_view_tab->getSize();
    _window_size += 2 * _field_view_tab->getMargin();
    _window_size += _log_view_tab->getSize();
    _window_size += 2 * _log_view_tab->getMargin();
    _helper.resizeWindow(_window_size);
}
