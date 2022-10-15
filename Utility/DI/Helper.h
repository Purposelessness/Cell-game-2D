#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
#ifndef GAME_UTILITY_DI_HELPER_H_
#define GAME_UTILITY_DI_HELPER_H_

#include <memory>
#include <tuple>

namespace di {

    template<typename T>
    concept TInjectClient = requires (T t) {
        &T::inject;
    };

    namespace details {
        template<typename Tuple, typename OutTuple>
        struct shared_ptr_tuple_impl;

        template<template<typename...> class Tuple, typename T, template<typename...> class OutTuple, typename... OutArgs>
        struct shared_ptr_tuple_impl<Tuple<T>, OutTuple<OutArgs...>> {
            using type = OutTuple<OutArgs..., std::shared_ptr<T>>;
        };

        template<template<typename...> class Tuple, typename... Args, typename T, template<typename...> class OutTuple, typename... OutArgs>
        struct shared_ptr_tuple_impl<Tuple<T, Args...>, OutTuple<OutArgs...>> {
            using type = typename shared_ptr_tuple_impl<Tuple<Args...>, OutTuple<OutArgs..., std::shared_ptr<T>>>::type;
        };

    }

    template<typename Tuple>
    struct shared_ptr_tuple;

    template<template<typename...> class Tuple, typename... Args>
    struct shared_ptr_tuple<Tuple<Args...>> {
        using type = typename details::shared_ptr_tuple_impl<Tuple<Args...>, std::tuple<>>::type;
    };

} // di


#endif //GAME_UTILITY_DI_HELPER_H_
#pragma clang diagnostic pop