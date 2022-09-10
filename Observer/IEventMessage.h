#ifndef GAME_IEVENTMESSAGE_H
#define GAME_IEVENTMESSAGE_H


#include <string>

class IEventMessage {
public:
    virtual std::string getName() = 0;
    virtual int getValue() = 0;
};


#endif //GAME_IEVENTMESSAGE_H
