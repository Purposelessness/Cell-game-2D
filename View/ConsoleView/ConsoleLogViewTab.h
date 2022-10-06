#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_

#include "ConsoleWindowTab.h"
#include "../../Engine/View/ViewMessage.h"
#include "../../Datatypes/Size.h"

class ConsoleLogViewTab : public ConsoleWindowTab {
public:
    void update(const ViewMessage& message) const;

private:
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLELOGVIEWTAB_H_