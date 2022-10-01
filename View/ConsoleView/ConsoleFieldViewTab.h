#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_

#include <memory>

#include "../FieldViewMessage.h"

class ConsoleFieldViewAdapter;

class ConsoleFieldViewTab {
public:
    ConsoleFieldViewTab();
    explicit ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter);

    void setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter);
    void update(const FieldViewMessage& message);

    void setMargin(int x, int y);

private:
    std::shared_ptr<ConsoleFieldViewAdapter> _adapter;
    int _margin_x;
    int _margin_y;
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_