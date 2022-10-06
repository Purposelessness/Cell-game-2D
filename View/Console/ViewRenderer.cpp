#include "ViewRenderer.h"

#include "Helper.h"

namespace console {

    ViewRenderer::ViewRenderer()
        : _field_view_tab(std::make_unique<FieldViewWidget>()),
          _log_view_tab(std::make_unique<LogViewWidget>()),
          _helper({}), _window_size({}) {
        Helper::hideCursor();
    //    _helper.resizeWindow(1080, 720);
        // TODO: remove hard coded values (maybe create grid...)
        _field_view_tab->setObserver(this);
        _log_view_tab->setObserver(this);
        _field_view_tab->setMargin(5, 0, false);
        _log_view_tab->setMargin(5, 5, false);
        onSizeUpdated();
    }

    void ViewRenderer::setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter) {
        _field_view_tab->setAdapter(adapter);
    }

    void ViewRenderer::onSizeUpdated() {
        _window_size = _field_view_tab->getSize();
        _window_size += _field_view_tab->getMargin();
        _window_size += _log_view_tab->getSize();
        _window_size += _log_view_tab->getMargin();
        _helper.resize(_window_size);
    //    _helper.resizeBuffer(_window_size);
    //    _helper.fitWindowSize();
    }

}
