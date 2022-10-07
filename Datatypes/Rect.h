#ifndef GAME_DATATYPES_RECT_H_
#define GAME_DATATYPES_RECT_H_

#include "../Utility/IConvertibleToString.h"
#include "Point.h"
#include "Size.h"

struct Rect : IConvertibleToString {
    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] Size size() const;

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

    [[nodiscard]] int top() const;
    [[nodiscard]] int right() const;
    [[nodiscard]] int bottom() const;
    [[nodiscard]] int left() const;

    void setSize(const Size& size);
    void setTop(int value);
    void setLeft(int value);
    void setTopLeft(const Point& value);
    void setBottom(int value);
    void setRight(int value);
    void setBottomRight(const Point& value);

    Point top_left;
    Point bottom_right;
};

#endif //GAME_DATATYPES_RECT_H_