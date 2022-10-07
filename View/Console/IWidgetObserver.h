#ifndef GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_
#define GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_

namespace console {

    class Widget;

    class IWidgetObserver {
    public:
        virtual void onSizeUpdated(Widget* widget) = 0;
    };

}

#endif //GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_