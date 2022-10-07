#include "Field.h"

#include <memory>
#include <utility>

Field::Field() : Field(50, 20) {}

Field::Field(int width, int height) {
    _size = width <= 0 || height <= 0 ? Size{0, 0} : Size{width, height};
    _cells.resize(this->_size.y);
    for (int j = 0; j < this->_size.y; ++j) {
        _cells[j].resize(this->_size.x);
    }
}

Field::Field(const Field& other) : _size(other._size), _cells(other._cells) {}

Field& Field::operator=(Field other) {
    swap(other);
    return *this;
}

Field::Field(Field&& other) noexcept: _size(std::move(other._size)), _cells(std::move(other._cells)) {
    other._size.x = 0;
    other._size.y = 0;
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other) {
        Field new_field = std::move(other);
        swap(new_field);
    }
    return *this;
}

void Field::swap(Field& other) {
    std::swap(_size, other._size);
    std::swap(_cells, other._cells);
}

void Field::getSize(int& width, int& height) const {
    width = this->_size.x;
    height = this->_size.y;
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
    int x = point.x >= 0 ? point.x % _size.x : _size.x - (-point.x % _size.x);
    int y = point.y >= 0 ? point.y % _size.y : _size.y - (-point.y % _size.y);
    return Point{x, y};
}

bool Field::isPointValid(int x, int y) const {
    return x >= 0 && x < _size.x &&
        y >= 0 && y < _size.y;
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
    setCellEvent(Point{x, y}, std::move(event));
}

void Field::setCellEvent(const Point& point, std::shared_ptr<IEvent> event) {
    if (!isPointValid(point))
        return;
    _cells[point.y][point.x].changeEvent(std::move(event));
    event_handler({{point}});
}

std::vector<Cell>& Field::operator[](int row) {
    return _cells[row];
}

bool Field::operator==(const Field& other) const {
    return _size.x == other._size.x && _size.y == other._size.y && _cells == other._cells;
}

void Field::onPlayerStepped(const Point& point) {
    _cells[point.y][point.x].onPlayerStepped();
    event_handler({{point}});
}

void Field::onPlayerLeft(const Point& point) {
    _cells[point.y][point.x].onPlayerLeft();
    event_handler({{point}});
}

Size Field::getSize() const {
    return _size;
}
