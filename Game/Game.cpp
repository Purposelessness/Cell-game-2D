#include "Game.h"

#include <utility>

#include "../Core/IApplication.h"
#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/AddMoneySystem.h"
#include "../ECS/Systems/CleanDeadSystem.h"
#include "../ECS/Systems/DealDamageSystem.h"
#include "../ECS/Systems/HealthSystem.h"
#include "../ECS/Systems/MovementSystem.h"
#include "Events/EventFactory.h"

Game::Game(IApplication* application, std::shared_ptr<World> world)
    : _application(application), _world(std::move(world)) {}

void Game::initialize() {
  _field_changer = std::make_shared<FieldChanger>();
  std::weak_ptr<IGame> weak_this = shared_from_this();
  _event_factory =
      std::make_shared<EventFactory>(_world, _field_changer, weak_this);
  _field_configurator = std::make_unique<FieldConfigurator>(_event_factory);

  auto field = _field_configurator->execute();
  _fields = {field};

  // Systems
  _movement_system = _world->addSystem<MovementSystem>(fields());
  _world->addSystem<DealDamageSystem>();
  _world->addSystem<HealthSystem>();
  _world->addSystem<CleanDeadSystem>(shared_from_this());
  _world->addSystem<AddMoneySystem>();

  // Entities
  auto player = PlayerProvider::create(*_world);
}

void Game::reset() {
  auto field = _field_configurator->generate();
  _fields = {field};
  _movement_system->setFields(_fields);
  _application->onGameReseted();
}

const std::vector<std::shared_ptr<Field>>& Game::fields() { return _fields; }

void Game::stop() { _application->quit(); }
