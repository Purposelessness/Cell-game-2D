#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

#include "Widget.h"

#include <utility>

#include "WidgetObserver.h"

namespace console {

    Widget::Widget(Rect rect, WidgetObserver* observer)
        : observer(observer), rect(std::move(rect)) {
    }

    Widget::Widget(WidgetObserver* observer) : observer(observer), rect({}) {}

    void Widget::setObserver(WidgetObserver* observer) {
        this->observer = observer;
    }

    void Widget::resize(const Size& new_size, bool notify) {
        rect.setSize(new_size);
        if (observer && notify)
            observer->onSizeUpdated(this);
    }

    void Widget::resize(int x, int y, bool notify) {
        resize(Size{x, y}, notify);
    }

    Size Widget::getSize() const {
        return rect.size();
    }

    void Widget::setRect(const Rect& n_rect) {
        rect = n_rect;
    }

    void Widget::setTop(int value) {
        rect.setTop(value);
    }

    void Widget::setLeft(int value) {
        rect.setLeft(value);
    }

    void Widget::setTopLeft(const Point& value) {
        rect.setTopLeft(value);
    }

    void Widget::setBottom(int value) {
        rect.setBottom(value);
    }

    void Widget::setRight(int value) {
        rect.setRight(value);
    }

    void Widget::setBottomRight(const Point& value) {
        rect.setBottomRight(value);
    }

}

#pragma clang diagnostic pop