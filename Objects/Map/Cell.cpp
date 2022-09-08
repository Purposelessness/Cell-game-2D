#include "Cell.h"

Cell::Cell() : Cell(nullptr) {}

Cell::Cell(IEventMessage *event) : event(event) {}

void Cell::onPlayerStepped() {
    if (event != nullptr) {
        event->invoke();
    }
}

void Cell::changeEvent(IEventMessage *event) {
    this->event = event;
}
