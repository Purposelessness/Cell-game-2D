#ifndef GAME_VIEW_CONSOLE_GRID_H_
#define GAME_VIEW_CONSOLE_GRID_H_

#include <vector>
#include <memory>

#include "Widget.h"
#include "WidgetObserver.h"

namespace console {

    class Grid : public WidgetObserver, public Widget {
    public:
        explicit Grid(WidgetObserver* observer = nullptr);

        void addWidget(std::shared_ptr<Widget> widget);

        void setMargin(const Size& size);

        void onSizeUpdated(Widget* widget) override;

    private:
        WidgetObserver* _observer;
        std::vector<std::shared_ptr<Widget>> _elements;

        Size _margin;
    };

}

#endif //GAME_VIEW_CONSOLE_GRID_H_