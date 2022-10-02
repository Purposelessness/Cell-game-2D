#ifndef GAME_CORE_VIEWSYSTEMDEPLOYER_H_
#define GAME_CORE_VIEWSYSTEMDEPLOYER_H_

#include <memory>

#include "../Utility/IDisposable.h"
#include "../Engine/View/ViewSystem.h"
#include "../View/ConsoleView/ConsoleViewRenderer.h"

class ViewSystemDeployer : public IDisposable {
    using ViewSystemType = ViewSystem<ConsoleViewRenderer>;

public:
    ViewSystemDeployer() : _view_system(std::make_shared<ViewSystemType>()) {
        auto console_view_renderer = std::make_unique<ConsoleViewRenderer>();
        auto adapter = std::make_shared<ConsoleFieldViewAdapter>();
        auto symbols = std::unordered_map<FieldViewType, char>{};

        symbols[FieldViewType::Undefined] = '?';
        symbols[FieldViewType::Cell] = '.';
        symbols[FieldViewType::Wall] = '#';
        symbols[FieldViewType::Player] = '&';
        adapter->symbols = symbols;
        console_view_renderer->setAdapter(adapter);
        _view_system->addRenderer(std::move(console_view_renderer));

        auto mes = message();
        _view_system->render(mes);
    }

    auto& getSystem() {
        return _view_system;
    }

private:
    // TODO: mock method
    static FieldViewMessage message() {
        FieldViewMessage field_view_message;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == j) {
                    field_view_message.changes.emplace_back(Point{i, j}, FieldViewType::Wall);
                    continue;
                }
                field_view_message.changes.emplace_back(Point{i, j}, FieldViewType::Cell);
            }
        }
        field_view_message.information = "Field view message mock";

        return field_view_message;
    }

    std::shared_ptr<ViewSystemType> _view_system;
};

#endif //GAME_CORE_VIEWSYSTEMDEPLOYER_H_