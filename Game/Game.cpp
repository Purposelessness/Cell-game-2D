#include "Game.h"

#include <utility>

#include "../Core/IApplication.h"
#include "../ECS/EntityProviders/PlayerProvider.h"
#include "../ECS/Systems/AddMoneySystem.h"
#include "../ECS/Systems/CleanDeadSystem.h"
#include "../ECS/Systems/DealDamageSystem.h"
#include "../ECS/Systems/HealthSystem.h"
#include "../ECS/Systems/MovementSystem.h"
#include "Events/ControlInversionEvent.h"
#include "Events/EnemyEvent.h"
#include "Events/EventFactory.h"
#include "Events/ExitEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/MoneyEvent.h"
#include "Field/Generator/GridPlacer.h"
#include "Field/Generator/RandomPlacer.h"
#include "Field/Generator/EventPlacer.h"
#include "Field/Generator/RectPlacer.h"

Game::Game(IApplication* application, std::shared_ptr<World> world)
    : _application(application), _world(std::move(world)) {}

void Game::initialize() {
  _field_changer = std::make_shared<FieldChanger>();
  std::weak_ptr<IGame> weak_this = shared_from_this();
  _event_factory =
      std::make_shared<EventFactory>(_world, _field_changer, weak_this);

  auto money_placer =
      std::make_shared<EventPlacer<MoneyEvent, SimpleRandomizer<75>>>(*_event_factory);
  // GridPlacer<10, 5, EventPlacer<MoneyEvent>, form::Rect<3, 3>> grid_placer{
  //     money_placer};
  // auto generator = FieldGenerator<
  //     GridPlacer<10, 5, EventPlacer<MoneyEvent>, form::Rect<3, 3>>>{};
  // auto field = generator.execute(Size{60, 20}, grid_placer);
  //
  // RandomPlacer<20, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<2, 3>> random_placer{
  //     money_placer};
  // auto generator = FieldGenerator<
  //     RandomPlacer<20, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<2, 3>>>{};
  // auto field = generator.execute(Size{60, 20}, random_placer);
  // _fields = {field};

  RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<1, 1>> random_placer{
      money_placer};
  auto generator = FieldGenerator<
      RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<1, 1>>>{};
  auto field = generator.execute(Size{60, 20}, random_placer);
  _fields = {field};

  _field_changer->setEventFactory(_event_factory);
  _field_changer->setField(field);

  // Systems
  _world->addSystem<MovementSystem>(fields());
  _world->addSystem<DealDamageSystem>();
  _world->addSystem<HealthSystem>();
  _world->addSystem<CleanDeadSystem>(shared_from_this());
  _world->addSystem<AddMoneySystem>();

  // Entities
  auto player = PlayerProvider::create(*_world);
}

const std::vector<std::shared_ptr<Field>>& Game::fields() { return _fields; }

void Game::stop() { _application->quit(); }
