#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
#pragma ide diagnostic ignored "NotImplementedFunctions"
#ifndef GAME_UTILITY_TEMPLATE_H_
#define GAME_UTILITY_TEMPLATE_H_

#include <type_traits>
#include <functional>
#include <tuple>
#include <memory>

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

template<TTuple T, TTuple U> requires (std::tuple_size_v<T> == std::tuple_size_v<U>)
struct of_same_size<T, U> : std::true_type {};

template<TTuple T, TTuple U>
inline constexpr bool of_same_size_v = of_same_size<T, U>::value;

/// has_type\<T, Tuple\> — if Tuple contains type T
template<typename T, typename Tuple>
struct has_type;

template<typename T>
struct has_type<T, std::tuple<>> : std::false_type {};

template<typename T, typename U, typename... Args>
struct has_type<T, std::tuple<U, Args...>> : has_type<T, std::tuple<Args...>> {};

template<typename T, typename... Args>
struct has_type<T, std::tuple<T, Args...>> : std::true_type {};

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

/// Push `T` type to `Tuple` tuple
template<typename Tuple, typename T>
struct tuple_push;

template<template<typename...> class Tuple, typename... Args, typename T>
struct tuple_push<Tuple<Args...>, T> {
    using type = Tuple<Args..., T>;
};

/// Create tuple with unique_ptr from another tuple
namespace details {
    template<typename Tuple, typename OutTuple>
    struct unique_ptr_tuple_impl;

    template<template<typename...> class Tuple, typename T, template<typename...> class OutTuple, typename... OutArgs>
    struct unique_ptr_tuple_impl<Tuple<T>, OutTuple<OutArgs...>> {
        using type = OutTuple<OutArgs..., std::unique_ptr<T>>;
    };

    template<template<typename...> class Tuple, typename... Args, typename T, template<typename...> class OutTuple, typename... OutArgs>
    struct unique_ptr_tuple_impl<Tuple<T, Args...>, OutTuple<OutArgs...>> {
        using type = typename unique_ptr_tuple_impl<Tuple<Args...>, OutTuple<OutArgs..., std::unique_ptr<T>>>::type;
    };

}

template<typename Tuple>
struct unique_ptr_tuple;

template<template<typename...> class Tuple, typename... Args>
struct unique_ptr_tuple<Tuple<Args...>> {
    using type = typename details::unique_ptr_tuple_impl<Tuple<Args...>, std::tuple<>>::type;
};

template<typename T>
struct remove_smart_pointer {
    using type = T;
};

template<typename T>
struct remove_smart_pointer<std::shared_ptr<T>> {
    using type = T;
};

template<typename T>
struct remove_smart_pointer<std::unique_ptr<T>> {
    using type = T;
};

template<typename T>
struct remove_smart_pointer<std::decay<std::weak_ptr<T>>> {
    using type = T;
};

/// If tuple `TTuple` contains type `T`
template<typename TTuple, typename T>
struct has_type;

template<typename T>
struct has_type<std::tuple<>, T> : std::false_type {};

template<typename T, typename U, typename... Args>
struct has_type<std::tuple<U, Args...>, T> : has_type<std::tuple<Args...>, T> {};

template<typename T, typename... Args>
struct has_type<std::tuple<T, Args...>, T> : std::true_type {};

namespace details {
    template<typename T1, typename T2>
    struct has_all_type_impl;

    template<typename... Args, typename T>
    struct has_all_type_impl<std::tuple<Args...>, std::tuple<T>> : has_type<std::tuple<Args...>, typename remove_smart_pointer<T>::type> {};

    template<typename... Args, typename T, typename... Ts>
    struct has_all_type_impl<std::tuple<Args...>, std::tuple<T, Ts...>> : std::false_type {};

    template<typename... Args, typename T, typename... Ts> requires (has_type<std::tuple<Args...>, typename remove_smart_pointer<T>::type>::value)
    struct has_all_type_impl<std::tuple<Args...>, std::tuple<T, Ts...>> : has_all_type_impl<std::tuple<Args...>, std::tuple<Ts...>>{};
}

template<typename TTuple, typename Ts>
struct has_all_type : std::false_type {};

template<typename... Args, typename... Ts>
struct has_all_type<std::tuple<Args...>, std::tuple<Ts...>> : details::has_all_type_impl<std::tuple<Args...>, std::tuple<Ts...>> {};

#endif //GAME_UTILITY_TEMPLATE_H_
#pragma clang diagnostic pop