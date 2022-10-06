#include "WindowsConsoleHelper.h"

void WindowsConsoleHelper::fitWindowSize() {
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(_handle, &screen_buffer_info);

    SHORT window_width = screen_buffer_info.srWindow.Right - screen_buffer_info.srWindow.Left + 1;
    SHORT window_height = screen_buffer_info.srWindow.Bottom - screen_buffer_info.srWindow.Top + 1;

    SHORT screen_buffer_width = screen_buffer_info.dwSize.X;
    SHORT screen_buffer_height = screen_buffer_info.dwSize.Y;

    COORD new_size = {screen_buffer_width, window_height};
    resizeWindow(new_size);
}

void WindowsConsoleHelper::resizeWindow(const Size& size) {
    COORD new_size = {static_cast<SHORT>(size.x), static_cast<SHORT>(size.y)};
    resizeWindow(new_size);
}

void WindowsConsoleHelper::resizeWindow(const COORD& size) {
    int status = SetConsoleScreenBufferSize(_handle, size);
    if (status == 0) {
        Log::instance()("Cannot set new size of screen.", Log::Error);
    }
}