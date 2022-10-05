#include "ConsoleViewRenderer.h"

#include "WindowsConsoleHelper.h"

ConsoleViewRenderer::ConsoleViewRenderer()
    : _field_view_tab(std::make_unique<ConsoleFieldViewTab>()),
      _log_view_tab(std::make_unique<ConsoleLogViewTab>()),
      _helper({}) {
    WindowsConsoleHelper::hideCursor();
    _helper.fitWindowSize();
    // TODO: remove hard coded values (maybe create grid...)
    _field_view_tab->setMargin(5, 0);
    _log_view_tab->setMargin(5, 30);
}

void ConsoleViewRenderer::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _field_view_tab->setAdapter(adapter);
}