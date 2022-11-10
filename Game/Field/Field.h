#ifndef GAME_GAME_FIELD_FIELD_H_
#define GAME_GAME_FIELD_FIELD_H_

#include <memory>
#include <vector>

#include "../../Datatypes/Point.h"
#include "../../Datatypes/Size.h"
#include "../../Utility/EventHandler.h"
#include "Cell.h"
#include "FieldEventMessage.h"

class Field {
 public:
  Field();
  explicit Field(std::vector<std::vector<Cell>>&& cells);
  explicit Field(const Size& size);
  explicit Field(int width, int height);
  Field(const Field& other);
  Field(Field&& other) noexcept;

  Field& operator=(Field other);
  Field& operator=(Field&& other) noexcept;

  bool operator==(const Field& other) const;
  std::vector<Cell>& operator[](int row);

  void getSize(int& width, int& height) const;
  [[nodiscard]] Size getSize() const;

  [[nodiscard]] const Cell& getCell(int x, int y) const;
  [[nodiscard]] const Cell& getCell(const Point& point) const;

  void onPlayerStepped(const Point& point);
  void onPlayerLeft(const Point& point);

  void setCellEvent(int x, int y, std::shared_ptr<IEvent> event);
  void setCellEvent(const Point& point, std::shared_ptr<IEvent> event);

  void setCellPassability(const Point& point, bool value);

  [[nodiscard]] bool isPointPassable(const Point& point) const;

  [[nodiscard]] bool isPointValid(int x, int y) const;
  [[nodiscard]] bool isPointValid(const Point& point) const;

  [[nodiscard]] Point normalizePoint(const Point& point) const;

  EventHandler<FieldEventMessage> event_handler;

 private:
  void swap(Field& other);

  Size _size;
  std::vector<std::vector<Cell>> _cells;
  Cell _empty_cell{};
};

#endif  // GAME_GAME_FIELD_FIELD_H_
