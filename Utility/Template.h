#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
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
struct are_same_sized;

template<typename... Ts, typename... Us>
struct are_same_sized<std::tuple<Ts...>, std::tuple<Us...>> : all_true<is_same<Ts, Us>...> {};

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

template<typename T1, typename T2>
struct recursion_call {
    template<size_t I>
    using is_same = std::is_same<
        extract_tuple_type_by_index<I, T1>,
        extract_tuple_type_by_index<I, T2>>;

    template<size_t I>
    constexpr static bool value() {
        return is_same<I>::value && recursion_call::value<I-1>();
    }

    template<>
    constexpr static bool value<0>() {
        return is_same<0>::value;
    }
};

template<typename Tuple1, typename Tuple2>
struct are_same {
    static constexpr size_t arg_count = std::tuple_size_v<Tuple1>;

    static constexpr bool result = recursion_call<Tuple1, Tuple2>::template value<arg_count>();
};

struct are_same_arguments {
    template<typename F1, typename F2>
    static constexpr bool value(F1 f1, F2 f2) {
        return are_same<
            extract_method_arguments<decltype(f1)>::args_tuple,
            extract_method_arguments<decltype(f2)>::args_tuple>::result
    }
};

#endif //GAME_UTILITY_TEMPLATE_H_
#pragma clang diagnostic pop