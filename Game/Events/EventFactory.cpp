#include "EventFactory.h"

#include <utility>

template<typename... Ts>
EventFactory::EventFactory(std::shared_ptr<Ts>... services) : _container({std::move(services)...}) {}

template<TEvent T, typename... Args>
std::shared_ptr<T> EventFactory::get(Args&& ... args) {
    return _container.template create<T>(std::forward<Args>(args)...);
}

template<typename T>
void EventFactory::inject(T& obj) {
    _container.template inject(obj);
}

template<typename T>
void EventFactory::addService(std::shared_ptr<T> service) {
    _container.template addService(std::move(service));
}

template<typename T, typename... Args>
std::shared_ptr<T> EventFactory::addServices(Args&& ... args) {
    return _container.template addService(std::forward<Args>(args)...);
}
