#ifndef GAME_DATATYPES_SIZE_H_
#define GAME_DATATYPES_SIZE_H_

#include "../Utility/IConvertibleToString.h"

struct Size : IConvertibleToString {
  explicit Size(int x = 0, int y = 0);

  explicit operator std::string() const override;
  [[nodiscard]] bool isNull() const;

  Size& operator+=(const Size& other);
  Size operator+(const Size& b);
  Size& operator*=(int value);
  Size operator*(int value);

  int x;
  int y;
};

#endif  // GAME_DATATYPES_SIZE_H_
