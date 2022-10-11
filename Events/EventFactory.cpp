#include "EventFactory.h"

template<TEvent T>
std::shared_ptr<T> EventFactory::get() {
    return _game_installer->template create<T>();
}

template<TEvent T>
std::shared_ptr<T> EventFactory::get(const Point& position, int field_index) {
    return _game_installer->template create<T>(position, field_index);
}
