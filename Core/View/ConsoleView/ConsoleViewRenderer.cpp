#include "ConsoleViewRenderer.h"

#include "ConsoleHelper.h"

ConsoleViewRenderer::ConsoleViewRenderer()
    : _field_view_tab(std::make_unique<ConsoleFieldViewTab>()), _log_view_tab(std::make_unique<ConsoleLogViewTab>()) {
    ConsoleHelper::hideCursor();
    // TODO: remove hard coded values (maybe create grid...)
    _field_view_tab->setMargin(5, 0);
    _log_view_tab->setMargin(5, 50);
}

void ConsoleViewRenderer::setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter) {
    _field_view_tab->setAdapter(adapter);
}

template<TViewMessage T>
void ConsoleViewRenderer::update(const T& message) {
    _log_view_tab->update(message);
}

template<>
void ConsoleViewRenderer::update<FieldViewMessage>(const FieldViewMessage& message) {
    _field_view_tab->update(message);
}
