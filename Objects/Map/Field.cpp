#include "Field.h"

#include <algorithm>

Field::Field() : Field(20, 20) {}

Field::Field(int width, int height) : width(width), height(height) {
    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width]{};
    }
}

void Field::getSize(int &width, int &height) const {
    width = this->width;
    height = this->height;
}

Field::Field(const Field &other) : Field(other.width, other.height) {
    std::copy(&other.cells[0][0], &other.cells[0][0] + width * height, &cells[0][0]);
}

Field &Field::operator=(const Field &other) {
    if (this != &other) {
        delete[] cells;

        width = other.width;
        height = other.height;
        std::copy(&other.cells[0][0], &other.cells[0][0] + width * height, &cells[0][0]);
    }
    return *this;
}

Field::Field(Field &&other) noexcept : width(other.width), height(other.height) {
    cells = other.cells;

    other.clearCellInfo();
}

Field &Field::operator=(Field &&other) noexcept {
    if (this != &other) {
        delete[] cells;

        width = other.width;
        height = other.height;
        cells = other.cells;

        other.clearCellInfo();
    }
    return *this;
}

void Field::clearCellInfo() {
    width = 0;
    height = 0;
    cells = nullptr;
}

Field::~Field() {
    delete[] cells;
}


