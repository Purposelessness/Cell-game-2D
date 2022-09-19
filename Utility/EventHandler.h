#ifndef GAME_UTILITY_EVENTHANDLER_H_
#define GAME_UTILITY_EVENTHANDLER_H_

#include <functional>
#include <memory>
#include <vector>
#include <tuple>

#include "MethodContainer.h"
#include "Template.h"

template<typename... Args>
class EventHandler {
public:
    EventHandler& operator+=(std::function<void(Args...)> function) {
        _functions.emplace_back(function);
        return *this;
    }

    EventHandler& operator-=(std::function<void(Args...)> function) {
        for (size_t i = 0; i < _functions.size(); ++i) {
            if (getAddress(_functions[i]) == getAddress(function)) {
                _functions.erase(_functions.begin() + i);
            }
        }
        return *this;
    }

    template<typename T>
    void add(T* obj, void (T::*func)(Args...)) {
        _containers.emplace_back(std::make_unique<event_handler::MethodContainer<T, Args...>>(obj, func));
    }

    template<typename T>
    void add(T* obj, void (T::*func)(const Args&...)) {
        _const_containers.emplace_back(std::make_unique<event_handler::MethodContainer<T, const Args&...>>(obj, func));
    }

    template<typename T>
    void remove(T* obj, void (T::*func)(Args...)) {
        for (size_t i = 0; i < _containers.size(); ++i) {
            auto container = dynamic_cast<event_handler::MethodContainer<T, Args...>*>(_containers[i].get());
            if (container == nullptr)
                continue;
            if (container->getObject() == obj && container->getFunction() == func) {
                _containers.erase(_containers.begin() + i);
                break;
            }
        }
    }

    template<typename T>
    void remove(T* obj, void (T::*func)(const Args&...)) {
        for (size_t i = 0; i < _const_containers.size(); ++i) {
            auto container = dynamic_cast<event_handler::MethodContainer<T, const Args&...>*>(_const_containers[i].get());
            if (container == nullptr)
                continue;
            if (container->getObject() == obj && container->getFunction() == func) {
                _const_containers.erase(_const_containers.begin() + i);
                break;
            }
        }
    }

    void operator()(Args... args) {
        for (const auto& func : _functions) {
            func(args...);
        }
        event_handler::Arguments<Args...> arguments(std::forward<Args>(args)...);
        if (!_containers.empty()) {
            for (const auto& kPtr : _containers) {
                kPtr->invoke(&arguments);
            }
        }
        if (!_const_containers.empty()) {
            for (const auto& kPtr : _const_containers) {
                kPtr->invoke(&arguments);
            }
        }
    }

private:
    std::vector<std::function<void(Args...)>> _functions;
    std::vector<std::unique_ptr<event_handler::IMethodContainer>> _containers;
    std::vector<std::unique_ptr<event_handler::IMethodContainer>> _const_containers;
};

#endif //GAME_UTILITY_EVENTHANDLER_H_