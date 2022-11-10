#ifndef GAME_GAME_FIELD_GENERATOR_FORM_H_
#define GAME_GAME_FIELD_GENERATOR_FORM_H_

#include "Concepts.h"
#include "FieldGenerator.h"

template <typename T, typename Changer>
concept TForm =
    requires { TCellChanger<Changer>; } and
    requires(T t) {
      t(std::declval<const Changer&>(), std::declval<FieldChangerInput&>());
    };

namespace form {

template <int X, int Y, bool Centered = true>
class Rect;

template <int X, int Y>
class Rect<X, Y, true> {
 public:
  template <TCellChanger T>
  void operator()(const T& changer, FieldChangerInput& data) {
    auto width = static_cast<int>(data.cells[0].size());
    auto height = static_cast<int>(data.cells.size());
    auto position = Point{data.position.x - X / 2, data.position.y - Y / 2};
    if (position.x < 0) {
      position.x = 0;
    }
    if (position.y < 0) {
      position.y = 0;
    }

    for (auto j = 0; j < Y; ++j) {
      for (auto i = 0; i < X; ++i) {
        if (position.x + i >= width || position.y + j >= height) {
          continue;
        }
        changer(data.cells[position.y + j][position.x + i]);
      }
    }
  }
};

template <int X, int Y>
class Rect<X, Y, false> {
 public:
  template <TCellChanger T>
  void operator()(const T& changer, FieldChangerInput& data) {
    auto width = static_cast<int>(data.cells[0].size());
    auto height = static_cast<int>(data.cells.size());

    for (auto j = 0; j < Y; ++j) {
      for (auto i = 0; i < X; ++i) {
        if (data.position.x + i >= width || data.position.y + j >= height) {
          continue;
        }
        changer(data.cells[data.position.y + j][data.position.x + i]);
      }
    }
  }
};

template <int Length, bool Centered = true>
class VerticalLine : public Rect<1, Length, Centered> {};

template <int Length, bool Centered = true>
class HorizontalLine : public Rect<Length, 1, Centered> {};

}  // namespace form

#endif
