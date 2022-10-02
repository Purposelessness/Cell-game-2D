#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_

#include "../FieldViewMessage.h"

class ConsoleFieldViewAdapter {
    using Map = std::unordered_map<CellView, char>;

public:
    explicit ConsoleFieldViewAdapter(Map symbols) : symbols(std::move(symbols)) {}

    char symbol(CellView type);
    Map symbols;
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_