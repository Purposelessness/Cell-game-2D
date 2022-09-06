#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "../../Events/IEvent.h"

class Cell {
public:
    Cell();
    explicit Cell(IEvent *event);

    void changeEvent(IEvent *event);
    void onPlayerStepped();

private:
    IEvent *event;
};

#endif //GAME_CELL_H
