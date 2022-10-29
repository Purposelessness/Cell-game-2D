#include "Game.h"

#include <utility>

#include "../Core/IApplication.h"

#include "Events/EventFactory.h"

#include "Events/ControlInversionEvent.h"
#include "Events/MoneyEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/EnemyEvent.h"
#include "../ECS/Systems/HealthSystem.h"
#include "../ECS/Systems/CleanDeadSystem.h"
#include "Events/ExitEvent.h"
#include "../ECS/Systems/DealDamageSystem.h"
#include "../ECS/Systems/AddMoneySystem.h"
#include "../ECS/Systems/MovementSystem.h"
#include "../ECS/EntityProviders/PlayerProvider.h"

Game::Game(IApplication* application, std::shared_ptr<World> world)
    : _application(application), _world(std::move(world)) {}

void Game::initialize() {
    _field_changer = std::make_shared<FieldChanger>();
    std::weak_ptr<IGame> weak_this = shared_from_this();
    _event_factory = std::make_shared<EventFactory>(_world, _field_changer, weak_this);

    auto field = std::make_shared<Field>();
    for (int i = 0; i < 20; ++i) {
        field->setCellEvent(Point{11, i}, _event_factory->get<ControlInversionEvent>());
        field->setCellEvent(Point{18, i}, _event_factory->get<MoneyEvent>());
        field->setCellEvent(Point{5, i}, _event_factory->get<GenerateMoneyEvent>());
        field->setCellEvent(Point{37, i}, _event_factory->get<EnemyEvent>());
    }
    auto exit = _event_factory->get<ExitEvent>();
    field->setCellEvent(Point{30, 10}, exit);

    for (int i = 0; i < 10; ++i) {
        field->setCellPassability(Point{17, i}, false);
    }
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

const std::vector<std::shared_ptr<Field>>& Game::fields() {
    return _fields;
}

void Game::stop() {
    _application->quit();
}
