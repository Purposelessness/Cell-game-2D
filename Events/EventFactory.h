#ifndef GAME_EVENTS_EVENTFACTORY_H_
#define GAME_EVENTS_EVENTFACTORY_H_

#include <vector>
#include <memory>

#include "Event.h"
#include "../Datatypes/Point.h"
#include "../Core/GameInstaller.h"

class EventFactory {
public:
    template<TEvent T>
    std::shared_ptr<T> get();

    template<TEvent T>
    std::shared_ptr<T> get(const Point& position, int field_index = 0);

private:
    std::shared_ptr<GameInstaller> _game_installer;
};

#endif //GAME_EVENTS_EVENTFACTORY_H_