#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "Cell.h"

#include <memory>
#include <vector>

class Field {
public:
    Field();
    explicit Field(int width, int height);

    void getSize(int &width, int &height) const;
    void setCellEvent(int x, int y, std::shared_ptr<IEvent> event);

    Field(const Field &other);
    Field &operator=(const Field &other);

    Field(Field &&other) noexcept;
    Field &operator=(Field &&other) noexcept;

private:
    void clearCellInfo();

    std::vector<std::vector<Cell>> cells;
    int width, height;
};

#endif //GAME_FIELD_H
