#ifndef GAME_VIEW_CONSOLE_WIDGET_H_
#define GAME_VIEW_CONSOLE_WIDGET_H_

#include <memory>

#include "../../Datatypes/Size.h"

namespace console {

    class Observer;

    class Widget {
    public:
        explicit Widget(Size size = Size{}, Size margin = Size{}, Observer* observer = nullptr);
        explicit Widget(Observer* observer);

        void setObserver(Observer* observer);

        void resize(const Size& new_size, bool notify = true);
        void resize(int width, int height, bool notify = true);
        void setMargin(const Size& new_margin, bool notify = true);
        void setMargin(int x, int y, bool notify = true);

        [[nodiscard]] Size getSize() const;
        [[nodiscard]] Size getMargin() const;

    protected:
        Size size;
        Size margin;
        Observer* observer;
    };

}

#endif //GAME_VIEW_CONSOLE_WIDGET_H_