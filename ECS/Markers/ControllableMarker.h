#ifndef GAME_ECS_MARKERS_CONTROLLABLEMARKER_H_
#define GAME_ECS_MARKERS_CONTROLLABLEMARKER_H_

#include "../../ECSLib/Components/Component.h"

struct ControllableMarker : public Component {
    ControllableMarker();

    explicit operator std::string() const override;
};

#endif //GAME_ECS_MARKERS_CONTROLLABLEMARKER_H_