#ifndef GAME_VIEW_CONSOLE_HELPER_H_
#define GAME_VIEW_CONSOLE_HELPER_H_

#include <windows.h>

#include "../../Utility/Log.h"
#include "../../Datatypes/Size.h"

namespace console {

    class Helper {
    public:
        Helper();

//    void resizeWindow(const Size& size);
//    void resizeWindow(int width, int height);
//    void resizeBuffer(const COORD& size);
//    void resizeBuffer(const Size& size);
//    void fitWindowSize();

        void resize(const Size& size);

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
    };

}

#endif //GAME_VIEW_CONSOLE_HELPER_H_