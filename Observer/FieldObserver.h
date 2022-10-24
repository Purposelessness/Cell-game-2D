#ifndef GAME_OBSERVER_FIELDOBSERVER_H_
#define GAME_OBSERVER_FIELDOBSERVER_H_

#include <memory>
#include <utility>

#include "../Utility/IDisposable.h"
#include "../Game/Field/FieldEventMessage.h"
#include "../View/FieldViewMessage.h"
#include "../Game/Field/Field.h"

#include "../View/CellViewRecognizer.h"
#include "../Utility/Tuple.h"

template<typename T>
concept TFieldObserverClient = requires(T t) {
    t << std::declval<FieldViewMessage>();
};

template<TFieldObserverClient... Ts>
class FieldObserver : public IDisposable {
public:
    explicit FieldObserver(std::shared_ptr<Field> field, std::shared_ptr<Ts>... clients);
    ~FieldObserver() override;

    FieldObserver<Ts...>& operator<<(const Field& field);

    void react(const FieldEventMessage& message);

    void setObservableField(std::shared_ptr<Field> field);

private:
    void notifyClients(const FieldViewMessage& message);

    std::shared_ptr<Field> _field;
    std::tuple<std::shared_ptr<Ts>...> _clients;
};

template<TFieldObserverClient... Ts>
FieldObserver<Ts...>::FieldObserver(std::shared_ptr<Field> field, std::shared_ptr<Ts>... clients)
    : _field(std::move(field)), _clients(std::make_tuple(std::move(clients)...)) {
    _field->event_handler.template add(this, &FieldObserver::react);
    this->operator<<(*_field);
}

template<TFieldObserverClient... Ts>
FieldObserver<Ts...>::~FieldObserver() {
    _field->event_handler.template remove(this, &FieldObserver::react);
}

template<TFieldObserverClient... Ts>
FieldObserver<Ts...>& FieldObserver<Ts...>::operator<<(const Field& field) {
    std::vector<std::pair<Point, CellView>> cells;
    int width, height;
    _field->getSize(width, height);
    cells.reserve(width * height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            auto point = Point{i, j};
            cells.emplace_back(point, CellViewRecognizer::use(_field->getCell(point)));
        }
    }
    notifyClients(FieldViewMessage{cells, Size{width, height}});
    return *this;
}

template<TFieldObserverClient... Ts>
void FieldObserver<Ts...>::react(const FieldEventMessage& message) {
    std::vector<std::pair<Point, CellView>> cells;
    cells.emplace_back(std::pair<Point, CellView>{message.position,
                                                  CellViewRecognizer::use(_field->getCell(message.position))});
    notifyClients(FieldViewMessage{cells});
}

template<TFieldObserverClient... Ts>
void FieldObserver<Ts...>::setObservableField(std::shared_ptr<Field> field) {
    if (_field != nullptr)
        _field->event_handler.template remove(this, &FieldObserver::react);
    _field = std::move(field);
    _field->event_handler.template add(this, &FieldObserver::react);
}

template<TFieldObserverClient... Ts>
void FieldObserver<Ts...>::notifyClients(const FieldViewMessage& message) {
    Tuple::forEach(_clients, [&message]<TFieldObserverClient T>(std::shared_ptr<T>& client) {
        *client << message;
    });
}

#endif //GAME_OBSERVER_FIELDOBSERVER_H_