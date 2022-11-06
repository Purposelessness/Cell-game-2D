#ifndef GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_
#define GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_

#include <unordered_map>

#include "../../Message/FieldInfoMessage.h"

namespace console {

class FieldViewAdapter {
  using Map = std::unordered_map<CellView, char>;

 public:
  explicit FieldViewAdapter(Map symbols) : symbols(std::move(symbols)) {}

  char symbol(CellView type);
  Map symbols;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_FIELDVIEWADAPTER_H_
