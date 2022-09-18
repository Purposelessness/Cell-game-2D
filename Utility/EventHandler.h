#ifndef GAME_UTILITY_EVENTHANDLER_H_
#define GAME_UTILITY_EVENTHANDLER_H_

#include <functional>
#include <memory>
#include <vector>
#include <tuple>

#include "Template.h"

class IArguments {
public:
    virtual ~IArguments() = default;
};

template<typename... Args>
class Arguments : public IArguments {
public:
    explicit Arguments(Args... args) : _tuple(std::make_tuple(std::forward<Args>(args)...)) {}
    std::tuple<Args...> _tuple;
};

class IContainer {
public:
    virtual void invoke(IArguments* arguments) = 0;
};

template<typename T, typename... Args>
class Container : public IContainer {
    using F = void (T::*)(Args...);
    using CorrectArguments = Arguments<Args...>;

public:
    Container(T* obj, F func) : _obj(obj), _func(func) {}

    void invoke(IArguments* arguments) override {
        auto args = dynamic_cast<CorrectArguments*>(arguments);
        auto lambda = [obj = _obj, func = _func](Args... args) {
            (obj->*func)(args...);
        };
        std::apply(lambda, std::move(args->_tuple));
    }

    T* getObject() {
        return _obj;
    }

    F getFunction() {
        return _func;
    }

private:
    T* _obj;
    F _func;
};

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
        _containers.emplace_back(std::make_unique<Container<T, Args...>>(obj, func));
    }

    template<typename T>
    void remove(T* obj, void (T::*func)(Args...)) {
        for (size_t i = 0; i < _containers.size(); ++i) {
            auto container = dynamic_cast<Container<T, Args...>*>(_containers[i].get());
            if (container == nullptr)
                continue;
            if (container->getObject() == obj && container->getFunction() == func) {
                _containers.erase(_containers.begin() + i);
                break;
            }
        }
    }

    void operator()(Args... args) {
        for (const auto& func : _functions) {
            func(args...);
        }
        Arguments<Args...> arguments(std::forward<Args>(args)...);
        for (const auto& kPtr : _containers) {
            kPtr->invoke(&arguments);
        }
    }

private:
    std::vector<std::function<void(Args...)>> _functions;
    std::vector<std::unique_ptr<IContainer>> _containers;
};

#endif //GAME_UTILITY_EVENTHANDLER_H_