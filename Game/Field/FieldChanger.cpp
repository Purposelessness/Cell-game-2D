#include "FieldChanger.h"

#include <memory>

#include "Field.h"
#include "../Events/EventFactory.h"
#include "../Events/MoneyEvent.h"

FieldChanger::FieldChanger() : _event_factory({}), _field(nullptr) {}

void FieldChanger::setEventFactory(std::weak_ptr<EventFactory> event_factory) {
    _event_factory = std::move(event_factory);
}

void FieldChanger::setField(std::shared_ptr<Field> field) {
    _field = std::move(field);
}

void FieldChanger::addMoneyEvents(int money_count) {
    if (_event_factory.expired() || _field == nullptr)
        return;
    auto factory = _event_factory.lock();
    int w, h;
    auto size = (_field->getSize(w, h), w * h);
    auto iter_count = 0;
    auto max_iter_count = size;
    while (money_count > 0 && iter_count < max_iter_count) {
        ++iter_count;
        auto x = std::rand() % w;
        auto y = std::rand() % h;
        auto cell = _field->getCell(x, y);
        if (cell.hasPlayerOn() || cell.getEvent() != nullptr)
            continue;
        _field->setCellEvent(x, y, factory->get<MoneyEvent>());
        --money_count;
    }
}
