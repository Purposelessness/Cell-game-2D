#include "MainApplication.h"

#include <unistd.h>

MainApplication::MainApplication() : _is_executing(false) {}

int MainApplication::execute(int delta_time) {
    _is_executing = true;
    while (_is_executing) {
        update();
        usleep(delta_time);
    }
    return 0;
}

void MainApplication::update() {

}

void MainApplication::quit() {
    _is_executing = false;
}
