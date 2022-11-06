#include "Helper.h"

#include <iostream>

#include "../../Utility/Log/Log.h"

namespace console {

#ifdef _WIN32
Helper::Helper()
    : _handle(GetStdHandle(STD_OUTPUT_HANDLE)), _hwnd(GetConsoleWindow()) {
  auto monitor = MonitorFromWindow(_hwnd, MONITOR_DEFAULTTONEAREST);
  MONITORINFO info;
  info.cbSize = sizeof(MONITORINFO);
  GetMonitorInfo(monitor, &info);
  _screen_size =
      Size{static_cast<int>(info.rcMonitor.right - info.rcMonitor.left),
           static_cast<int>(info.rcMonitor.bottom - info.rcMonitor.top)};
}
#endif

void Helper::resizeWindow(const Size& size) {
#ifdef _WIN32
  COORD new_size_in_ch{static_cast<SHORT>(size.x), static_cast<SHORT>(size.y)};
  SetConsoleScreenBufferSize(_handle, new_size_in_ch);
  CONSOLE_FONT_INFO font_info;
  GetCurrentConsoleFont(_handle, FALSE, &font_info);
  COORD font_size = font_info.dwFontSize;
  int width = static_cast<int>(size.x * font_size.X * 1.1);
  int height = static_cast<int>(size.y * font_size.Y * 1.1);
  int x = (_screen_size.x - width) / 2;
  int y = (_screen_size.y - height) / 2;
  SetWindowPos(_hwnd, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
#endif
  fitBuffer();
}

void Helper::fitBuffer() {
#ifdef _WIN32
  CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
  GetConsoleScreenBufferInfo(_handle, &screen_buffer_info);

  int windows_width =
      screen_buffer_info.srWindow.Right - screen_buffer_info.srWindow.Left + 1;
  int windows_height =
      screen_buffer_info.srWindow.Bottom - screen_buffer_info.srWindow.Top + 1;

  COORD new_size = {static_cast<SHORT>(windows_width),
                    static_cast<SHORT>(windows_height)};

  int status = SetConsoleScreenBufferSize(_handle, new_size);
  if (status == 0) {
    LOG_WARNING << "SetConsoleScreenBufferSize() failed! Reason : " +
                       std::to_string(GetLastError()) + '\n';
  }
#endif
}

Size Helper::getScreenSize() { return _screen_size; }

}  // namespace console
