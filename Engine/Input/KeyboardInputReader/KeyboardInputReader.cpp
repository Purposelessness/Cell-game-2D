#include "KeyboardInputReader.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#endif

#include "../InputMessage.h"
#include "ControlScheme.h"

// TODO: Linux support

KeyboardInputReader::KeyboardInputReader(ControlScheme& control_scheme) {
  changeControlScheme(control_scheme);
}

void KeyboardInputReader::process() {
#ifdef __linux__
  // Linux code
#elif _WIN32
  for (auto& k : _key_map) {
    bool pressed = keyPressed(k.first);
    if (pressed && (k.second.state == InputState::Released)) {
      k.second.state = InputState::Pressed;
    } else if (!pressed && k.second.state == InputState::Pressed) {
      k.second.state = InputState::Released;
    } else {
      continue;
    }
    event_handler(k.second);
  }
#endif
}

void KeyboardInputReader::changeControlScheme(ControlScheme& control_scheme) {
  for (const auto& kKey : control_scheme.keys()) {
    _key_map[kKey.first] = {kKey.second, InputState::Released};
  }
}

bool KeyboardInputReader::keyPressed(int key) {
#ifdef _WIN32
  static constexpr int kKeyPressed = 0x8000;
  return GetAsyncKeyState(key) & kKeyPressed;
#elif __linux__
  return false;
#endif
}
