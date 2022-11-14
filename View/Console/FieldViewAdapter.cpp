#include "FieldViewAdapter.h"

namespace console {

FieldViewAdapter::Map FieldViewAdapter::symbols{};

void FieldViewAdapter::setMap(Map symbols) {
  FieldViewAdapter::symbols = std::move(symbols);
}

char FieldViewAdapter::encode(CellView type) { return symbols[type]; }

CellView FieldViewAdapter::decode(char c) {
  for (const auto& pair : symbols) {
    if (pair.second == c) {
      return pair.first;
    }
  }
  return CellView::Undefined;
}

}  // namespace console
