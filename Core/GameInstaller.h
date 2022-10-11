#ifndef GAME_CORE_GAMEINSTALLER_H_
#define GAME_CORE_GAMEINSTALLER_H_

#include "../Utility/DI/Container.h"

class Field;
class EventFactory;

class GameInstaller {
    using DiServiceContainer = di::Container<Field, EventFactory>;

public:
    GameInstaller();

    template<typename T, typename... Args>
    std::shared_ptr<T> create(Args&&... args);

    template<typename T>
    void inject(T& obj);

private:
    DiServiceContainer _container;
};

#endif //GAME_CORE_GAMEINSTALLER_H_