#ifndef GAME_ECS_MARKERS_PLAYERMARKER_H_
#define GAME_ECS_MARKERS_PLAYERMARKER_H_

#include "../../ECSLib/Components/Component.h"

struct PlayerMarker : public Component {
public:
    explicit PlayerMarker();

    [[nodiscard]] std::string toString() const override;
};

#endif //GAME_ECS_MARKERS_PLAYERMARKER_H_