#ifndef GAME_CORE_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_
#define GAME_CORE_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_

#include "../../../Engine/View/ViewMessage.h"

class ConsoleLogViewTab {
public:
    void setMargin(int x, int y);

    void update(const ViewMessage& message) const;

private:
    int _x_margin;
    int _y_margin;
};

#endif //GAME_CORE_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_