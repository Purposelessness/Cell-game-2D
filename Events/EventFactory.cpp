#include "EventFactory.h"

#include <utility>

EventFactory::EventFactory(std::shared_ptr<GameInstaller> game_installer)
    : _game_installer(std::move(game_installer)) {}

template<TEvent T>
std::shared_ptr<T> EventFactory::get() {
    return _game_installer->template create<T>();
}

template<TEvent T>
std::shared_ptr<T> EventFactory::get(const Point& position, int field_index) {
    return _game_installer->template create<T>(position, field_index);
}

void EventFactory::setInstaller(std::shared_ptr<GameInstaller> game_installer) {
    _game_installer = std::move(game_installer);
}
