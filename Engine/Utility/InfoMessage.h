#ifndef GAME_ENGINE_UTILITY_INFOMESSAGE_H_
#define GAME_ENGINE_UTILITY_INFOMESSAGE_H_

#include <type_traits>

#include "../../Utility/IConvertibleToString.h"

struct InfoMessage : public IConvertibleToString {
  explicit operator std::string() const override = 0;
};

template <typename T>
concept TInfoMessage = std::is_base_of_v<InfoMessage, std::remove_cvref_t<T>>;

#endif  // GAME_ENGINE_UTILITY_INFOMESSAGE_H_
