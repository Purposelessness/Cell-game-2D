#ifndef GAME_GAME_FIELD_GENERATOR_CONCEPTS_H_
#define GAME_GAME_FIELD_GENERATOR_CONCEPTS_H_

#include <vector>

#include "../../../Datatypes/Point.h"
#include "../Cell.h"

struct FieldChangerInput {
  std::vector<std::vector<Cell>>& cells;
  Point position;
};

template <typename T>
concept TFieldChanger =
    requires(T t) { t(std::declval<std::vector<std::vector<Cell>>&>()); };

template <typename T>
concept TCellChanger = requires(T t) { t(std::declval<Cell&>()); };

#endif
