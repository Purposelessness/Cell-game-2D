#ifndef GAME_OBJECTS_MAP_CELL_H_
#define GAME_OBJECTS_MAP_CELL_H_

#include <memory>
#include "../../Events/IEvent.h"

class Cell {
public:
    Cell();
    explicit Cell(std::shared_ptr<IEvent> event);

    void changeEvent(std::shared_ptr<IEvent> event);
    void onPlayerStepped();

    auto operator<=>(const Cell&) const = default;

private:
    std::shared_ptr<IEvent> _event;
};

#endif //GAME_OBJECTS_MAP_CELL_H_
