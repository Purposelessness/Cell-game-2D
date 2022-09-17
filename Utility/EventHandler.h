#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H


#include <functional>
#include <vector>

template<typename... Args>
class EventHandler {
public:
    EventHandler &operator+=(std::function<void(Args...)> function) {
        functions.emplace_back(std::move(function));
        return *this;
    }

    EventHandler &operator-=(std::function<void(Args...)> function) {
        functions.erase(function);
        return *this;
    }

    void operator()(Args... args) {
        for (const auto &func : functions) {
            func(args...);
        }
    }

private:
    std::vector<std::function<void(Args...)>> functions;
};



#endif //GAME_EVENTHANDLER_H