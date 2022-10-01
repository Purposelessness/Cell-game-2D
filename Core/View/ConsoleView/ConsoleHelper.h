#ifndef GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEHELPER_H_
#define GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEHELPER_H_

#include <windows.h>

class ConsoleHelper {
public:
    static inline void setCursorPosition(int x, int y) {
        coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    static inline void hideCursor() {
        HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info{100, FALSE};
        SetConsoleCursorInfo(console_handle, &info);
    }

private:
    static COORD coord;
};

#endif //GAME_CORE_VIEW_CONSOLEVIEW_CONSOLEHELPER_H_