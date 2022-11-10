#ifndef GAME_GAME_FIELD_GENERATOR_FORM_H_
#define GAME_GAME_FIELD_GENERATOR_FORM_H_

#include "Concepts.h"
#include "FieldGenerator.h"

template <typename T, typename Changer>
concept TForm = requires { TCellChanger<Changer>; } and
                requires(T t) {
                  t(std::declval<const Changer&>(), std::declval<FieldChangerInput&>());
                };

namespace form {

template <int X, int Y>
class Rect {
 public:
  template <TCellChanger T>
  void operator()(const T& changer, FieldChangerInput& data) {
    for (auto j = 0; j < Y; ++j) {
      for (auto i = 0; i < X; ++i) {
        changer(data.cells[data.position.y + j][data.position.x + i]);
      }
    }
  }
};

template <int Length>
class VerticalLine : Rect<1, Length> {};

template <int Length>
class HorizontalLine : Rect<Length, 1> {};

}  // namespace form

#endif