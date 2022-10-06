#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"

#include "ConsoleWindowTab.h"

#include "ConsoleWindowObserver.h"

ConsoleWindowTab::ConsoleWindowTab(const Size& size, const Size& margin, ConsoleWindowObserver* observer)
    : observer(observer) {
    resize(size);
    setMargin(margin);
}

ConsoleWindowTab::ConsoleWindowTab(ConsoleWindowObserver* observer) : observer(observer), size({}), margin({}) {}

void ConsoleWindowTab::setObserver(ConsoleWindowObserver* observer) {
    this->observer = observer;
}

void ConsoleWindowTab::resize(const Size& new_size) {
    size = new_size;
    if (observer)
        observer->onSizeUpdated();
}

void ConsoleWindowTab::resize(int x, int y) {
    size.x = x;
    size.y = y;
    if (observer)
        observer->onSizeUpdated();
}

void ConsoleWindowTab::setMargin(const Size& new_margin) {
    margin = new_margin;
    if (observer)
        observer->onSizeUpdated();
}

void ConsoleWindowTab::setMargin(int x, int y) {
    margin.x = x;
    margin.y = y;
    if (observer)
        observer->onSizeUpdated();
}

Size ConsoleWindowTab::getSize() const {
    return size;
}

Size ConsoleWindowTab::getMargin() const {
    return margin;
}

#pragma clang diagnostic pop