#ifndef GAME_ENGINE_VIEW_VIEWSYSTEM_H_
#define GAME_ENGINE_VIEW_VIEWSYSTEM_H_

#include <memory>
#include <vector>
#include <tuple>
#include <unordered_map>

#include "../../Utility/IDisposable.h"
#include "../../Utility/Tuple.h"
#include "../../Utility/Template.h"
#include "ViewRenderer.h"

template<TViewRenderer... Ts>
class ViewSystem : public IDisposable {
    using Types = std::tuple<Ts...>;

public:
    template<TViewRenderer T, typename... Args> requires(has_type<T, Types>::value)
    void addRenderer(Args&&... args) {
        auto& ptr = std::get<std::unique_ptr<T>>(_renderers);
        if (!ptr.get())
            ptr = std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<TViewRenderer T> requires(has_type<T, Types>::value)
    void addRenderer(std::unique_ptr<T>
    && renderer) {
        auto& ptr = std::get<std::unique_ptr<T>>(_renderers);
        if (ptr.get()) {
            ptr.reset();
        }
        ptr = std::move(renderer);
    }

    template<TViewRenderer T>
    requires(has_type<T, Types>::value)
    void removeRenderer() {
        std::get<std::unique_ptr<T>>(_renderers).reset();
    }

    template<TViewMessage T>
    void render(T&& message) {
        Tuple::forEach(_renderers, [message = std::forward<T>(message)](auto& t) -> void {
            if (t == nullptr)
                return;
            t->update(message);
        });
    }

    ~ViewSystem() override = default;

private:
    std::tuple<std::unique_ptr<Ts>...> _renderers;
};

#endif //GAME_ENGINE_VIEW_VIEWSYSTEM_H_