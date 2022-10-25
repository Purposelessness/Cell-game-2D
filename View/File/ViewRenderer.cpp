#include "ViewRenderer.h"

namespace file {
    ViewRenderer::ViewRenderer() : ViewRenderer("main.log") {}

    ViewRenderer::ViewRenderer(const std::string& filename) : _file(filename) {}

    ViewRenderer::~ViewRenderer() {
        _file.close();
    }


} // file