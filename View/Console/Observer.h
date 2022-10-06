#ifndef GAME_VIEW_CONSOLE_OBSERVER_H_
#define GAME_VIEW_CONSOLE_OBSERVER_H_

namespace console {

    class Observer {
    public:
        virtual void onSizeUpdated() = 0;
    };

}


#endif //GAME_VIEW_CONSOLE_OBSERVER_H_