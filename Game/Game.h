#ifndef GAME_GAME_GAME_H_
#define GAME_GAME_GAME_H_

#include <memory>
#include <vector>

#include "Field/Field.h"
#include "Field/FieldGenerator.h"

class World;

class Game {
public:
    explicit Game(std::shared_ptr<World> world);

    const std::vector<std::shared_ptr<Field>>& fields();

private:
    std::shared_ptr<FieldGenerator> _field_generator;
    std::shared_ptr<EventFactory> _event_factory;
    std::vector<std::shared_ptr<Field>> _fields;
};

#endif //GAME_GAME_GAME_H_