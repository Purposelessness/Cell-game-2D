#ifndef GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_
#define GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_

#include <windows.h>

#include "../../Utility/Log.h"

class WindowsConsoleHelper {
public:
    WindowsConsoleHelper() : _handle(GetStdHandle(STD_OUTPUT_HANDLE)) {}

    void fitWindowSize() {
        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        GetConsoleScreenBufferInfo(_handle, &screen_buffer_info);

        SHORT window_width = screen_buffer_info.srWindow.Right - screen_buffer_info.srWindow.Left + 1;
        SHORT window_height = screen_buffer_info.srWindow.Bottom - screen_buffer_info.srWindow.Top + 1;

        SHORT screen_buffer_width = screen_buffer_info.dwSize.X;
        SHORT screen_buffer_height = screen_buffer_info.dwSize.Y;

        COORD new_size = {screen_buffer_width, window_height};
        int status = SetConsoleScreenBufferSize(_handle, new_size);
        if (status == 0) {
            Log::instance()("Cannot set new size of screen.", Log::Error);
        }
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
};

#endif //GAME_VIEW_CONSOLEVIEW_WINDOWSCONSOLEHELPER_H_