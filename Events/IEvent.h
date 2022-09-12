#ifndef GAME_IEVENT_H
#define GAME_IEVENT_H


class IEvent {
public:
    virtual void invoke() = 0;
};


#endif //GAME_IEVENT_H
