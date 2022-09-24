#ifndef GAME_ECS_COMPONENTS_CONTROLLABLEMARKER_H_
#define GAME_ECS_COMPONENTS_CONTROLLABLEMARKER_H_

#include "../../ECSLib/Components/Component.h"

struct ControllableMarker : public Component {
    ControllableMarker();

    std::string toString() override;
};

#endif //GAME_ECS_COMPONENTS_CONTROLLABLEMARKER_H_