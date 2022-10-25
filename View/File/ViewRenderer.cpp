#include "ViewRenderer.h"

namespace file {
    ViewRenderer::ViewRenderer() : ViewRenderer("main") {}

#ifdef OBJECT_FILE_LOGGING
    ViewRenderer::ViewRenderer(const std::string& filename)
        : _log_file(filename + ".log"), _object_log_file(filename + ".objects.log") {}
#else
    ViewRenderer::ViewRenderer(const std::string& filename) : _log_file(filename + ".log") {}
#endif

    ViewRenderer::~ViewRenderer() {
        _log_file.close();
#ifdef OBJECT_FILE_LOGGING
        _object_log_file.close();
#endif
    }

#ifdef OBJECT_FILE_LOGGING
    void ViewRenderer::enableObjectLogging(bool value) {
        _enable_object_logging = value;
    }
#endif

} // file