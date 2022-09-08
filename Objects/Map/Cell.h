#ifndef GAME_CELL_H
#define GAME_CELL_H


#include "../../Observer/Events/IEventMessage.h"

class Cell {
public:
    Cell();
    explicit Cell(IEventMessage *event);

    void changeEvent(IEventMessage *event);
    void onPlayerStepped();

private:
    IEventMessage *event;
};


#endif //GAME_CELL_H
