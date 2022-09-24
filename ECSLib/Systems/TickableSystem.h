#ifndef GAME_ECSLIB_SYSTEMS_TICKABLESYSTEM_H_
#define GAME_ECSLIB_SYSTEMS_TICKABLESYSTEM_H_

#include "System.h"

class TickableSystem : public System {
public:
    void tick() {
        process();
    }

    void process() override = 0;
};

#endif //GAME_ECSLIB_SYSTEMS_TICKABLESYSTEM_H_