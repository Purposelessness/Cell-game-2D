#ifndef GAME_TEMPLATE_H
#define GAME_TEMPLATE_H


#include <type_traits>

template<template<typename...> class base, typename derived>
struct is_base_of_template_impl {
    template<typename... Ts>
    static constexpr std::true_type check(const base<Ts...> *);
    static constexpr std::false_type check(...);

    using type = decltype(check(std::declval<derived *>()));
};

template<template<typename...> class base, typename derived>
using is_base_of_template = typename is_base_of_template_impl<base, derived>::type;


#endif //GAME_TEMPLATE_H
