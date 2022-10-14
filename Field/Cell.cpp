#include "Cell.h"

#include <utility>

Cell::Cell() : Cell(true, nullptr) {}

Cell::Cell(std::shared_ptr<IEvent> event) : Cell(true, std::move(event)) {}

Cell::Cell(bool can_be_passed, std::shared_ptr<IEvent> event)
    : _is_passable(can_be_passed), _has_player_on(false), _event(std::move(event)) {}

void Cell::changeEvent(std::shared_ptr<IEvent> event) {
    _event = std::move(event);
}

void Cell::changePassability(bool value) {
    _is_passable = value;
}

void Cell::onPlayerStepped() {
    _has_player_on = true;
    if (_event.get())
        _event->invoke();
}

void Cell::onPlayerLeft() {
    _has_player_on = false;
}

bool Cell::isPassable() const {
    return _is_passable;
}

bool Cell::hasPlayerOn() const {
    return _has_player_on;
}

const std::shared_ptr<IEvent>& Cell::getEvent() const {
    return _event;
}
