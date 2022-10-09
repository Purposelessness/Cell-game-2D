#ifndef GAME_UTILITY_METHODCONTAINER_H_
#define GAME_UTILITY_METHODCONTAINER_H_

#include "Template.h"

namespace event_handler {

    class IArguments {
    public:
        virtual ~IArguments() = default;
    };

    template<typename... Args>
    class Arguments : public IArguments {
    public:
        explicit Arguments(Args... args) : tuple(std::make_tuple(std::forward<Args>(args)...)) {}
        std::tuple<Args...> tuple;
    };

    class IMethodContainer {
    public:
        virtual void invoke(IArguments* arguments) = 0;
        virtual ~IMethodContainer() = default;
    };

    template<typename T, typename... Args>
    class MethodContainer : public IMethodContainer {
        using F = void (T::*)(Args...);
        using CorrectArguments = Arguments<Args...>;

    public:
        MethodContainer(T* obj, F func) : _obj(obj), _func(func) {}

        void invoke(IArguments* arguments) override {
            auto args = dynamic_cast<Arguments<remove_cv_reference<Args>...>*>(arguments);
            auto lambda = [obj = _obj, func = _func](Args... args) {
                (obj->*func)(args...);
            };
            std::apply(lambda, args->tuple);
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

}

#endif //GAME_UTILITY_METHODCONTAINER_H_