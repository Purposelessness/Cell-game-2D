#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "Cell.h"

class Field {
public:
    Field();
    explicit Field(int width, int height);

    void getSize(int &width, int &height) const;

    Field(const Field &other);
    Field &operator=(const Field &other);

    Field(Field &&other) noexcept;
    Field &operator=(Field &&other) noexcept;

    ~Field();

private:
    void clearCellInfo();

    Cell **cells;
    int width, height;
};

#endif //GAME_FIELD_H
