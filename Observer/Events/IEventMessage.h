#ifndef GAME_IEVENTMESSAGE_H
#define GAME_IEVENTMESSAGE_H


#include <string>

class IEventMessage {
public:
    virtual void invoke() const = 0;
    virtual std::string getName() = 0;
};


#endif //GAME_IEVENTMESSAGE_H
