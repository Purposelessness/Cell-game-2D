#ifndef GAME_VIEW_CELLVIEWRECOGNIZER_H_
#define GAME_VIEW_CELLVIEWRECOGNIZER_H_

#include <unordered_map>

#include "../Game/Field/Cell.h"
#include "FieldViewMessage.h"

class CellViewRecognizer {
public:
    static inline CellView use(const Cell& cell) {
        if (cell.getEvent() == nullptr) {
            return cell.hasPlayerOn() ? CellView::Player : (cell.isPassable() ? CellView::Empty : CellView::Wall);
        } else {
            return _event_types[typeid(cell.getEvent()).hash_code()];
        }
    }

private:
    static std::unordered_map<std::size_t, CellView> _event_types;
};

#endif //GAME_VIEW_CELLVIEWRECOGNIZER_H_