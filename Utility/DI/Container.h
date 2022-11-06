#ifndef GAME_UTILITY_DI_CONTAINER_H_
#define GAME_UTILITY_DI_CONTAINER_H_

#include <tuple>

#include "../Template.h"
#include "../Tuple.h"
#include "Helper.h"

namespace di {

template <typename... TServices>
class Container {
  using Types = std::tuple<TServices...>;
  Types _services;

 public:
  Container() = default;

  explicit Container(TServices... services)
      : _services(std::make_tuple(services...)) {}

  template <typename T>
  void addService(T service) {
    std::get<T>(_services) = service;
  }

  template <TInjectClient T, typename... Args>
  std::shared_ptr<T> create(Args&&... args) {
    using MethodArgs =
        typename extract_method_arguments<decltype(&T::inject)>::args_tuple;
    static_assert(has_all_type<Types, MethodArgs>::value);

    auto obj = std::make_shared<T>(std::forward<Args>(args)...);
    inject(*obj);

    return obj;
  }

  template <TInjectClient T>
  void inject(T& obj) {
    using MethodArgs =
        typename extract_method_arguments<decltype(&T::inject)>::args_tuple;
    static_assert(has_all_type<Types, MethodArgs>::value);

    MethodArgs services_to_inject;
    Tuple::forEach(services_to_inject, [services = _services](auto& service) {
      service = std::get<std::decay_t<decltype(service)>>(services);
    });

    auto inject_lambda = [&obj]<typename... InjectArgs>(InjectArgs&&... args) {
      obj.inject(std::move(args)...);
    };
    std::apply(inject_lambda, std::move(services_to_inject));
  }
};

}  // namespace di

#endif  // GAME_UTILITY_DI_CONTAINER_H_
