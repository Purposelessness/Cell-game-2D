#ifndef GAME_ENGINE_VIEW_VIEWSYSTEM_H_
#define GAME_ENGINE_VIEW_VIEWSYSTEM_H_

#include <vector>
#include <tuple>

#include "../../Utility/Tuple.h"
#include "ViewRenderer.h"

template<TViewRenderer... Args>
class ViewSystem {
public:
    template<TViewMessage T>
    void render(const T& message) {
        Tuple::forEach(_types, [message](TViewRenderer auto t) {
            t.update(message);
        });
    }

private:
    std::tuple<Args...> _types;
};

#endif //GAME_ENGINE_VIEW_VIEWSYSTEM_H_