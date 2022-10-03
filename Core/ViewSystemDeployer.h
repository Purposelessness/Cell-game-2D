#ifndef GAME_CORE_VIEWSYSTEMDEPLOYER_H_
#define GAME_CORE_VIEWSYSTEMDEPLOYER_H_

#include <memory>

#include "../Utility/IDisposable.h"
#include "../Engine/View/ViewSystem.h"
#include "../View/ConsoleView/ConsoleViewRenderer.h"

class ViewSystemDeployer : public IDisposable {
public:
    using ViewSystemType = ViewSystem<ConsoleViewRenderer>;

    ViewSystemDeployer() : _view_system(std::make_shared<ViewSystemType>()) {
        auto console_view_renderer = std::make_unique<ConsoleViewRenderer>();

        auto symbols = std::unordered_map<CellView, char>{};
        symbols[CellView::Undefined] = '?';
        symbols[CellView::Empty] = '.';
        symbols[CellView::Wall] = '#';
        symbols[CellView::Player] = '&';
        auto adapter = std::make_shared<ConsoleFieldViewAdapter>(symbols);

        console_view_renderer->setAdapter(adapter);
        _view_system->addRenderer(std::move(console_view_renderer));

        auto mes = message();
        _view_system->update(mes);
    }

    auto& getSystem() {
        return _view_system;
    }

private:
    // TODO: mock method
    static FieldViewMessage message() {
        FieldViewMessage field_view_message{{}};
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == j) {
                    field_view_message.changes.emplace_back(Point{i, j}, CellView::Wall);
                    continue;
                }
                field_view_message.changes.emplace_back(Point{i, j}, CellView::Empty);
            }
        }
        return field_view_message;
    }

    std::shared_ptr<ViewSystemType> _view_system;
};

#endif //GAME_CORE_VIEWSYSTEMDEPLOYER_H_