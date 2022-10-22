#ifndef GAME_ECS_MARKERS_INVERTCONTROLMARKER_H_
#define GAME_ECS_MARKERS_INVERTCONTROLMARKER_H_

#include "../../ECSLib/Components/Component.h"

struct InvertControlMarker : public Component {
    InvertControlMarker();

    explicit operator std::string() const override;
};

#endif //GAME_ECS_MARKERS_INVERTCONTROLMARKER_H_