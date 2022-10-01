#ifndef GAME_CORE_IAPPLICATION_H_
#define GAME_CORE_IAPPLICATION_H_

#include <memory>

class ITickable;
class IDisposable;

class IApplication {
public:
    virtual void addTickable(const std::shared_ptr<ITickable>& tickable) = 0;
    virtual void addDisposable(const std::shared_ptr<IDisposable>& disposable) = 0;
    virtual void quit() = 0;
};

#endif //GAME_CORE_IAPPLICATION_H_