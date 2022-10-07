#ifndef GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_
#define GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_

#include <deque>

#include "Widget.h"
#include "../../Engine/View/ViewMessage.h"
#include "../../Datatypes/Size.h"

namespace console {

    class LogViewWidget : public Widget {
    public:
        void update(const ViewMessage& message);

    private:
        std::deque<std::string> _buffer;
    };

}


#endif //GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_