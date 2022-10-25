#ifndef GAME_VIEW_FILE_VIEWRENDERER_H_
#define GAME_VIEW_FILE_VIEWRENDERER_H_

#include <fstream>

#include "../../Message/FieldInfoMessage.h"

namespace file {

    class ViewRenderer {
    public:
        ViewRenderer();
        explicit ViewRenderer(const std::string& filename);
        ~ViewRenderer();

        template<TInfoMessage T>
        inline void update(const T& message);

    private:
        std::ofstream _file;
    };

    template<TInfoMessage T>
    void ViewRenderer::update(const T& message) {

    }

    template<>
    inline void ViewRenderer::update<FieldInfoMessage>(const FieldInfoMessage& message) {}

} // file


#endif //GAME_VIEW_FILE_VIEWRENDERER_H_