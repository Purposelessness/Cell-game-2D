#ifndef GAME_VIEW_CONSOLE_WIDGET_H_
#define GAME_VIEW_CONSOLE_WIDGET_H_

#include <memory>

#include "../../Datatypes/Rect.h"
#include "../../Datatypes/Size.h"

namespace console {

class IWidgetObserver;

class Widget {
 public:
  explicit Widget(Rect rect = Rect{}, IWidgetObserver* observer = nullptr);
  explicit Widget(IWidgetObserver* observer);
  virtual ~Widget() = default;

  void setObserver(IWidgetObserver* observer);

  void setRect(const Rect& rect);
  void setTop(int value);
  void setLeft(int value);
  void setTopLeft(const Point& value);
  void setBottom(int value);
  void setRight(int value);
  void setBottomRight(const Point& value);
  virtual void resize(const Size& new_size, bool notify = true);
  virtual void resize(int width, int height, bool notify = true);

  [[nodiscard]] Size getSize() const;

 protected:
  Rect rect;
  IWidgetObserver* observer;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_WIDGET_H_
