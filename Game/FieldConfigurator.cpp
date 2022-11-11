#include "FieldConfigurator.h"

#include <iostream>

#include "Events/EnemyEvent.h"
#include "Events/EventFactory.h"
#include "Events/ExitEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/MoneyEvent.h"
#include "Field/Generator/EventPlacer.h"
#include "Field/Generator/GridPlacer.h"
#include "Field/Generator/RandomPlacer.h"
#include "Field/Generator/Randomizer.h"

FieldConfigurator::FieldConfigurator(
    std::shared_ptr<EventFactory> event_factory)
    : _event_factory(std::move(event_factory)), _option(Default) {}

std::shared_ptr<Field> FieldConfigurator::execute() {
  std::cout << "Select field template:\n\t1. Default\n\t2. Rect\n\t3. Chaos\n";
  char c = 0;
  std::cin >> c;

  switch (c) {
    case '2':
      _option = Rect;
      break;
    case '3':
      _option = Chaos;
      break;
    case '1':
    default:
      _option = Default;
      break;
  }

  return generate();
}

std::shared_ptr<Field> FieldConfigurator::generate() {
  switch (_option) {
    case Rect:
      return rectOption();
    case Chaos:
      return chaosOption();
      break;
    case Default:
    default:
      return defaultOption();
  }
}

std::shared_ptr<Field> FieldConfigurator::defaultOption() {
  constexpr int kWidth = 60;
  constexpr int kHeight = 20;

  // Generate money events
  constexpr int kGMEChance = 20;
  constexpr int kGMEXCount = 5;
  constexpr int kGMEYCount = 5;
  using GenerateMoneyEventPlacer =
      EventPlacer<GenerateMoneyEvent, SimpleRandomizer<kGMEChance>>;
  using GenerateMoneyGridPlacer =
      GridPlacer<kGMEXCount, kGMEYCount, GenerateMoneyEventPlacer>;
  auto generate_money_placer =
      std::make_shared<GenerateMoneyEventPlacer>(*_event_factory);
  GenerateMoneyGridPlacer gm_grid_placer{generate_money_placer};

  // Money events
  constexpr int kMEChance = 20;
  constexpr int kMEXCount = 9;
  constexpr int kMEYCount = 5;
  using MoneyEventPlacer = EventPlacer<MoneyEvent, SimpleRandomizer<kMEChance>>;
  using MoneyGridPlacer = GridPlacer<kMEXCount, kMEYCount, MoneyEventPlacer>;
  auto money_placer = std::make_shared<MoneyEventPlacer>(*_event_factory);
  MoneyGridPlacer m_grid_placer{money_placer};

  // Enemy events
  constexpr int kEChance = 25;
  constexpr int kEXCount = 12;
  constexpr int kEYCount = 7;
  using EnemyEventPlacer = EventPlacer<EnemyEvent, SimpleRandomizer<kEChance>>;
  using EnemyGridPlacer = GridPlacer<kEXCount, kEYCount, EnemyEventPlacer>;
  auto enemy_placer = std::make_shared<EnemyEventPlacer>(*_event_factory);
  EnemyGridPlacer e_grid_placer{enemy_placer};

  // Exit event
  using ExitRandomPlacer = RandomPlacer<2, EventPlacer<ExitEvent>>;
  auto exit_placer = std::make_shared<EventPlacer<ExitEvent>>(*_event_factory);
  ExitRandomPlacer exit_random_placer(exit_placer);

  auto generator = FieldGenerator<GenerateMoneyGridPlacer, MoneyGridPlacer,
                                  EnemyGridPlacer, ExitRandomPlacer>{};
  auto field =
      generator.execute(Size{kWidth, kHeight}, gm_grid_placer, m_grid_placer,
                        e_grid_placer, exit_random_placer);

  return field;
}

std::shared_ptr<Field> FieldConfigurator::rectOption() {
  auto field = std::make_shared<Field>(50, 20);
  return field;
}

std::shared_ptr<Field> FieldConfigurator::chaosOption() {
  auto field = std::make_shared<Field>(50, 20);
  return field;

  // RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>,
  // form::Rect<1, 1>> random_placer{
  //     money_placer};
  // auto generator = FieldGenerator<
  //     RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>,
  //     form::Rect<1, 1>>>{};
  // auto field = generator.execute(Size{60, 20}, random_placer);
  // _fields = {field};

  // _field_changer->setEventFactory(_event_factory);
  // _field_changer->setField(field);
}
