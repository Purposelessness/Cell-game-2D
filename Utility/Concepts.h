#ifndef GAME_UTILITY_CONCEPTS_H_
#define GAME_UTILITY_CONCEPTS_H_


#include <type_traits>

template<typename T>
concept Method = std::is_member_function_pointer_v<T>;

template<typename T>
concept Func = std::is_function_v<typename std::remove_pointer<T>::type>;


#endif //GAME_UTILITY_CONCEPTS_H_
