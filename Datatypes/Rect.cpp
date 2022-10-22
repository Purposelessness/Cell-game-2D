#include "Rect.h"

#include <utility>

Rect::Rect() : Rect(Point{}, Point{}) {}

Rect::Rect(Point top_left, Point bottom_right) : top_left(std::move(top_left)), bottom_right(std::move(bottom_right)) {}

Rect::operator std::string() const {
    return "(Rect | top-left: " + static_cast<std::string>(top_left) +
        ", bottom-right: " + static_cast<std::string>(bottom_right) + ")";
}

Size Rect::size() const {
    return Size{width(), height()};
}

int Rect::width() const {
    return bottom_right.x - top_left.x;
}

int Rect::height() const {
    return bottom_right.y - top_left.y;
}

int Rect::top() const {
    return top_left.y;
}

int Rect::right() const {
    return bottom_right.x;
}

int Rect::bottom() const {
    return bottom_right.y;
}

int Rect::left() const {
    return top_left.x;
}

void Rect::setSize(const Size& size) {
    bottom_right.x = top_left.x + size.x;
    bottom_right.y = top_left.y + size.y;
}

void Rect::setTop(int value) {
    int h = height();
    top_left.y = value;
    bottom_right.y = top_left.y + h;
}

void Rect::setLeft(int value) {
    int w = width();
    top_left.x = value;
    bottom_right.x = top_left.x + w;
}

void Rect::setTopLeft(const Point& value) {
    Size s = Size{width(), height()};
    top_left = value;
    bottom_right = top_left + static_cast<Point>(s);
}

void Rect::setBottom(int value) {
    int h = height();
    bottom_right.y = value;
    top_left.y = bottom_right.y - h;
}

void Rect::setRight(int value) {
    int w = width();
    bottom_right.x = value;
    top_left.x = bottom_right.x - w;
}

void Rect::setBottomRight(const Point& value) {
    Size s = Size{width(), height()};
    bottom_right = value;
    top_left = bottom_right - static_cast<Point>(s);
}
