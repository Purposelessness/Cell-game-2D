#include "Application.h"
#include "../../Utility/Log/Log.h"

#include <unistd.h>

Application::Application() : _is_executing(false) {}

int Application::execute(int delta_time) {
    LOG_INFO_F("Application executed");
    _is_executing = true;
    while (_is_executing) {
        tick();
        usleep(delta_time);
    }
    return 0;
}

void Application::tick() {

}

void Application::quit() {
    _is_executing = false;
    LOG_INFO_F("Application quited");
}
