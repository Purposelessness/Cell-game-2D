#ifndef GAME_ENGINE_CORE_APPLICATION_H_
#define GAME_ENGINE_CORE_APPLICATION_H_

#include "IApplication.h"
#include "ITickable.h"

class Application : public IApplication {
public:
    Application();

    int execute(int delta_time);

    virtual void update();

    void quit() final;

private:
    bool _is_executing;
};

#endif //GAME_ENGINE_CORE_APPLICATION_H_