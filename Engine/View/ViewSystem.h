#ifndef GAME_ENGINE_VIEW_VIEWSYSTEM_H_
#define GAME_ENGINE_VIEW_VIEWSYSTEM_H_

#include <vector>
#include <tuple>

#include "../../Utility/Tuple.h"
#include "ViewRenderer.h"

template<TViewRenderer... Args>
class ViewSystem {
public:
    explicit ViewSystem(Args*... args) {
        _types = std::make_tuple(args...);
    }

    template<TViewMessage T>
    void render(T&& message) {
        Tuple::forEach(_types, [message=std::forward<T>(message)](TViewRenderer auto* t) {
            t->update(message);
        });
    }

private:
    std::tuple<Args*...> _types;
};

#endif //GAME_ENGINE_VIEW_VIEWSYSTEM_H_