#ifndef GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_
#define GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_

#include <deque>

#include "../../Datatypes/Size.h"
#include "../../Engine/Utility/InfoMessage.h"
#include "Widget.h"

namespace console {

class LogViewWidget : public Widget {
 public:
  LogViewWidget();

  LogViewWidget& operator<<(const InfoMessage& message);

 private:
  std::deque<std::string> _buffer;
  std::string _flush;
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_
