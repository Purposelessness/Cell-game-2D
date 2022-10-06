#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_

#include <memory>

#include "ConsoleWindowTab.h"
#include "../FieldViewMessage.h"
#include "../../Datatypes/Size.h"

class ConsoleFieldViewAdapter;

class WindowsConsoleHelper;

class ConsoleFieldViewTab : public ConsoleWindowTab {
public:
    explicit ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter = nullptr);

    void setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter);
    void update(const FieldViewMessage& message);

private:
    std::shared_ptr<ConsoleFieldViewAdapter> _adapter;
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_