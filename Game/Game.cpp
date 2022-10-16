#include "Game.h"

#include <utility>

#include "../Core/IApplication.h"

#include "../Utility/Log.h"

#include "Events/EventFactory.h"

#include "Events/ControlInversionEvent.h"
#include "Events/MoneyEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/EnemyEvent.h"
#include "../ECS/Systems/HealthSystem.h"
#include "../ECS/Systems/CleanDeadSystem.h"
#include "Events/ExitEvent.h"

Game::Game(IApplication* application, std::shared_ptr<World> world)
    : _application(application), _world(std::move(world)) {}

void Game::initialize() {
    _field_generator = std::make_shared<FieldGenerator>();
    _event_factory = std::make_shared<EventFactory>(_world, _field_generator);

    auto field = std::make_shared<Field>();
    for (int i = 0; i < 20; ++i) {
        field->setCellEvent({11, i}, _event_factory->get<ControlInversionEvent>());
        field->setCellEvent({18, i}, _event_factory->get<MoneyEvent>());
        field->setCellEvent({5, i}, _event_factory->get<GenerateMoneyEvent>());
        field->setCellEvent({37, i}, _event_factory->get<EnemyEvent>());
    }
    auto exit = _event_factory->get<ExitEvent>();
    exit->setGame(shared_from_this());
    field->setCellEvent({30, 10}, exit);

    for (int i = 0; i < 10; ++i) {
        field->setCellPassability({17, i}, false);
    }
    _fields = {field};

    _field_generator->setEventFactory(_event_factory);
    _field_generator->setField(field);

    _world->addSystem<HealthSystem>();
    _world->addSystem<CleanDeadSystem>(shared_from_this());
}

const std::vector<std::shared_ptr<Field>>& Game::fields() {
    return _fields;
}

void Game::stop() {
    _application->quit();
}
