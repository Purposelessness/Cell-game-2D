#ifndef GAME_GAME_SAVECONTROLLER_H_
#define GAME_GAME_SAVECONTROLLER_H_

#include <memory>

#include "Saver.h"

class Field;
class World;
class Cell;
class EventFactory;
struct FieldInfoMessage;
enum class CellView;

class SaveController {
 public:
  void save(const Field& field, World& world) const;
  std::shared_ptr<Field> load(World& world, EventFactory& event_factory);

 private:
  static void generateCell(Cell& cell, CellView type,
                           EventFactory& event_factory);

  Saver _saver;
};

#endif
