#ifndef GAME_CELL_H
#define GAME_CELL_H


#include <memory>
#include "../../Events/IEvent.h"

class Cell {
public:
    Cell();
    explicit Cell(std::shared_ptr<IEvent> event);

    void changeEvent(std::shared_ptr<IEvent> event);
    void onPlayerStepped();

private:
    std::shared_ptr<IEvent> event;
};


#endif //GAME_CELL_H
