#ifndef GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_
#define GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_

#include <unordered_map>

#include "../../Message/FieldInfoMessage.h"

namespace console {

class FieldViewAdapter {
  using Map = std::unordered_map<CellView, char>;

 public:
  static void setMap(Map symbols);
  static char encode(CellView type);
  static CellView decode(char c);
  static Map symbols;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_
