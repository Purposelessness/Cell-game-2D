#ifndef GAME_VIEW_CONSOLE_VIEWRENDERER_H_
#define GAME_VIEW_CONSOLE_VIEWRENDERER_H_

#include <memory>

#include "WidgetObserver.h"

#include "../../Engine/View/ViewMessage.h"
#include "../FieldViewMessage.h"
#include "FieldViewWidget.h"
#include "LogViewWidget.h"

#include "Grid.h"
#include "FieldViewAdapter.h"
#include "Helper.h"

namespace console {

    class ViewRenderer : public WidgetObserver, public std::enable_shared_from_this<ViewRenderer> {
    public:
        ViewRenderer();

        template<TViewMessage T>
        inline void update(const T& message);

        // TODO: scan from file
        void setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter);

        void onSizeUpdated(Widget* widget) override;

    private:
        Grid _grid;
        std::shared_ptr<FieldViewWidget> _field_widget;
        std::shared_ptr<LogViewWidget> _log_widget;

        Helper _helper;

        Size _window_size;
    };

    template<TViewMessage T>
    void ViewRenderer::update(const T& message) {
        _log_widget->update(message);
    }

    template<>
    inline void ViewRenderer::update<FieldViewMessage>(const FieldViewMessage& message) {
        _field_widget->update(message);
    }

}

#endif //GAME_VIEW_CONSOLE_VIEWRENDERER_H_