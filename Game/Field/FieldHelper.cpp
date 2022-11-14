#include "FieldHelper.h"

FieldInfoMessage FieldHelper::info(const Field& field) {
  std::vector<std::pair<Point, CellView>> cells;
  int width = 0;
  int height = 0;
  field.getSize(width, height);
  cells.reserve(width * height);
  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      auto point = Point{i, j};
      cells.emplace_back(point, CellViewRecognizer::use(field.getCell(point)));
    }
  }

  Size size{width, height};
  auto message = FieldInfoMessage{cells, size};

  return message;
}
