#ifndef GAME_CORE_GAMEINSTALLER_H_
#define GAME_CORE_GAMEINSTALLER_H_

#include "../Utility/DI/Container.h"

class Field;
class EventFactory;

class GameInstaller : public std::enable_shared_from_this<GameInstaller> {
    using DiContainer = di::Container<Field, EventFactory>;

public:
    void initialize();

    template<typename T, typename... Args>
    std::shared_ptr<T> create(Args&&... args);

    template<typename T>
    void inject(T& obj);

private:
    DiContainer _container;
};

#endif //GAME_CORE_GAMEINSTALLER_H_