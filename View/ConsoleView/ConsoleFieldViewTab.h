#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_

#include <memory>

#include "../FieldViewMessage.h"
#include "../../Datatypes/Size.h"

class ConsoleFieldViewAdapter;

class WindowsConsoleHelper;

class ConsoleFieldViewTab {
public:
    explicit ConsoleFieldViewTab(std::shared_ptr<ConsoleFieldViewAdapter> adapter = nullptr);

    void setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter);
    void update(const FieldViewMessage& message);

    void setMargin(int x, int y);
    void setMargin(const Size& margin);

private:
    void resize(const Size& field_size);

    std::shared_ptr<ConsoleFieldViewAdapter> _adapter;
    Size _margin;
};

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEFIELDVIEWTAB_H_