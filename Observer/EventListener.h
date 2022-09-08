#ifndef GAME_EVENTLISTENER_H
#define GAME_EVENTLISTENER_H


#include <vector>

#include "EventType.h"

class EventListener {
public:
    EventListener();
    [[nodiscard]] int getIndex() const;

    virtual void update(EventType e) = 0;

    ~EventListener();

private:
    void assignIndex();

    static int length;
    static std::vector<int> unusedIndices;
    
    int index = -1;
};


#endif //GAME_EVENTLISTENER_H