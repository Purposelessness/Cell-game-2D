#include "GameInstaller.h"

#include <memory>

#include "../Objects/Field/Field.h"
#include "../Events/EventFactory.h"

void GameInstaller::initialize() {
    _container = di::Container{std::make_shared<Field>(),
                               std::make_shared<EventFactory>(shared_from_this())};
}

template<typename T, typename... Args>
std::shared_ptr<T> GameInstaller::create(Args&& ... args) {
    return _container.template create<T>(std::forward<Args>(args)...);
}

template<typename T>
void GameInstaller::inject(T& obj) {
    _container.template inject(obj);
}
