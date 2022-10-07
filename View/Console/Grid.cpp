#include "Grid.h"

#include <utility>

namespace console {

    Grid::Grid(WidgetObserver* observer) : _observer(observer), _margin({}), _elements({}) {}

    void Grid::addWidget(std::shared_ptr<Widget> widget, int row, int column) {
        widget->setObserver(this);
        _elements[row][column] = std::move(widget);
        onSizeUpdated(this);
    }

    void Grid::setSize(int row_count, int column_count) {
        _grid_size = {column_count, row_count};
        _elements.resize(row_count);
        for (auto& el : _elements) {
            el.resize(column_count);
        }
    }

    void Grid::setMargin(const Size& size) {
        _margin = size;
        onSizeUpdated(this);
    }

    void Grid::onSizeUpdated(Widget* widget) {
        Size grid_size{};
        int row_count = _grid_size.y;
        int column_count = _grid_size.x;

        std::vector<int> row_height;
        std::vector<int> column_width;
        row_height.resize(row_count);
        column_width.resize(column_count);

        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < column_count; ++j) {
                if (_elements[i][j] == nullptr)
                    continue;
                auto size = _elements[i][j]->getSize();
                row_height[i] = std::max(row_height[i], size.y);
                column_width[j] = std::max(column_width[j], size.x);
            }
        }
        int y_offset = 0;
        int x_offset = 0;
        for (int i = 0; i < row_count; ++i) {
            x_offset = 0;
            y_offset += _margin.y;
            for (int j = 0; j < column_count; ++j) {
                auto& element = _elements[i][j];
                if (element == nullptr)
                    continue;
                x_offset += _margin.x;
                element->setTopLeft({x_offset, y_offset});
                element->resize(column_width[j], row_height[i], false);
                x_offset += column_width[j];
            }
            y_offset += row_height[i];
        }
        int width = x_offset + _margin.x;
        int height = y_offset + _margin.y;

        grid_size = {width, height};

//        for (auto& el : _elements) {
//            size += _margin;
//            el->setTopLeft(Point{_margin.x, size.y});
//            size += el->getSize();
//        }
        resize(grid_size);
        if (_observer)
            _observer->onSizeUpdated(this);
    }

}
