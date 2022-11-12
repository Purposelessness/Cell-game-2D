#include "FieldConfigurator.h"

#include <iostream>

#include "Events/EnemyEvent.h"
#include "Events/EventFactory.h"
#include "Events/ExitEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/MoneyEvent.h"
#include "Field/Generator/EventPlacer.h"
#include "Field/Generator/Form.h"
#include "Field/Generator/GridPlacer.h"
#include "Field/Generator/PassabilityPlacer.h"
#include "Field/Generator/RandomPlacer.h"
#include "Field/Generator/Randomizer.h"
#include "Field/Generator/RectPlacer.h"

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

  // Generate walls
  constexpr int kWChance = 80;
  constexpr int kWXCount = 15;
  constexpr int kWYCount = 9;
  constexpr int kWLength = 3;
  using WallPlacer = PassabilityPlacer<false, SimpleRandomizer<kWChance>>;
  using WallHorizontalLine = form::HorizontalLine<kWLength>;
  using WallGridPlacer =
      GridPlacer<kWXCount, kWYCount, WallPlacer, WallHorizontalLine>;
  auto wall_placer = std::make_shared<WallPlacer>();
  WallGridPlacer wall_grid_placer{wall_placer};

  constexpr int kRWChance = 50;
  constexpr int kRWCount = 5;
  constexpr int kRWWidth = 2;
  constexpr int kRWHeight = 4;
  using RectWallPlacer = PassabilityPlacer<false, SimpleRandomizer<kRWChance>>;
  using RectWall = form::Rect<kRWWidth, kRWHeight>;
  using RectWallRandomPlacer = RandomPlacer<kRWCount, RectWallPlacer, RectWall>;
  auto rect_wall_placer = std::make_shared<RectWallPlacer>();
  RectWallRandomPlacer rwall_random_placer{rect_wall_placer};

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
  ExitRandomPlacer exit_random_placer(exit_placer, true);

  auto generator = FieldGenerator<WallGridPlacer, RectWallRandomPlacer,
                                  GenerateMoneyGridPlacer, MoneyGridPlacer,
                                  EnemyGridPlacer, ExitRandomPlacer>{};
  auto field = generator.execute(
      Size{kWidth, kHeight}, wall_grid_placer, rwall_random_placer,
      gm_grid_placer, m_grid_placer, e_grid_placer, exit_random_placer);

  return field;
}

std::shared_ptr<Field> FieldConfigurator::rectOption() {
  constexpr int kWidth = 60;
  constexpr int kHeight = 30;

  // Generate walls
  constexpr int kWallChance = 70;
  constexpr int kWallWidth = 2;
  using WallPlacer = PassabilityPlacer<false, SimpleRandomizer<kWallChance>>;
  auto wall_placer = std::make_shared<WallPlacer>();

  using WallRectPlacer1 = RectPlacer<6, 4, kWallWidth, WallPlacer>;
  using WallRectPlacer2 = RectPlacer<12, 8, kWallWidth, WallPlacer>;
  using WallRectPlacer3 = RectPlacer<18, 12, kWallWidth, WallPlacer>;
  WallRectPlacer1 wall_rect_placer_1{wall_placer};
  WallRectPlacer2 wall_rect_placer_2{wall_placer};
  WallRectPlacer3 wall_rect_placer_3{wall_placer};

  // Generate money
  constexpr int kMoneyChance = 3;
  constexpr int kMoneyWidth = 2;
  using MoneyPlacer = EventPlacer<MoneyEvent, SimpleRandomizer<kMoneyChance>>;
  auto money_placer = std::make_shared<MoneyPlacer>(*_event_factory);

  using MoneyRectPlacer1 = RectPlacer<8, 6, kMoneyWidth, MoneyPlacer>;
  using MoneyRectPlacer2 = RectPlacer<20, 14, kMoneyWidth, MoneyPlacer>;
  MoneyRectPlacer1 money_rect_placer_1{money_placer};
  MoneyRectPlacer2 money_rect_placer_2{money_placer};

  // Generate enemies
  constexpr int kEnemyChance = 13;
  constexpr int kEnemyWidth1 = 4;
  constexpr int kEnemyWidth2 = 2;
  using EnemyPlacer = EventPlacer<EnemyEvent, SimpleRandomizer<kEnemyChance>>;
  auto enemy_placer = std::make_shared<EnemyPlacer>(*_event_factory);

  using EnemyRectPlacer1 = RectPlacer<1, 0, kEnemyWidth1, EnemyPlacer>;
  using EnemyRectPlacer2 = RectPlacer<14, 10, kEnemyWidth2, EnemyPlacer>;
  EnemyRectPlacer1 enemy_rect_placer_1{enemy_placer};
  EnemyRectPlacer2 enemy_rect_placer_2{enemy_placer};

  // Exit generator
  using ExitGridPlacer =
      GridPlacer<1, 1, EventPlacer<ExitEvent>, form::Rect<4, 4>>;
  auto exit_placer = std::make_shared<EventPlacer<ExitEvent>>(*_event_factory);
  ExitGridPlacer exit_grid_placer(exit_placer);

  // Generator
  auto generator =
      FieldGenerator<WallRectPlacer1, WallRectPlacer2, WallRectPlacer3,
                     MoneyRectPlacer1, MoneyRectPlacer2, EnemyRectPlacer1,
                     EnemyRectPlacer2, ExitGridPlacer>{};
  auto field = generator.execute(
      Size{kWidth, kHeight}, wall_rect_placer_1, wall_rect_placer_2,
      wall_rect_placer_3, money_rect_placer_1, money_rect_placer_2,
      enemy_rect_placer_1, enemy_rect_placer_2, exit_grid_placer);

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
