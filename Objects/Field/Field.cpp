#include "Field.h"

#include <memory>
#include <utility>

Field::Field() : Field(20, 20) {}

Field::Field(int width, int height) {
    if (width <= 0 || height <= 0) {
        this->_width = 0;
        this->_height = 0;
    } else {
        this->_width = width;
        this->_height = height;
    }
    _cells.resize(this->_height);
    for (int j = 0; j < this->_height; ++j) {
        _cells[j].resize(this->_width);
    }
}

Field::Field(const Field& other) : _width(other._width), _height(other._height), _cells(other._cells) {}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        Field copy = other;
        swap(copy);
    }
    return *this;
}

Field::Field(Field&& other) noexcept: _width(other._width), _height(other._height), _cells(std::move(other._cells)) {
    other._width = 0;
    other._height = 0;
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other) {
        Field new_field = std::move(other);
        swap(new_field);
    }
    return *this;
}

void Field::swap(Field& other) {
    std::swap(_width, other._width);
    std::swap(_height, other._height);
    std::swap(_cells, other._cells);
}

void Field::getSize(int& width, int& height) const {
    width = this->_width;
    height = this->_height;
}

Cell& Field::getCell(int x, int y) {
    if (!isPointValid(x, y))
        return _empty_cell;
    return _cells[y][x];
}

Cell& Field::getCell(const Point& point) {
    return getCell(point.x, point.y);
}

Point Field::normalizePoint(const Point& point) const {
    if (isPointValid(point))
        return point;
    int x = point.x >= 0 ? point.x % _width : _width - (-point.x % _width);
    int y = point.y >= 0 ? point.y % _height : _height - (-point.y % _height);
    return Point{x, y};
}

bool Field::isPointValid(int x, int y) const {
    return x >= 0 && x < _width &&
        y >= 0 && y < _height;
}

bool Field::isPointValid(const Point& point) const {
    return isPointValid(point.x, point.y);
}

bool Field::isPointPassable(const Point& point) const {
    if (!isPointValid(point))
        return false;
    return _cells[point.y][point.x].isPassable();
}

void Field::setCellEvent(int x, int y, std::shared_ptr<IEvent> event) {
    if (!isPointValid(x, y))
        return;
    _cells[y][x].changeEvent(std::move(event));
    event_handler({std::vector<Point>{Point{x, y}}});
}

void Field::setCellEvent(const Point& point, std::shared_ptr<IEvent> event) {
    setCellEvent(point.x, point.y, std::move(event));
}

std::vector<Cell>& Field::operator[](int row) {
    return _cells[row];
}

bool Field::operator==(const Field& other) const {
    return _width == other._width && _height == other._height && _cells == other._cells;
}

void Field::onPlayerStepped(const Point& point) {
    _cells[point.y][point.x].onPlayerStepped();
    event_handler({std::vector<Point>{Point{point.x, point.y}}});
}

void Field::onPlayerLeft(const Point& point) {
    _cells[point.y][point.x].onPlayerLeft();
    event_handler({std::vector<Point>{Point{point.x, point.y}}});
}
