#ifndef GAME_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_
#define GAME_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_

#include <memory>

#include "ConsoleWindowObserver.h"

#include "../../Engine/View/ViewMessage.h"
#include "../FieldViewMessage.h"
#include "ConsoleFieldViewTab.h"
#include "ConsoleLogViewTab.h"

#include "ConsoleFieldViewAdapter.h"
#include "WindowsConsoleHelper.h"

class ConsoleViewRenderer : public ConsoleWindowObserver, public std::enable_shared_from_this<ConsoleViewRenderer> {
public:
    ConsoleViewRenderer();

    template<TViewMessage T>
    inline void update(const T& message);

    // TODO: scan from file
    void setAdapter(const std::shared_ptr<ConsoleFieldViewAdapter>& adapter);

    void onSizeUpdated() override;

private:
    std::unique_ptr<ConsoleFieldViewTab> _field_view_tab;
    std::unique_ptr<ConsoleLogViewTab> _log_view_tab;

    WindowsConsoleHelper _helper;

    Size _window_size;
};

template<TViewMessage T>
void ConsoleViewRenderer::update(const T& message) {
    _log_view_tab->update(message);
}

template<>
inline void ConsoleViewRenderer::update<FieldViewMessage>(const FieldViewMessage& message) {
    _field_view_tab->update(message);
}

#endif //GAME_VIEW_CONSOLEVIEW_CONSOLEVIEWRENDERER_H_