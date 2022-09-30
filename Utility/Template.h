#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
#pragma ide diagnostic ignored "NotImplementedFunctions"
#ifndef GAME_UTILITY_TEMPLATE_H_
#define GAME_UTILITY_TEMPLATE_H_

#include <type_traits>
#include <functional>
#include <tuple>

#include "Concepts.h"

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

template<typename T, typename U>
using is_base_of = std::is_base_of<remove_cv_reference<T>, remove_cv_reference<U>>;

namespace detail {
    template<bool...>
    struct bool_pack;
    template<bool... bs>
    using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;
}

template<typename... Ts>
using all_true = detail::all_true<Ts::value...>;

template<typename T, typename U>
struct are_same;

template<typename... Ts, typename... Us>
struct are_same<std::tuple<Ts...>, std::tuple<Us...>> : all_true<is_same<Ts, Us>...> {};

template<typename T, typename U>
struct are_base_of : std::false_type {};

template<typename... Ts, typename U>
struct are_base_of<std::tuple<Ts...>, U> : all_true<is_base_of<U, Ts>...> {};

template<typename T, typename U>
inline constexpr bool are_base_of_v = are_base_of<T, U>::value;

template<typename T, typename U>
struct of_same_size : std::false_type {};

template<TTuple T, TTuple U>
requires (std::tuple_size_v<T> == std::tuple_size_v<U>)
struct of_same_size<T, U> : std::true_type {};

template<TTuple T, TTuple U>
inline constexpr bool of_same_size_v = of_same_size<T, U>::value;

template<typename... Args>
struct extract_method_arguments {};

template<typename T, typename... Args>
using F = void (T::*)(Args...);

template<typename T>
struct extract_method_arguments<F<T>> {
    using args_tuple = std::tuple<void>;

    template<size_t I>
    using get_arg_type = void;
};

template<size_t I, typename Tuple>
struct extract_tuple_type_by_index {
    using value = std::tuple_element_t<I, Tuple>;
};

template<typename T, typename... Args>
struct extract_method_arguments<F<T, Args...>> {
    static constexpr size_t arg_count = sizeof...(Args);

    using args_tuple = std::tuple<Args...>;

    template<size_t I>
    using get_arg_type = typename extract_tuple_type_by_index<I, args_tuple>::value;
};

#endif //GAME_UTILITY_TEMPLATE_H_
#pragma clang diagnostic pop