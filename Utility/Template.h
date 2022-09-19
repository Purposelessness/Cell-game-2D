#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"
#ifndef GAME_UTILITY_TEMPLATE_H_
#define GAME_UTILITY_TEMPLATE_H_

#include <type_traits>
#include <functional>
#include <tuple>

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

template<typename T>
using remove_cv_reference = std::remove_cv_t<std::remove_reference_t<T>>;

template<typename T, typename U>
using is_same = std::is_same<remove_cv_reference<T>, remove_cv_reference<U>>;

namespace detail {
    template<bool...>
    struct bool_pack;
    template<bool... bs>
    using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;
}
template<typename... Ts>
using all_true = detail::all_true<Ts::value...>;

template<typename TTuple, typename UTuple>
struct are_same;

template<typename... Ts, typename... Us>
struct are_same<std::tuple<Ts...>, std::tuple<Us...>> : all_true<is_same<Ts, Us>...> {};

#endif //GAME_UTILITY_TEMPLATE_H_
#pragma clang diagnostic pop