#ifndef GAME_GAME_FIELD_GENERATOR_COLUMNPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_COLUMNPLACER_H_

#include <utility>

#include "Concepts.h"

template <TCellChanger T, int Column = 0, int Count = 0>
class ColumnPlacer {
 public:
  void operator()(std::vector<std::vector<Cell>>& cells) {
    auto height = static_cast<int>(cells.size());
    auto space = height / (Count + 1);
    for (auto y = space; y < height; y += space) {
      _changer(cells[y][Column]);
    }
  }

 private:
  T _changer{};
};

#endif
