#ifndef GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_
#define GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_

#include "Widget.h"
#include "../../Engine/View/ViewMessage.h"
#include "../../Datatypes/Size.h"

namespace console {

    class LogViewWidget : public Widget {
    public:
        LogViewWidget();

        void update(const ViewMessage& message);

    private:
        int _offset = 0;
    };

}


#endif //GAME_VIEW_CONSOLE_LOGVIEWWIDGET_H_