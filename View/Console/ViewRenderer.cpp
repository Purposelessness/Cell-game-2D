#include "ViewRenderer.h"

#include "Helper.h"

namespace console {

    ViewRenderer::ViewRenderer()
        : _field_view_tab(std::make_shared<FieldViewWidget>()),
          _log_view_tab(std::make_shared<LogViewWidget>()),
          _helper({}), _window_size({}), _grid(Grid{this}) {
        Helper::hideCursor();

        _grid.setMargin({2, 1});
        _grid.addWidget(_field_view_tab);
        _grid.addWidget(_log_view_tab);
        _log_view_tab->resize(20, 5);
        _field_view_tab->resize(20, 10);
    }

    void ViewRenderer::setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter) {
        _field_view_tab->setAdapter(adapter);
    }

    void ViewRenderer::onSizeUpdated(Widget* widget) {
        _window_size = widget->getSize();
        _helper.resize(_window_size);
    }

}
