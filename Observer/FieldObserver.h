#ifndef GAME_OBSERVER_FIELDOBSERVER_H_
#define GAME_OBSERVER_FIELDOBSERVER_H_

#include <memory>
#include <utility>

#include "../Game/Field/Field.h"
#include "../Game/Field/FieldEventMessage.h"
#include "../Utility/IDisposable.h"
#include "../Utility/Log/Log.h"
#include "../Utility/Tuple.h"
#include "../View/CellViewRecognizer.h"

template <typename T>
concept TFieldObserverClient =
    requires(T t) { t << std::declval<FieldInfoMessage>(); };

class IFieldObserver {
 public:
  virtual ~IFieldObserver() = default;
  virtual void setObservableField(std::shared_ptr<Field> field) = 0;
};

template <TFieldObserverClient... Ts>
class FieldObserver : public IFieldObserver {
 public:
  explicit FieldObserver(std::shared_ptr<Field> field,
                         std::shared_ptr<Ts>... clients);
  ~FieldObserver() override;

  FieldObserver<Ts...>& operator<<(const Field& field);

  void react(const FieldEventMessage& message);

  void setObservableField(std::shared_ptr<Field> field) override;

 private:
  void notifyClients(const FieldInfoMessage& message);

  std::shared_ptr<Field> _field;
  std::tuple<std::shared_ptr<Ts>...> _clients;
};

template <TFieldObserverClient... Ts>
FieldObserver<Ts...>::FieldObserver(std::shared_ptr<Field> field,
                                    std::shared_ptr<Ts>... clients)
    : _field(std::move(field)),
      _clients(std::make_tuple(std::move(clients)...)) {
  _field->event_handler.template add(this, &FieldObserver::react);
  this->operator<<(*_field);
}

template <TFieldObserverClient... Ts>
FieldObserver<Ts...>::~FieldObserver() {
  _field->event_handler.template remove(this, &FieldObserver::react);
}

template <TFieldObserverClient... Ts>
FieldObserver<Ts...>& FieldObserver<Ts...>::operator<<(const Field& field) {
  std::vector<std::pair<Point, CellView>> cells;
  int width = 0;
  int height = 0;
  field.getSize(width, height);
  cells.reserve(width * height);
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      auto point = Point{i, j};
      cells.emplace_back(point, CellViewRecognizer::use(field.getCell(point)));
    }
  }
  Size size{width, height};
  notifyClients(FieldInfoMessage{cells, size});
  LOG_INFO_F("Field size is " + std::string(size));
  return *this;
}

template <TFieldObserverClient... Ts>
void FieldObserver<Ts...>::react(const FieldEventMessage& message) {
  std::vector<std::pair<Point, CellView>> cells;
  cells.emplace_back(message.position, CellViewRecognizer::use(
                                           _field->getCell(message.position)));
  notifyClients(FieldInfoMessage{cells});
  if (message.type != FieldEventMessage::PlayerLeft) {
    LOG_TRACE_F(static_cast<std::string>(message));
  }
}

template <TFieldObserverClient... Ts>
void FieldObserver<Ts...>::setObservableField(std::shared_ptr<Field> field) {
  if (_field != nullptr) {
    _field->event_handler.template remove(this, &FieldObserver::react);
  }
  _field = std::move(field);
  _field->event_handler.template add(this, &FieldObserver::react);
  this->operator<<(*_field);
}

template <TFieldObserverClient... Ts>
void FieldObserver<Ts...>::notifyClients(const FieldInfoMessage& message) {
  Tuple::forEach(
      _clients, [&message]<TFieldObserverClient T>(std::shared_ptr<T>& client) {
        *client << message;
      });
}

#endif  // GAME_OBSERVER_FIELDOBSERVER_H_
