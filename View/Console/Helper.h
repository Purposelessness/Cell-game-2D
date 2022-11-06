#ifndef GAME_VIEW_CONSOLE_HELPER_H_
#define GAME_VIEW_CONSOLE_HELPER_H_

#ifdef _WIN32
#include <windows.h>
#endif  // DEBUG

#include "../../Datatypes/Point.h"
#include "../../Datatypes/Size.h"

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
#ifdef _WIN32
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#endif  // DEBUG
  }

  static inline void hideCursor() {
#ifdef _WIN32
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info{100, FALSE};
    SetConsoleCursorInfo(console_handle, &info);
#endif  // DEBUG
  }

 private:
#ifdef _WIN32
  HANDLE _handle;
  HWND _hwnd;
#endif  // DEBUG
  Size _screen_size;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_HELPER_H_
