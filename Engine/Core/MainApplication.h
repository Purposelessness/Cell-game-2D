#ifndef GAME_ENGINE_CORE_MAINAPPLICATION_H_
#define GAME_ENGINE_CORE_MAINAPPLICATION_H_

#include "IApplication.h"
#include "ITickable.h"

class MainApplication : public IApplication {
public:
    MainApplication();

    int execute(int delta_time);

    virtual void update();

    void quit() final;

private:
    bool _is_executing;
};

#endif //GAME_ENGINE_CORE_MAINAPPLICATION_H_