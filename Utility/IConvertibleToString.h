#ifndef GAME_UTILITY_ICONVERTIBLETOSTRING_H_
#define GAME_UTILITY_ICONVERTIBLETOSTRING_H_

#include <string>

class IConvertibleToString {
public:
    virtual explicit operator std::string() const = 0;

    auto operator<=>(const IConvertibleToString& other) const = default;
};

template<typename T>
concept ToString = std::is_base_of_v<IConvertibleToString, T>;

#endif //GAME_UTILITY_ICONVERTIBLETOSTRING_H_
