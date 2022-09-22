#ifndef GAME_OBJECTS_FIELD_FIELD_H_
#define GAME_OBJECTS_FIELD_FIELD_H_

#include <memory>
#include <vector>

#include "Cell.h"

class Field {
public:
    Field();
    explicit Field(int width, int height);

    void getSize(int& width, int& height) const;
    std::vector<Cell> &operator[](int row);
    Cell getCell(int x, int y);
    void setCellEvent(int x, int y, std::shared_ptr<IEvent> event);

    [[nodiscard]] inline bool isPointValid(int x, int y) const;

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other) noexcept;
    Field& operator=(Field&& other) noexcept;

    auto operator<=>(const Field& other) const = default;

private:
    void swap(Field& other);

    std::vector<std::vector<Cell>> _cells;
    int _width, _height;
};

#endif //GAME_OBJECTS_FIELD_FIELD_H_
