#ifndef GAME_GAME_FIELD_GENERATOR_FIELDGENERATOR_H_
#define GAME_GAME_FIELD_GENERATOR_FIELDGENERATOR_H_

#include "../../../Utility/Tuple.h"
#include "../Field.h"
#include "Concepts.h"

template <TFieldChanger... Ts>
class FieldGenerator {
 public:
  std::shared_ptr<Field> execute(const Size& field_size, Ts&... changers) {
    std::vector<std::vector<Cell>> cells;
    cells.resize(field_size.y);
    for (auto y = 0; y < field_size.y; ++y) {
      cells[y].resize(field_size.x);
    }

    (changers(cells), ...);
    return std::make_shared<Field>(std::move(cells));
  }
};

#endif
