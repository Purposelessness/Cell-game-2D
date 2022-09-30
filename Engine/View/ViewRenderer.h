#ifndef GAME_ENGINE_VIEW_VIEWRENDERER_H_
#define GAME_ENGINE_VIEW_VIEWRENDERER_H_

#include "ViewMessage.h"
#include "../../Utility/Template.h"

template<typename T>
concept TViewRenderer = requires (T t, ViewMessage* view_message) {
    t.update(*view_message);
};

#endif //GAME_ENGINE_VIEW_VIEWRENDERER_H_