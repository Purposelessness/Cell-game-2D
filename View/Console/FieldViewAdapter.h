#ifndef GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_
#define GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_

#include "../FieldViewMessage.h"

namespace console {

    class FieldViewAdapter {
        using Map = std::unordered_map<CellView, char>;

    public:
        explicit FieldViewAdapter(Map symbols) : symbols(std::move(symbols)) {}

        char symbol(CellView type);
        Map symbols;
    };

}


#endif //GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_