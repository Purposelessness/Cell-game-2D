#include "Cell.h"

Cell::Cell() : Cell(nullptr) {}

Cell::Cell(IEvent *event) : event(event) {}

void Cell::onPlayerStepped() {
    if (event != nullptr) {
        event->invoke();
    }
}

void Cell::changeEvent(IEvent *event) {
    this->event = event;
}
