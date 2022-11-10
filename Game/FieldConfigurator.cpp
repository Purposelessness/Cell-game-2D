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

std::shared_ptr<Field> FieldConfigurator::execute(
    EventFactory& event_factory) {
  std::cout << "Select field template:\n\t1. Default\n\t2. Rect\n\t3. Chaos\n";
  char c = 0;
  std::cin >> c;

  system("cls");

  switch (c) {
    case '2':
      return std::move(rectOption(event_factory));
    case '3':
      return std::move(chaosOption(event_factory));
    case '1':
    default:
      return std::move(defaultOption(event_factory));
  }
}

std::shared_ptr<Field> FieldConfigurator::defaultOption(
    EventFactory& event_factory) {
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
      std::make_shared<GenerateMoneyEventPlacer>(event_factory);
  GenerateMoneyGridPlacer gm_grid_placer{generate_money_placer};

  // Money events
  constexpr int kMEChance = 20;
  constexpr int kMEXCount = 9;
  constexpr int kMEYCount = 5;
  using MoneyEventPlacer = EventPlacer<MoneyEvent, SimpleRandomizer<kMEChance>>;
  using MoneyGridPlacer = GridPlacer<kMEXCount, kMEYCount, MoneyEventPlacer>;
  auto money_placer = std::make_shared<MoneyEventPlacer>(event_factory);
  MoneyGridPlacer m_grid_placer{money_placer};

  // Enemy events
  constexpr int kEChance = 25;
  constexpr int kEXCount = 12;
  constexpr int kEYCount = 7;
  using EnemyEventPlacer = EventPlacer<EnemyEvent, SimpleRandomizer<kEChance>>;
  using EnemyGridPlacer = GridPlacer<kEXCount, kEYCount, EnemyEventPlacer>;
  auto enemy_placer = std::make_shared<EnemyEventPlacer>(event_factory);
  EnemyGridPlacer e_grid_placer{enemy_placer};

  // Exit event
  using ExitRandomPlacer = RandomPlacer<2, EventPlacer<ExitEvent>>;
  auto exit_placer = std::make_shared<EventPlacer<ExitEvent>>(event_factory);
  ExitRandomPlacer exit_random_placer(exit_placer);

  auto generator = FieldGenerator<GenerateMoneyGridPlacer, MoneyGridPlacer,
                                  EnemyGridPlacer, ExitRandomPlacer>{};
  auto field =
      generator.execute(Size{kWidth, kHeight}, gm_grid_placer, m_grid_placer,
                        e_grid_placer, exit_random_placer);

  return std::move(field);
}

std::shared_ptr<Field> FieldConfigurator::rectOption(
    EventFactory& event_factory) {
  auto field = std::make_shared<Field>(50, 20);
  return std::move(field);
}

std::shared_ptr<Field> FieldConfigurator::chaosOption(
    EventFactory& event_factory) {
  auto field = std::make_shared<Field>(50, 20);
  return std::move(field);

  // RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<1, 1>> random_placer{
  //     money_placer};
  // auto generator = FieldGenerator<
  //     RectPlacer<5, 3, 1, EventPlacer<MoneyEvent, SimpleRandomizer<75>>, form::Rect<1, 1>>>{};
  // auto field = generator.execute(Size{60, 20}, random_placer);
  // _fields = {field};

  // _field_changer->setEventFactory(_event_factory);
  // _field_changer->setField(field);
}
