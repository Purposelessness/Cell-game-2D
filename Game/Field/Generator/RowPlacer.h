#ifndef GAME_GAME_FIELD_GENERATOR_ROWPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_ROWPLACER_H_

#include <utility>

#include "Concepts.h"

template <TCellChanger T, int Row = 0, int Count = 0>
class RowPlacer {
 public:
  void operator()(std::vector<std::vector<Cell>>& cells) {
    auto width = static_cast<int>(cells[0].size());
    auto space = width / (Count + 1);
    for (auto x = space; x < width; x += space) {
      _changer(cells[Row][x]);
    }
  }

 private:
  T _changer{};
};

#endif
