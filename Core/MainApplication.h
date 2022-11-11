#ifndef GAME_CORE_MAINAPPLICATION_H_
#define GAME_CORE_MAINAPPLICATION_H_

#include <memory>
#include <vector>

#include "../Engine/Core/Application.h"
#include "../Utility/IDisposable.h"
#include "IApplication.h"

class ITickable;
class World;
class ViewSystem;
class InputSystem;
class Game;
class IFieldObserver;
class ILogObserver;

class MainApplication : public Application, public IApplication {
 public:
  MainApplication();

  int execute(int delta_time) override;
  void tick() override;

  void addTickable(std::shared_ptr<ITickable> tickable) override;
  void addDisposable(std::shared_ptr<IDisposable> disposable) override;
  void redraw() override;
  void onGameReseted() override;
  void quit() override;

 private:
  std::shared_ptr<World> _world;
  std::shared_ptr<ViewSystem> _view_system;
  std::shared_ptr<InputSystem> _input_system;
  std::shared_ptr<Game> _game;
  std::vector<std::shared_ptr<ITickable>> _tickables;
  std::vector<std::shared_ptr<IDisposable>> _disposables;
  std::shared_ptr<ILogObserver> _log_observer;
  std::shared_ptr<IFieldObserver> _field_observer;
};

#endif  // GAME_CORE_MAINAPPLICATION_H_
