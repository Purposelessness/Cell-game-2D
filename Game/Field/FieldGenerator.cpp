#include "FieldGenerator.h"
#include "../Events/MoneyEvent.h"

#include <utility>

FieldGenerator::FieldGenerator() : _event_factory({}), _field(nullptr) {}

void FieldGenerator::setEventFactory(std::weak_ptr<EventFactory> event_factory) {
    _event_factory = std::move(event_factory);
}

void FieldGenerator::setField(std::shared_ptr<Field> field) {
    _field = std::move(field);
}

void FieldGenerator::addMoneyEvents(int max_count) {
    if (_event_factory.expired() || _field == nullptr)
        return;
    auto factory = _event_factory.lock();
    auto count = std::rand() % max_count;
    int w, h;
    auto size = (_field->getSize(w, h), w * h);
    auto iter_count = 0;
    auto max_iter_count = size;
    while (count < max_count && iter_count < max_iter_count) {
        ++iter_count;
        auto x = std::rand() % w;
        auto y = std::rand() % h;
        auto cell = _field->getCell(x, y);
        if (cell.hasPlayerOn() || cell.getEvent() != nullptr)
            continue;
        _field->setCellEvent(x, y, factory->get<MoneyEvent>());
        ++count;
    }
}
