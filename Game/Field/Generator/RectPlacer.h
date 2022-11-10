#ifndef GAME_GAME_FIELD_GENERATOR_DIAGONALPLACER_H_
#define GAME_GAME_FIELD_GENERATOR_DIAGONALPLACER_H_

#include <memory>
#include <utility>

#include "../../../Utility/Log/Log.h"
#include "Concepts.h"
#include "Form.h"

template <int XOffset, int YOffset, int Width, TCellChanger T,
          TForm<T> Form = form::Rect<1, 1>>
class RectPlacer {
 public:
  explicit RectPlacer(std::shared_ptr<T> changer)
      : _changer(std::move(changer)) {}

  void operator()(std::vector<std::vector<Cell>>& cells) {
    auto width = static_cast<int>(cells[0].size());
    auto height = static_cast<int>(cells.size());
    if (XOffset + Width >= width || YOffset + Width >= height) {
      LOG_ERROR_F("Field size is too small for rect placer.");
      return;
    }

    for (int i = 0; i < Width; ++i) {
      fillRect(cells, XOffset + i, YOffset + i);
    }
  }

 private:
  inline void fillRect(std::vector<std::vector<Cell>>& cells, int x_offset,
                       int y_offset) {
    auto width = static_cast<int>(cells[0].size()) - x_offset;
    auto height = static_cast<int>(cells.size()) - y_offset;
    FieldChangerInput input{cells, Point{0, 0}};

    input.position.y = y_offset;
    for (int x = x_offset; x < width; ++x) {
      input.position.x = x;
      _form(*_changer, input);
    }

    for (int y = y_offset + 1; y < height - 2; ++y) {
      input.position.y = y;
      input.position.x = x_offset;
      _form(*_changer, input);
      input.position.x = width - 1;
      _form(*_changer, input);
    }

    input.position.y = height - 1;
    for (int x = x_offset; x < width; ++x) {
      input.position.x = x;
      _form(*_changer, input);
    }
  }

  std::shared_ptr<T> _changer;
  Form _form;
};

#endif
