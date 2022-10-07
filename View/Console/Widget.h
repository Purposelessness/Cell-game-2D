#ifndef GAME_VIEW_CONSOLE_WIDGET_H_
#define GAME_VIEW_CONSOLE_WIDGET_H_

#include <memory>

#include "../../Datatypes/Size.h"
#include "../../Datatypes/Rect.h"

namespace console {

    class WidgetObserver;

    class Widget {
    public:
        explicit Widget(Rect rect = Rect{}, WidgetObserver* observer = nullptr);
        explicit Widget(WidgetObserver* observer);

        void setObserver(WidgetObserver* observer);

        void setRect(const Rect& rect);
        void setTop(int value);
        void setLeft(int value);
        void setTopLeft(const Point& value);
        void setBottom(int value);
        void setRight(int value);
        void setBottomRight(const Point& value);
        void resize(const Size& new_size, bool notify = true);
        void resize(int width, int height, bool notify = true);

        [[nodiscard]] Size getSize() const;

    protected:
        Rect rect;
        WidgetObserver* observer;
    };

}

#endif //GAME_VIEW_CONSOLE_WIDGET_H_