#ifndef GAME_GAME_FIELD_GENERATOR_GRIDPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_GRIDPLACER_H_

#include <utility>

#include "Concepts.h"
#include "Form.h"

template <int XCount, int YCount, TCellChanger T,
          TForm<T> Form = form::Rect<1, 1>>
class GridPlacer {
 public:
  explicit GridPlacer(std::shared_ptr<T> changer)
      : _changer(std::move(changer)) {}

  void operator()(std::vector<std::vector<Cell>>& cells) {
    auto height = static_cast<int>(cells.size());
    auto y_space = (height - YCount) / (YCount + 1);
    y_space = y_space == 0 ? 1 : y_space;
    auto width = static_cast<int>(cells[0].size());
    auto x_space = (width - XCount) / (XCount + 1);
    x_space = x_space == 0 ? 1 : x_space;
    FieldChangerInput input{cells, Point{0, 0}};
    for (auto y = y_space; y < height; y += y_space) {
      input.position.y = y;
      for (auto x = x_space; x < width; x += x_space) {
        input.position.x = x;
        _form(*_changer, input);
      }
    }
  }

 private:
  std::shared_ptr<T> _changer;
  Form _form;
};

#endif
