#ifndef GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_
#define GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_

namespace console {

class Widget;

class IWidgetObserver {
 public:
  virtual ~IWidgetObserver() = default;
  virtual void onSizeUpdated(Widget* widget) = 0;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_IWIDGETOBSERVER_H_
