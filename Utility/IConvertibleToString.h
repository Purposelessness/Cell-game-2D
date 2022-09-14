#ifndef GAME_ICONVERTIBLETOSTRING_H
#define GAME_ICONVERTIBLETOSTRING_H


#include <string>

class IConvertibleToString {
public:
    [[nodiscard]] virtual std::string toString() = 0;
};

template<typename T>
concept ToString = std::is_base_of_v<IConvertibleToString, T>;


#endif //GAME_ICONVERTIBLETOSTRING_H
