#ifndef GAME_GAME_FIELD_GENERATOR_RANDOMPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_RANDOMPLACER_H_

#include <ctime>
#include <random>
#include <utility>

#include "Concepts.h"
#include "Form.h"

template <int Count, TCellChanger T, TForm<T> Form = form::Rect<1, 1>>
class RandomPlacer {
 public:
  explicit RandomPlacer(std::shared_ptr<T> changer, bool safe_search = false)
      : _safe_search(safe_search), _changer(std::move(changer)) {
    std::srand(std::time(nullptr));
  }

  void operator()(std::vector<std::vector<Cell>>& cells) {
    int i = 0;
    int height = static_cast<int>(cells.size());
    int width = static_cast<int>(cells[0].size());
    Point position{0, 0};
    FieldChangerInput input{cells, position};
    while (i < Count) {
      input.position.x = std::rand() % width;
      input.position.y = std::rand() % height;
      if (_safe_search &&
          !cells[input.position.y][input.position.x].isPassable()) {
        continue;
      }
      _form(*_changer, input);
      ++i;
    }
  }

 private:
  bool _safe_search;
  std::shared_ptr<T> _changer;
  Form _form;
};

#endif
