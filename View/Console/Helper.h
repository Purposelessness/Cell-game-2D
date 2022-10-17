#ifndef GAME_VIEW_CONSOLE_HELPER_H_
#define GAME_VIEW_CONSOLE_HELPER_H_

#include <windows.h>

#include "../../Utility/Log.h"
#include "../../Datatypes/Size.h"
#include "../../Datatypes/Point.h"

namespace console {

    class Helper {
    public:
        Helper();

        void resizeWindow(const Size& size);
        void fitBuffer();

        Size getScreenSize();

        static inline void setCursorPosition(const Point& point) {
            setCursorPosition(point.x, point.y);
        }

        static inline void setCursorPosition(int x, int y) {
            COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

        static inline void hideCursor() {
            HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO info{100, FALSE};
            SetConsoleCursorInfo(console_handle, &info);
        }

    private:
        HANDLE _handle;
        HWND _hwnd;
        Size _screen_size;
    };

}

#endif //GAME_VIEW_CONSOLE_HELPER_H_