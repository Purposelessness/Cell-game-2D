#ifndef GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_
#define GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_

#include <memory>

#include "../../Datatypes/Size.h"
#include "../../Message/FieldInfoMessage.h"
#include "Widget.h"

namespace console {

class FieldViewAdapter;

class Helper;

class FieldViewWidget : public Widget {
 public:
  FieldViewWidget& operator<<(const FieldInfoMessage& message);
};

}  // namespace console

#endif  // GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_
