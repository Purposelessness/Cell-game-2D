#ifndef GAME_VIEW_CONSOLE_WIDGETOBSERVER_H_
#define GAME_VIEW_CONSOLE_WIDGETOBSERVER_H_

namespace console {

    class Widget;

    class WidgetObserver {
    public:
        virtual void onSizeUpdated(Widget* widget) = 0;
    };

}

#endif //GAME_VIEW_CONSOLE_WIDGETOBSERVER_H_