#ifndef GAME_GAME_EVENTS_EVENTFACTORY_H_
#define GAME_GAME_EVENTS_EVENTFACTORY_H_

#include <memory>

#include "Event.h"

#include "../../Utility/DI/Container.h"

class World;

class FieldGenerator;

class EventFactory {
    using DiContainer = di::Container<World, FieldGenerator>;

public:
    template<typename... Ts>
    explicit EventFactory(std::shared_ptr<Ts>... services);

    template<typename T>
    void addService(std::shared_ptr<T> service);

    template<typename T, typename... Args>
    std::shared_ptr<T> addServices(Args&& ... args);

    template<TEvent T, typename... Args>
    std::shared_ptr<T> get(Args&& ... args);

    template<typename T>
    void inject(T& obj);

private:
    DiContainer _container;
};

template<typename... Ts>
EventFactory::EventFactory(std::shared_ptr<Ts>... services) : _container({std::move(services)}...) {}

template<typename T>
void EventFactory::addService(std::shared_ptr<T> service) {
    _container.template addService(std::move(service));
}

template<typename T, typename... Args>
std::shared_ptr<T> EventFactory::addServices(Args&& ... args) {
    return _container.template addService(std::forward<Args>(args)...);
}

template<TEvent T, typename... Args>
std::shared_ptr<T> EventFactory::get(Args&& ... args) {
    if constexpr (di::TInjectClient<T>) {
        return _container.template create<T>(std::forward<Args>(args)...);
    } else {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

template<typename T>
void EventFactory::inject(T& obj) {
    _container.template inject(obj);
}

#endif //GAME_GAME_EVENTS_EVENTFACTORY_H_