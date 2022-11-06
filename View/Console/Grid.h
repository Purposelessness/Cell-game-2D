#ifndef GAME_VIEW_CONSOLE_GRID_H_
#define GAME_VIEW_CONSOLE_GRID_H_

#include <memory>
#include <vector>

#include "IWidgetObserver.h"
#include "Widget.h"

namespace console {

class Grid : public IWidgetObserver, public Widget {
 public:
  explicit Grid(IWidgetObserver* observer = nullptr);

  void addWidget(std::shared_ptr<Widget> widget, int row, int column);

  void setSize(int row_count, int column_count);
  void setMargin(const Size& size);

  void onSizeUpdated(Widget* widget) override;

 private:
  Size _grid_size;

  IWidgetObserver* _observer;
  std::vector<std::vector<std::shared_ptr<Widget>>> _elements;

  Size _margin;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_GRID_H_
