#include "MainApplication.h"

#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"
#include "../Observer/FieldObserver.h"
#include "../Observer/LogObserver.h"
#include "GameDeployer.h"
#include "InputSystemDeployer.h"
#include "LogSystemCustomizer.h"
#include "ViewSystemDeployer.h"

MainApplication::MainApplication() {
  _world = std::make_shared<World>();

  // Log
  auto log_settings = LogSystemCustomizer::execute();
  auto log_observer = std::make_shared<LogObserver<ViewSystem>>();

  // View
  _view_system = ViewSystemDeployer::execute(log_settings.console_logging,
                                             log_settings.file_logging);
  log_observer->addClient(_view_system);

  // Game
  _game = GameDeployer::execute(this, _world);

  // Input
  _input_system = InputSystemDeployer::execute(*_world, _game);

  // Observers
  auto field_observer = std::make_shared<FieldObserver<ViewSystem>>(
      _game->fields()[0], _view_system);

  // Others
  _tickables.emplace_back(_input_system);

  _disposables.emplace_back(std::move(log_observer));
  _disposables.emplace_back(std::move(field_observer));
}

int MainApplication::execute(int delta_time) {
  LOG_INFO_F("Application executed");
  return Application::execute(delta_time);
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
  LOG_INFO_F("Application quited");
  system("pause");
}
