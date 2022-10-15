#ifndef GAME_BRIDGES_FIELDVIEWBRIDGE_H_
#define GAME_BRIDGES_FIELDVIEWBRIDGE_H_

#include <type_traits>
#include <utility>

#include "../Utility/EventHandler.h"
#include "../Utility/IDisposable.h"

#include "../View/CellViewRecognizer.h"
#include "../View/FieldViewMessage.h"

#include "../Game/Field/FieldEventMessage.h"
#include "../Game/Field/Cell.h"

template<typename T>
concept TObservableField = requires(T t, int a, int b) {
    { t.event_handler } -> std::convertible_to<EventHandler<FieldEventMessage>>;
    { t.getCell(std::declval<Point>()) } -> std::convertible_to<Cell>;
    t.getSize(a, b);
};

template<typename T>
concept TFieldRenderer = requires(T t) {
    t.update(std::declval<FieldViewMessage>());
};

template<TFieldRenderer T, TObservableField F>
class FieldViewBridge : public IDisposable {
public:
    FieldViewBridge(std::shared_ptr<T> renderer, std::shared_ptr<F> field);
    ~FieldViewBridge() override;

    void react(const FieldEventMessage& message);

    void setObservableField(std::shared_ptr<F> field);

private:
    std::shared_ptr<T> _renderer;
    std::shared_ptr<F> _field;
};

template<TFieldRenderer T, TObservableField F>
FieldViewBridge<T, F>::FieldViewBridge(std::shared_ptr<T> renderer, std::shared_ptr<F> field)
    : _renderer(std::move(renderer)), _field(std::move(field)) {
    _field->event_handler.template add(this, &FieldViewBridge<T, F>::react);

    std::vector<std::pair<Point, CellView>> cells;
    int width, height;
    _field->getSize(width, height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            auto point = Point{i, j};
            cells.emplace_back(point, CellViewRecognizer::use(_field->getCell(point)));
        }
    }
    _renderer->update(FieldViewMessage{cells, Size{width, height}});
}

template<TFieldRenderer T, TObservableField F>
FieldViewBridge<T, F>::~FieldViewBridge() {
    _field->event_handler.template remove(this, &FieldViewBridge<T, F>::react);
}

template<TFieldRenderer T, TObservableField F>
void FieldViewBridge<T, F>::react(const FieldEventMessage& message) {
    std::vector<std::pair<Point, CellView>> cells;
    for (const auto& kPoint : message.information) {
        cells.emplace_back(std::pair<Point, CellView>{kPoint, CellViewRecognizer::use(_field->getCell(kPoint))});
    }
    _renderer->update(FieldViewMessage{cells});
}

template<TFieldRenderer T, TObservableField F>
void FieldViewBridge<T, F>::setObservableField(std::shared_ptr<F> field) {
    _field->event_handler.remove(this, &FieldViewBridge<T, F>::react);
    _field = std::move(field);
    _field->event_handler.add(this, &FieldViewBridge<T, F>::react);
}

#endif //GAME_BRIDGES_FIELDVIEWBRIDGE_H_