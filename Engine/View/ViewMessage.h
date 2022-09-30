#ifndef GAME_ENGINE_VIEW_VIEWMESSAGE_H_
#define GAME_ENGINE_VIEW_VIEWMESSAGE_H_

#include <type_traits>
#include "../../Utility/IConvertibleToString.h"
#include "../../Utility/Template.h"

struct ViewMessage {
    std::string information;
};

template<typename T>
concept TViewMessage = std::is_base_of_v<ViewMessage, remove_cv_reference<T>>;

#endif //GAME_ENGINE_VIEW_VIEWMESSAGE_H_
