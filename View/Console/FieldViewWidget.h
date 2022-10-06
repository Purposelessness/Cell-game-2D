#ifndef GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_
#define GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_

#include <memory>

#include "Widget.h"
#include "../FieldViewMessage.h"
#include "../../Datatypes/Size.h"

namespace console {

    class FieldViewAdapter;

    class Helper;

    class FieldViewWidget : public Widget {
    public:
        explicit FieldViewWidget(std::shared_ptr<FieldViewAdapter> adapter = nullptr);

        void setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter);
        void update(const FieldViewMessage& message);

    private:
        std::shared_ptr<FieldViewAdapter> _adapter;
    };

}


#endif //GAME_VIEW_CONSOLE_FIELDVIEWWIDGET_H_