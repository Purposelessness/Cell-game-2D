#ifndef GAME_VIEW_CONSOLE_VIEWRENDERER_H_
#define GAME_VIEW_CONSOLE_VIEWRENDERER_H_

#include <memory>

#include "Observer.h"

#include "../../Engine/View/ViewMessage.h"
#include "../FieldViewMessage.h"
#include "FieldViewWidget.h"
#include "LogViewWidget.h"

#include "FieldViewAdapter.h"
#include "Helper.h"

namespace console {

    class ViewRenderer : public Observer, public std::enable_shared_from_this<ViewRenderer> {
    public:
        ViewRenderer();

        template<TViewMessage T>
        inline void update(const T& message);

        // TODO: scan from file
        void setAdapter(const std::shared_ptr<FieldViewAdapter>& adapter);

        void onSizeUpdated() override;

    private:
        std::unique_ptr<FieldViewWidget> _field_view_tab;
        std::unique_ptr<LogViewWidget> _log_view_tab;

        Helper _helper;

        Size _window_size;
    };

    template<TViewMessage T>
    void ViewRenderer::update(const T& message) {
        _log_view_tab->update(message);
    }

    template<>
    inline void ViewRenderer::update<FieldViewMessage>(const FieldViewMessage& message) {
        _field_view_tab->update(message);
    }

}

#endif //GAME_VIEW_CONSOLE_VIEWRENDERER_H_