#ifndef GAME_CORE_VIEWSYSTEMDEPLOYER_H_
#define GAME_CORE_VIEWSYSTEMDEPLOYER_H_

#include <memory>

#include "../Utility/IDisposable.h"
#include "../Engine/View/ViewSystem.h"
#include "../View/ConsoleView/ConsoleViewRenderer.h"

class ViewSystemDeployer {
public:
    static auto start() {
        auto view_system = std::make_shared<ViewSystem>();
        auto console_view_renderer = std::make_unique<ConsoleViewRenderer>();

        auto symbols = std::unordered_map<CellView, char>{};
        symbols[CellView::Undefined] = '?';
        symbols[CellView::Empty] = '.';
        symbols[CellView::Wall] = '#';
        symbols[CellView::Player] = '&';
        auto adapter = std::make_shared<ConsoleFieldViewAdapter>(symbols);

        console_view_renderer->setAdapter(adapter);
        view_system->addRenderer(std::move(console_view_renderer));
        return view_system;
    }
};

#endif //GAME_CORE_VIEWSYSTEMDEPLOYER_H_