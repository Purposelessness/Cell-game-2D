#include "ViewRenderer.h"

#include "Helper.h"

namespace console {

    ViewRenderer::ViewRenderer()
        : _field_widget(std::make_shared<FieldViewWidget>()),
          _log_widget(std::make_shared<LogViewWidget>()),
          _helper({}), _window_size({}), _grid(Grid{}) {
        Helper::hideCursor();

        _grid.setSize(2, 1);
        _grid.setMargin(Size{2, 1});
        _grid.addWidget(_field_widget, 0, 0);
        _grid.addWidget(_log_widget, 1, 0);
        _log_widget->resize(20, 5);
        _field_widget->resize(20, 10);

        _grid.setObserver(this);
    }

    void ViewRenderer::setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter) {
        _field_widget->setAdapter(adapter);
    }

    void ViewRenderer::onSizeUpdated(Widget* widget) {
        _window_size = widget->getSize();
        _helper.resizeWindow(_window_size);
    }

}
