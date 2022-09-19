#include "Cell.h"

#include <utility>


Cell::Cell() : Cell(nullptr) {}

Cell::Cell(std::shared_ptr<IEvent> event) : _event(std::move(event)) {}

void Cell::changeEvent(std::shared_ptr<IEvent> event) {
    this->_event = std::move(event);
}

void Cell::onPlayerStepped() {
    _event->invoke();
}
