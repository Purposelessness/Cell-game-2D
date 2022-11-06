#ifndef GAME_GAME_EVENTS_EVENTFACTORY_H_
#define GAME_GAME_EVENTS_EVENTFACTORY_H_

#include <memory>

#include "../../Utility/DI/Container.h"
#include "FieldEvent.h"
#include "WorldEvent.h"

class World;
class FieldChanger;
class IGame;

class EventFactory {
  using DiContainer = di::Container<std::weak_ptr<IGame>>;

 public:
  template <typename... Ts>
  EventFactory(std::shared_ptr<World> world,
               std::shared_ptr<FieldChanger> field_generator, Ts&&... services);

  template <typename T>
  void addService(std::shared_ptr<T> service);

  template <typename T, typename... Args>
  std::shared_ptr<T> addServices(Args&&... args);

  template <TEvent T>
  std::shared_ptr<T> get();

  template <TEvent T>
  void inject(T& event);

  void setWorld(std::shared_ptr<World> world);
  void setFieldChanger(std::shared_ptr<FieldChanger> field_changer);

 private:
  DiContainer _container;
  std::shared_ptr<World> _world;
  std::shared_ptr<FieldChanger> _field_changer;
};

template <typename... Ts>
EventFactory::EventFactory(std::shared_ptr<World> world,
                           std::shared_ptr<FieldChanger> field_generator,
                           Ts&&... services)
    : _container({std::forward<Ts>(services)}...), _world(std::move(world)),
      _field_changer(std::move(field_generator)) {}

template <typename T>
void EventFactory::addService(std::shared_ptr<T> service) {
  _container.template addService(std::move(service));
}

template <typename T, typename... Args>
std::shared_ptr<T> EventFactory::addServices(Args&&... args) {
  return _container.template addService(std::forward<Args>(args)...);
}

template <TEvent T>
std::shared_ptr<T> EventFactory::get() {
  auto event = std::make_shared<T>();
  inject(*event);
  return event;
}

template <TEvent T>
void EventFactory::inject(T& event) {
  if constexpr (std::is_base_of_v<WorldEvent, T>) {
    event.setWorld(_world);
  }
  if constexpr (std::is_base_of_v<FieldEvent, T>) {
    event.setFieldChanger(_field_changer);
  }

  if constexpr (di::TInjectClient<T>) {
    _container.template inject(event);
  }
}

#endif  // GAME_GAME_EVENTS_EVENTFACTORY_H_
