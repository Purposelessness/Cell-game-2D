#include "Field.h"

#include <memory>
#include <utility>

Field::Field() : Field(20, 20) {}

Field::Field(int width, int height) {
    if (width <= 0 || height <= 0) {
        this->width = 0;
        this->height = 0;
    } else {
        this->width = width;
        this->height = height;
    }
    cells.resize(this->height);
    for (int j = 0; j < this->height; ++j) {
        cells[j] = std::vector<Cell>(this->width);
    }
}

void Field::getSize(int &width, int &height) const {
    width = this->width;
    height = this->height;
}

Field::Field(const Field &other) : width(other.width), height(other.height) {
    cells = other.cells;
}

Field &Field::operator=(const Field &other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        cells = other.cells;
    }
    return *this;
}

Field::Field(Field &&other) noexcept: width(other.width), height(other.height), cells(std::move(other.cells)) {
    other.clearCellInfo();
}

Field &Field::operator=(Field &&other) noexcept {
    if (this != &other) {
        cells.clear();

        width = other.width;
        height = other.height;
        cells = std::move(other.cells);

        other.clearCellInfo();
    }
    return *this;
}

void Field::clearCellInfo() {
    width = 0;
    height = 0;
    cells.clear();
}

void Field::setCellEvent(int x, int y, std::shared_ptr<IEvent> event) {
    if (!pointIsValid(x, y))
        return;
    cells[y][x].changeEvent(std::move(event));
}

inline bool Field::pointIsValid(int x, int y) const {
    return x >= 0 && x < width &&
           y >= 0 && y < height;
}

Cell Field::getCell(int x, int y) {
    if (!pointIsValid(x, y))
        return {};
    return cells[y][x];
}
