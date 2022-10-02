#ifndef GAME_VIEW_FIELDVIEWMESSAGE_H_
#define GAME_VIEW_FIELDVIEWMESSAGE_H_

#include <vector>

#include "../Engine/View/ViewMessage.h"
#include "../Datatypes/Point.h"

enum class CellView {
    Undefined,
    Empty,
    Wall,
    Player
};

struct FieldViewMessage : public ViewMessage {
    explicit FieldViewMessage(std::vector<std::pair<Point, CellView>> changes) : changes(std::move(changes)) {}

    [[nodiscard]] std::string toString() const override {
        std::string out = "\n";
        for (const auto& k : changes) {
            out += "\t" + k.first.toString() + ": " + cellViewToString(k.second) + '\n';
        }
    }

    static inline std::string cellViewToString(CellView cell_view) {
        switch (cell_view) {
            case CellView::Empty:
                return "Empty";
            case CellView::Wall:
                return "Wall";
            case CellView::Player:
                return "Player";
            case CellView::Undefined:
                return "Undefined";
        }
    }

    std::vector<std::pair<Point, CellView>> changes;
};

#endif //GAME_VIEW_FIELDVIEWMESSAGE_H_
