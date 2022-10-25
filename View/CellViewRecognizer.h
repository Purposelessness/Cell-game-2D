#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpotentially-evaluated-expression"
#ifndef GAME_VIEW_CELLVIEWRECOGNIZER_H_
#define GAME_VIEW_CELLVIEWRECOGNIZER_H_

#include <unordered_map>

#include "../Game/Field/Cell.h"
#include "../Message/FieldInfoMessage.h"

class CellViewRecognizer {
public:
    static inline CellView use(const Cell& cell) {
        if (cell.hasPlayerOn())
            return CellView::Player;
        if (cell.getEvent() == nullptr) {
            return cell.isPassable() ? CellView::Empty : CellView::Wall;
        } else {
            auto a = _event_types[typeid(*cell.getEvent()).hash_code()];
            return a;
        }
    }

private:
    static std::unordered_map<std::size_t, CellView> _event_types;
};

#endif //GAME_VIEW_CELLVIEWRECOGNIZER_H_
#pragma clang diagnostic pop