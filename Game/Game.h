#ifndef GAME_GAME_GAME_H_
#define GAME_GAME_GAME_H_

#include <memory>
#include <vector>

#include "Field/Field.h"
#include "Field/FieldChanger.h"
#include "IGame.h"

class World;
class IApplication;

class Game : public IGame, public std::enable_shared_from_this<Game> {
 public:
  explicit Game(IApplication* application, std::shared_ptr<World> world);
  void initialize();

  const std::vector<std::shared_ptr<Field>>& fields();
  void stop() override;

 private:
  IApplication* _application;
  std::shared_ptr<World> _world;
  std::shared_ptr<FieldChanger> _field_changer;
  std::shared_ptr<EventFactory> _event_factory;
  std::vector<std::shared_ptr<Field>> _fields;
};

#endif  // GAME_GAME_GAME_H_
