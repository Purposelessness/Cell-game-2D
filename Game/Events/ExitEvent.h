#ifndef GAME_GAME_EVENTS_EXITEVENT_H_
#define GAME_GAME_EVENTS_EXITEVENT_H_

#include <memory>

#include "WorldEvent.h"
#include "../IGame.h"

class ExitEvent : public WorldEvent {
public:
    ExitEvent() = default;
    explicit ExitEvent(std::weak_ptr<IGame> game);

//    void inject(std::weak_ptr<IGame> game);
    void invoke() override;
    void setGame(std::weak_ptr<IGame> game);

private:
    std::weak_ptr<IGame> _game;
    int _win_money = 10;
};

#endif //GAME_GAME_EVENTS_EXITEVENT_H_