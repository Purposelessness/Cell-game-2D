#include "MainApplication.h"

#include "ViewSystemDeployer.h"
#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "InputSystemDeployer.h"
#include "LogSystemCustomizer.h"

#include "../Observer/LogObserver.h"
#include "../Observer/FieldObserver.h"
#include "GameDeployer.h"

MainApplication::MainApplication() : Application() {
    _world = std::make_shared<World>();

    // Log
    bool console_logging, file_logging;
    LogSystemCustomizer::execute(console_logging, file_logging);
    auto log_observer = std::make_shared<LogObserver<ViewSystem>>();

    // View
    _view_system = ViewSystemDeployer::execute(console_logging, file_logging);
    log_observer->addClient(_view_system);

    // Input
    _input_system = InputSystemDeployer::execute(*_world);

    // Game
    _game = GameDeployer::execute(this, _world);

    // Observers
    auto field_observer = std::make_shared<FieldObserver<ViewSystem>>(_game->fields()[0], _view_system);

    // Others
    _tickables.emplace_back(_input_system);

    _disposables.emplace_back(std::move(log_observer));
    _disposables.emplace_back(std::move(field_observer));
}

void MainApplication::tick() {
    Application::tick();
    for (auto& tickable : _tickables) {
        tickable->tick();
    }
    _world->tick();
}

void MainApplication::addTickable(std::shared_ptr<ITickable> tickable) {
    _tickables.emplace_back(std::move(tickable));
}

void MainApplication::addDisposable(std::shared_ptr<IDisposable> disposable) {
    _disposables.emplace_back(std::move(disposable));
}

void MainApplication::quit() {
    Application::quit();
    system("pause");
}
