#ifndef GAME_VIEW_CONSOLE_VIEWRENDERER_H_
#define GAME_VIEW_CONSOLE_VIEWRENDERER_H_

#include <memory>

#include "../../Message/FieldInfoMessage.h"
#include "FieldViewAdapter.h"
#include "FieldViewWidget.h"
#include "Grid.h"
#include "Helper.h"
#include "IWidgetObserver.h"
#include "LogViewWidget.h"

namespace console {

class ViewRenderer : public IWidgetObserver,
                     public std::enable_shared_from_this<ViewRenderer> {
 public:
  explicit ViewRenderer(bool logging = true);

  template <TInfoMessage T>
  inline ViewRenderer& operator<<(const T& message);

  void onSizeUpdated(Widget* widget) override;

 private:
  Grid _grid;
  std::shared_ptr<FieldViewWidget> _field_widget;
  std::shared_ptr<LogViewWidget> _log_widget;

  Helper _helper;

  Size _window_size;
};

template <TInfoMessage T>
ViewRenderer& ViewRenderer::operator<<(const T& message) {
  if (_log_widget != nullptr) {
    *_log_widget << message;
  }
  return *this;
}

template <>
inline ViewRenderer& ViewRenderer::operator<< <FieldInfoMessage>(
    const FieldInfoMessage& message) {
  *_field_widget << message;
  return *this;
}

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_VIEWRENDERER_H_
