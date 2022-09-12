#include "Cell.h"

#include <utility>


Cell::Cell() : Cell(nullptr) {}

Cell::Cell(std::shared_ptr<IEvent> event) : event(std::move(event)) {}

void Cell::changeEvent(std::shared_ptr<IEvent> event) {
    this->event = std::move(event);
}

void Cell::onPlayerStepped() {
    event->invoke();
}
