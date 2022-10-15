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
    std::shared_ptr<T> addServices(Args&&... args);

    template<TEvent T, typename... Args>
    std::shared_ptr<T> get(Args&& ... args);

    template<typename T>
    void inject(T& obj);

private:
    DiContainer _container;
};

#endif //GAME_GAME_EVENTS_EVENTFACTORY_H_