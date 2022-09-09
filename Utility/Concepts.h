#ifndef GAME_CONCEPTS_H
#define GAME_CONCEPTS_H


#include <type_traits>

template<typename T>
concept Func = std::is_member_function_pointer_v<T>;


#endif //GAME_CONCEPTS_H
