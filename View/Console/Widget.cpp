#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

#include "Widget.h"

#include <utility>

#include "Observer.h"

namespace console {

    Widget::Widget(Size size, Size margin, Observer* observer)
        : observer(observer), size(std::move(size)), margin(std::move(margin)) {
    }

    Widget::Widget(Observer* observer) : observer(observer), size({}), margin({}) {}

    void Widget::setObserver(Observer* observer) {
        this->observer = observer;
    }

    void Widget::resize(const Size& new_size, bool notify) {
        size = new_size;
        if (observer)
            observer->onSizeUpdated();
    }

    void Widget::resize(int x, int y, bool notify) {
        size.x = x;
        size.y = y;
        if (observer && notify)
            observer->onSizeUpdated();
    }

    void Widget::setMargin(const Size& new_margin, bool notify) {
        margin = new_margin;
        if (observer && notify)
            observer->onSizeUpdated();
    }

    void Widget::setMargin(int x, int y, bool notify) {
        margin.x = x;
        margin.y = y;
        if (observer && notify)
            observer->onSizeUpdated();
    }

    Size Widget::getSize() const {
        return size;
    }

    Size Widget::getMargin() const {
        return margin;
    }

}

#pragma clang diagnostic pop