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
        SetWindowPos(_hwnd, HWND_TOP, 0, 0, size.x * font_size.X, size.y * font_size.Y, SWP_SHOWWINDOW);
    //    std::string out = "Size of font: " + std::to_string(font_size.X) + " " + std::to_string(font_size.Y);
    //    Log::instance()(out);
    }

}


//void Helper::fitWindowSize() {
//    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(_handle, &screen_buffer_info);
//
//    SHORT window_width = screen_buffer_info.srWindow.Right - screen_buffer_info.srWindow.Left + 1;
//    SHORT window_height = screen_buffer_info.srWindow.Bottom - screen_buffer_info.srWindow.Top + 1;
//
//    SHORT screen_buffer_width = screen_buffer_info.dwSize.X;
//    SHORT screen_buffer_height = screen_buffer_info.dwSize.Y;
//
//    COORD new_size = {screen_buffer_width, window_height};
//    resizeBuffer(new_size);
//}
//
//void Helper::resizeBuffer(const Size& size) {
//    COORD new_size = {static_cast<SHORT>(size.x), static_cast<SHORT>(size.y)};
//    resizeBuffer(new_size);
//}
//
//void Helper::resizeBuffer(const COORD& size) {
//    int status = SetConsoleScreenBufferSize(_handle, size);
//    if (status == 0) {
//        std::string out = "Helper: Cannot set new size of screen: " + std::to_string(GetLastError());
//        Log::instance()(out, Log::Error);
//    }
//    std::string out = "Buffer: " + std::to_string(size.X) + " " + std::to_string(size.Y) + "\n";
//    Log::instance()(out, Log::Info);
//}
//
//void Helper::resizeWindow(const Size& size) {
//    resizeWindow(size.x, size.y);
//}
//
//void Helper::resizeWindow(int width, int height) {
//    SetWindowPos(_hwnd, HWND_TOP, 0, 0, width, height, SWP_SHOWWINDOW);
//    std::string out = "Window: " + std::to_string(width) + " " + std::to_string(height) + "\n";
//    Log::instance()(out, Log::Info);
//}
