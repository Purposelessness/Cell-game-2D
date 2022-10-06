#ifndef GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_
#define GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_

#include <windows.h>

#include "../../Utility/Log.h"
#include "../../Datatypes/Size.h"

class WindowsConsoleHelper {
public:
    WindowsConsoleHelper() : _handle(GetStdHandle(STD_OUTPUT_HANDLE)) {}

    void resizeWindow(const COORD& size);
    void resizeWindow(const Size& size);
    void fitWindowSize();

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
};

#endif //GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_