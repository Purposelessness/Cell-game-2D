#include "Application.h"

#include <unistd.h>

#include "../../Utility/Log/Log.h"

Application::Application() : _is_executing(false) {}

int Application::execute(int delta_time) {
  _is_executing = true;
  while (_is_executing) {
    tick();
    usleep(delta_time);
  }
  return 0;
}

void Application::tick() {}

void Application::quit() { _is_executing = false; }
