#ifndef GAME_VIEW_CELLVIEWRECOGNIZER_H_
#define GAME_VIEW_CELLVIEWRECOGNIZER_H_

#include "../Objects/Field/Cell.h"
#include "FieldViewMessage.h"

class CellViewRecognizer {
public:
    static inline CellView use(const Cell& cell) {
        return cell.hasPlayerOn() ? CellView::Player : (cell.isPassable() ? CellView::Empty : CellView::Wall);
    }
};

#endif //GAME_VIEW_CELLVIEWRECOGNIZER_H_