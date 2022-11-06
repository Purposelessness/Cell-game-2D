#ifndef GAME_DATATYPES_VECTOR_H_
#define GAME_DATATYPES_VECTOR_H_

#include "../Utility/IConvertibleToString.h"

struct Vector : public IConvertibleToString {
  explicit Vector(int x = 0, int y = 0);

  explicit operator std::string() const override;
  [[nodiscard]] bool isNull() const;

  Vector& operator+=(const Vector& other);
  Vector operator+(const Vector& other) const;

  int x = 0;
  int y = 0;
};

#endif  // GAME_DATATYPES_VECTOR_H_
