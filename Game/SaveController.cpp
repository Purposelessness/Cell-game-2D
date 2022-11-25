#include "SaveController.h"

#include <utility>

#include "../ECS/Components/Health.h"
#include "../ECS/Components/Intelligence.h"
#include "../ECS/Components/Money.h"
#include "../ECS/Components/Transform.h"
#include "../ECS/Components/Weapon.h"
#include "../ECS/Markers/PlayerMarker.h"
#include "../ECSLib/Core/Filter.h"
#include "../Utility/Log/Log.h"
#include "Events/ControlInversionEvent.h"
#include "Events/EnemyEvent.h"
#include "Events/EventFactory.h"
#include "Events/ExitEvent.h"
#include "Events/GenerateMoneyEvent.h"
#include "Events/MoneyEvent.h"
#include "Field/FieldHelper.h"

void SaveController::save(const Field& field, World& world) const {
  auto filter = Filter::with<PlayerMarker, Health, Money, Transform, Weapon,
                             Intelligence>(world);
  if (filter.empty()) {
    LOG_ERROR_F("No player found while saving");
    return;
  }
  auto player = filter.at(0);

  int health = player.getComponent<Health>().value;
  int money = player.getComponent<Money>().value;
  Point position = player.getComponent<Transform>().position;
  int weapon = player.getComponent<Weapon>().damage;
  int intelligence = player.getComponent<Intelligence>().value;
  PlayerInfoMessage player_info{health, money, position, weapon, intelligence};

  GameState game_state{FieldHelper::info(field), player_info};
  try {
    _saver.save(game_state);
  } catch (const SaverException& e) {
    LOG_ERROR_F("Saver error: " + std::string(e.what()));
    return;
  }
  LOG_INFO_F("Game saved");
}

std::shared_ptr<Field> SaveController::load(World& world,
                                            EventFactory& event_factory) {
  GameState game_state;
  try {
    game_state = _saver.load();
  } catch (const SaverException& e) {
    LOG_ERROR_F("Saver error: " + std::string(e.what()));
    return nullptr;
  }
  auto& field_info = game_state.field_info;
  auto& player_info = game_state.player_info;

  auto filter = Filter::with<PlayerMarker, Health, Money, Transform, Weapon,
                             Intelligence>(world);
  if (filter.empty()) {
    LOG_ERROR_F("No player found while loading");
    return nullptr;
  }
  auto player = filter.at(0);

  player.getComponent<Health>().value = player_info.health;
  player.getComponent<Money>().value = player_info.money;
  player.getComponent<Transform>().position = player_info.position;
  player.getComponent<Weapon>().damage = player_info.weapon;
  player.getComponent<Intelligence>().value = player_info.intelligence;

  std::vector<std::vector<Cell>> cells;
  auto& size = field_info.size;
  auto& changes = field_info.changes;
  cells.resize(size.y);
  for (int j = 0; j < size.y; ++j) {
    cells[j].resize(size.x);
    for (int i = 0; i < size.x; ++i) {
      generateCell(cells[j][i], changes[j * size.x + i].second, event_factory);
    }
  }
  auto field = std::make_shared<Field>(std::move(cells));
  field->onPlayerStepped(player_info.position);

  LOG_INFO_F("Game loaded");
  LOG_INFO_F("Health = " + std::to_string(player_info.health));
  LOG_INFO_F("Money = " + std::to_string(player_info.money));
  LOG_INFO_F("Weapon damage = " + std::to_string(player_info.weapon));
  LOG_INFO_F("Intelligence = " + std::to_string(player_info.intelligence));

  return field;
}

void SaveController::generateCell(Cell& cell, CellView type,
                                  EventFactory& event_factory) {
  switch (type) {
    case CellView::Wall:
      cell.changePassability(false);
      break;
    case CellView::ControlInversion:
      cell.changeEvent(event_factory.get<ControlInversionEvent>());
      break;
    case CellView::Money:
      cell.changeEvent(event_factory.get<MoneyEvent>());
      break;
    case CellView::Enemy:
      cell.changeEvent(event_factory.get<EnemyEvent>());
      break;
    case CellView::Exit:
      cell.changeEvent(event_factory.get<ExitEvent>());
      break;
    case CellView::GenerateMoney:
      cell.changeEvent(event_factory.get<GenerateMoneyEvent>());
      break;
    case CellView::Player:
    case CellView::Empty:
    case CellView::Undefined:
    default:
      break;
  }
}
