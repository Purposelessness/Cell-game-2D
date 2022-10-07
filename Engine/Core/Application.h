#ifndef GAME_ENGINE_CORE_APPLICATION_H_
#define GAME_ENGINE_CORE_APPLICATION_H_

#include "ITickable.h"

class Application {
public:
    Application();

    int execute(int delta_time);

    virtual void tick();

    void quit();

private:
    bool _is_executing;
};

#endif //GAME_ENGINE_CORE_APPLICATION_H_