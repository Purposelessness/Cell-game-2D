#ifndef GAME_UTILITY_ICONVERTIBLETOSTRING_H_
#define GAME_UTILITY_ICONVERTIBLETOSTRING_H_

#include <string>

class IConvertibleToString {
public:
    [[nodiscard]] virtual std::string toString() = 0;
};

template<typename T>
concept ToString = std::is_base_of_v<IConvertibleToString, T>;

#endif //GAME_UTILITY_ICONVERTIBLETOSTRING_H_
