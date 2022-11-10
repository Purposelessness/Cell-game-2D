#ifndef GAME_GAME_FIELD_GENERATOR_GRIDPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_GRIDPLACER_H_

#include <cmath>
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
    auto height = static_cast<float>(cells.size());
    // auto y_space = (height - YCount) / (YCount + 1);
    auto y_space = height / (YCount + 1);
    auto width = static_cast<float>(cells[0].size());
    // auto x_space = (width - XCount) / (XCount + 1);
    auto x_space = width / (XCount + 1);
    FieldChangerInput input{cells, Point{0, 0}};
    float y = y_space;
    for (int y_i = 0; y_i < YCount; ++y_i) {
      auto new_y = static_cast<int>(std::round(y));
      input.position.y = new_y >= height ? new_y - 1 : new_y;
      float x = x_space;
      for (int x_i = 0; x_i < XCount; ++x_i) {
        auto new_x = static_cast<int>(std::round(x));
        input.position.x = new_x >= width ? new_x - 1 : new_x;
        _form(*_changer, input);
        x += x_space;
      }
      y += y_space;
    }
  }

 private:
  std::shared_ptr<T> _changer;
  Form _form;
};

#endif
