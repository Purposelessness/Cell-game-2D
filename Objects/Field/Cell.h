#ifndef GAME_OBJECTS_FIELD_CELL_H_
#define GAME_OBJECTS_FIELD_CELL_H_

#include <memory>

#include "../../Events/IEvent.h"

class Cell {
public:
    Cell();
    explicit Cell(std::shared_ptr<IEvent> event);
    explicit Cell(bool can_be_passed, std::shared_ptr<IEvent> event);

    void changeEvent(std::shared_ptr<IEvent> event);
    void changePassability(bool value);
    void onPlayerStepped();
    void onPlayerLeft();

    [[nodiscard]] bool isPassable() const;
    [[nodiscard]] bool hasPlayerOn() const;

    auto operator<=>(const Cell&) const = default;

private:
    bool _is_passable;
    bool _has_player_on;
    std::shared_ptr<IEvent> _event;
};

#endif //GAME_OBJECTS_FIELD_CELL_H_
