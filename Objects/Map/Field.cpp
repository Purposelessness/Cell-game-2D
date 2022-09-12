#include "Field.h"

#include <memory>
#include <utility>

Field::Field() : Field(20, 20) {}

Field::Field(int width, int height) : width(width), height(height), cells(height) {
    for (int j = 0; j < height; ++j) {
        cells[j] = std::vector<Cell>(width);
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
    if (x >= width || y >= height)
        return;
    cells[y][x].changeEvent(std::move(event));
}
