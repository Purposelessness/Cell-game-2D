#ifndef GAME_ENGINE_VIEW_VIEWRENDERER_H_
#define GAME_ENGINE_VIEW_VIEWRENDERER_H_

#include "../Utility/InfoMessage.h"

template <typename T>
concept TViewRenderer = requires(T t) { t << std::declval<InfoMessage>(); };

#endif