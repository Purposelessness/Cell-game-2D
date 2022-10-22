#ifndef GAME_VIEW_FILE_VIEWRENDERER_H_
#define GAME_VIEW_FILE_VIEWRENDERER_H_

#include "../FieldViewMessage.h"

namespace file {

    class ViewRenderer {
    public:
        template<TViewMessage T>
        inline void update(const T& message);
    };

    template<TViewMessage T>
    void ViewRenderer::update(const T& message) {

    }

} // file


#endif //GAME_VIEW_FILE_VIEWRENDERER_H_