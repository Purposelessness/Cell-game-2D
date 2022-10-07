#include "Grid.h"

#include <utility>

namespace console {

    Grid::Grid(WidgetObserver* observer) : _observer(observer), _margin({}), _elements({}) {}

    void Grid::addWidget(std::shared_ptr<Widget> widget) {
        widget->setObserver(this);
        _elements.emplace_back(std::move(widget));
        onSizeUpdated(this);
    }

    void Grid::setMargin(const Size& size) {
        _margin = size;
        onSizeUpdated(this);
    }

    void Grid::onSizeUpdated(Widget* widget) {
        Size size{};
        for (auto& el : _elements) {
            size += _margin;
            el->setTopLeft(Point{_margin.x, size.y});
            size += el->getSize();
        }
        resize(size);
        if (_observer)
            _observer->onSizeUpdated(this);
    }

}
