#ifndef GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_
#define GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_

#include "../FieldViewMessage.h"

class ConsoleFieldViewAdapter {
public:
    char symbol(FieldViewType type);

    std::unordered_map<FieldViewType, char> symbols;
};

#endif //GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWADAPTER_H_