#include "Helper.h"

#include <iostream>

namespace console {

    Helper::Helper() : _handle(GetStdHandle(STD_OUTPUT_HANDLE)), _hwnd(GetConsoleWindow()) {}

    void Helper::resize(const Size& size) {
        COORD new_size_in_ch{static_cast<SHORT>(size.x), static_cast<SHORT>(size.y)};
        SetConsoleScreenBufferSize(_handle, new_size_in_ch);
        CONSOLE_FONT_INFO font_info;
        GetCurrentConsoleFont(_handle, FALSE, &font_info);
        COORD font_size = font_info.dwFontSize;
        SetWindowPos(_hwnd, HWND_TOP, 0, 0,
                     static_cast<int>(size.x * font_size.X * 1.2),
                     static_cast<int>(size.y * font_size.Y * 1.2),
                     SWP_SHOWWINDOW);
    }

}