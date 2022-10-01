#ifndef GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_
#define GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_

#include <memory>

#include "../../../Engine/View/ViewMessage.h"
#include "../FieldViewMessage.h"
#include "ConsoleFieldViewTab.h"
#include "ConsoleLogViewTab.h"

#include "ConsoleFieldViewAdapter.h"

class ConsoleViewRenderer {
public:
    ConsoleViewRenderer();

    template<TViewMessage T>
    void update(const T& message);

    // TODO: scan from file
    void setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter);

private:
    std::unique_ptr<ConsoleFieldViewTab> _field_view_tab;
    std::unique_ptr<ConsoleLogViewTab> _log_view_tab;
};

#endif //GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_