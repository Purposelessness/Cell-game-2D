#ifndef GAME_GAME_GAME_H_
#define GAME_GAME_GAME_H_

#include <memory>
#include <vector>

#include "Field/Field.h"
#include "Field/FieldChanger.h"
#include "FieldConfigurator.h"
#include "IGame.h"
#include "SaveController.h"

class World;
class IApplication;
class MovementSystem;

class Game : public IGame, public std::enable_shared_from_this<Game> {
 public:
  explicit Game(IApplication* application, std::shared_ptr<World> world);
  void initialize();

  void reset() override;
  const std::vector<std::shared_ptr<Field>>& fields();
  void stop() override;

  void save() override;
  void load() override;

 private:
  void changeField(std::shared_ptr<Field> field);

  IApplication* _application;
  std::shared_ptr<World> _world;
  std::shared_ptr<FieldChanger> _field_changer;
  std::shared_ptr<EventFactory> _event_factory;
  std::unique_ptr<FieldConfigurator> _field_configurator;
  std::vector<std::shared_ptr<Field>> _fields;
  SaveController _save_controller;

  std::shared_ptr<MovementSystem> _movement_system;
};

#endif  // GAME_GAME_GAME_H_
