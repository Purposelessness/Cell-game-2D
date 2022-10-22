#ifndef GAME_ENGINE_VIEW_VIEWMESSAGE_H_
#define GAME_ENGINE_VIEW_VIEWMESSAGE_H_

#include <type_traits>

#include "../../Utility/Template.h"
#include "../../Utility/IConvertibleToString.h"

struct ViewMessage : public IConvertibleToString {
    explicit operator std::string() const override = 0;
};

template<typename T>
concept TViewMessage = std::is_base_of_v<ViewMessage, remove_cv_reference<T>>;

#endif //GAME_ENGINE_VIEW_VIEWMESSAGE_H_