#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
#ifndef GAME_UTILITY_CONCEPTS_H_
#define GAME_UTILITY_CONCEPTS_H_

#include <type_traits>

template<typename T>
concept TMethod = std::is_member_function_pointer_v<T>;

template<typename T>
concept TFunc = std::is_function_v<typename std::remove_pointer<T>::type>;

template<typename T>
struct is_tuple : std::false_type {};

template<typename... Ts>
struct is_tuple<std::tuple<Ts...>> : std::true_type {};

template<typename T>
static constexpr bool is_tuple_v = is_tuple<T>::value;

template<typename T>
concept TTuple = is_tuple_v<T>;

#endif //GAME_UTILITY_CONCEPTS_H_
#pragma clang diagnostic pop