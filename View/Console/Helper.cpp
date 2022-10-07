#include "Helper.h"

#include <iostream>

namespace console {

    Helper::Helper() : _handle(GetStdHandle(STD_OUTPUT_HANDLE)), _hwnd(GetConsoleWindow()) {}

    void Helper::resizeWindow(const Size& size) {
        COORD new_size_in_ch{static_cast<SHORT>(size.x), static_cast<SHORT>(size.y)};
        SetConsoleScreenBufferSize(_handle, new_size_in_ch);
        CONSOLE_FONT_INFO font_info;
        GetCurrentConsoleFont(_handle, FALSE, &font_info);
        COORD font_size = font_info.dwFontSize;
        SetWindowPos(_hwnd, HWND_TOP, 0, 0,
                     static_cast<int>(size.x * font_size.X * 1.1),
                     static_cast<int>(size.y * font_size.Y * 1.1),
                     SWP_SHOWWINDOW);
        fitBuffer();
    }

    void Helper::fitBuffer() {
        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        GetConsoleScreenBufferInfo(_handle, &screen_buffer_info);

        int windows_width = screen_buffer_info.srWindow.Right - screen_buffer_info.srWindow.Left + 1;
        int windows_height = screen_buffer_info.srWindow.Bottom - screen_buffer_info.srWindow.Top + 1;

        COORD new_size = {static_cast<SHORT>(windows_width), static_cast<SHORT>(windows_height)};

        int status = SetConsoleScreenBufferSize(_handle, new_size);
        if (status == 0) {
            std::string out = "SetConsoleScreenBufferSize() failed! Reason : " + std::to_string(GetLastError()) + '\n';
            Log::instance()(out, Log::Warning);
        }
    }

}