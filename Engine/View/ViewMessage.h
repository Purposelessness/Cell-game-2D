#ifndef GAME_ENGINE_VIEW_VIEWMESSAGE_H_
#define GAME_ENGINE_VIEW_VIEWMESSAGE_H_

#include <type_traits>
#include "../../Utility/IConvertibleToString.h"

struct ViewMessage {
    std::string information;
};

template<typename T>
concept TViewMessage = std::is_base_of_v<ViewMessage, T>;

#endif //GAME_ENGINE_VIEW_VIEWMESSAGE_H_
