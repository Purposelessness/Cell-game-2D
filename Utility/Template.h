#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
#ifndef GAME_UTILITY_TEMPLATE_H_
#define GAME_UTILITY_TEMPLATE_H_

#include <type_traits>
#include <functional>

template<template<typename...> class base, typename derived>
struct is_base_of_template_impl {
    template<typename... Ts>
    static constexpr std::true_type check(const base<Ts...>*);
    static constexpr std::false_type check(...);

    using type = decltype(check(std::declval<derived*>()));
};

template<template<typename...> class base, typename derived>
using is_base_of_template = typename is_base_of_template_impl<base, derived>::type;

template<typename T, typename... U>
long getAddress(std::function<T(U...)> func) {
    return *reinterpret_cast<long*>(reinterpret_cast<char*>(&func));
}

#endif //GAME_UTILITY_TEMPLATE_H_
#pragma clang diagnostic pop