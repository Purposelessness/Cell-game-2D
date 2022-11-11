#include "FieldChanger.h"

#include <ctime>
#include <memory>

#include "../Events/EventFactory.h"
#include "../Events/MoneyEvent.h"
#include "Field.h"
#include "../../Utility/Log/Log.h"

FieldChanger::FieldChanger() : _field(nullptr) {
  std::srand(std::time(nullptr));
}

void FieldChanger::setEventFactory(std::weak_ptr<EventFactory> event_factory) {
  _event_factory = std::move(event_factory);
}

void FieldChanger::setField(std::shared_ptr<Field> field) {
  _field = std::move(field);
}

void FieldChanger::addMoneyEvents(int money_count) {
  if (_event_factory.expired() || _field == nullptr) {
    return;
  }
  auto factory = _event_factory.lock();
  int w = 0;
  int h = 0;
  auto size = (_field->getSize(w, h), w * h);
  auto iter_count = 0;
  auto max_iter_count = size;
  while (money_count > 0 && iter_count < max_iter_count) {
    ++iter_count;
    auto x = std::rand() % w;
    auto y = std::rand() % h;
    auto cell = _field->getCell(x, y);
    if (cell.hasPlayerOn() || !cell.isPassable() ||
        cell.getEvent() != nullptr) {
      continue;
    }
    _field->setCellEvent(x, y, factory->get<MoneyEvent>());
    --money_count;
  }
}
