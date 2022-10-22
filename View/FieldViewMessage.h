#ifndef GAME_VIEW_FIELDVIEWMESSAGE_H_
#define GAME_VIEW_FIELDVIEWMESSAGE_H_

#include <utility>
#include <vector>

#include "../Engine/View/ViewMessage.h"
#include "../Datatypes/Point.h"
#include "../Datatypes/Size.h"

enum class CellView {
    Undefined,
    Empty,
    Wall,
    Player,
    ControlInversion,
    Money,
    Enemy,
    Exit,
    GenerateMoney
};

struct FieldViewMessage : public ViewMessage {
    explicit FieldViewMessage(std::vector<std::pair<Point, CellView>> changes, Size size = Size{})
        : changes(std::move(changes)), size(std::move(size)) {}

    explicit operator std::string() const override;

    static inline std::string cellViewToString(CellView cell_view) {
        switch (cell_view) {
            case CellView::Empty:
                return "Empty";
            case CellView::Wall:
                return "Wall";
            case CellView::Player:
                return "Player";
            case CellView::ControlInversion:
                return "ControlInversion";
            case CellView::Money:
                return "Money";
            case CellView::Enemy:
                return "Enemy";
            case CellView::Exit:
                return "Exit";
            case CellView::GenerateMoney:
                return "GenerateMoney";
            case CellView::Undefined:
            default:
                return "Undefined";
        }
    }

    std::vector<std::pair<Point, CellView>> changes;
    Size size;
};

#endif //GAME_VIEW_FIELDVIEWMESSAGE_H_
