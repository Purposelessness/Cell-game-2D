#ifndef GAME_CORE_VIEW_IMAINAPPLICATION_H_
#define GAME_CORE_VIEW_IMAINAPPLICATION_H_

#include <memory>

class ITickable;
class IDisposable;

class IMainApplication {
public:
    virtual void addTickable(const std::shared_ptr<ITickable>& tickable) = 0;
    virtual void addDisposable(const std::shared_ptr<IDisposable>& disposable) = 0;
};

#endif //GAME_CORE_VIEW_IMAINAPPLICATION_H_