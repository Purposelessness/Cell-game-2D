#include "KeyboardInputReader.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#endif

#include "ControlScheme.h"
#include "InputMessage.h"

// TODO: Linux support

KeyboardInputReader::KeyboardInputReader(std::shared_ptr<ControlScheme> control_scheme)
    : _control_scheme(std::move(control_scheme)) {}

void KeyboardInputReader::process() {
#ifdef __linux__
    return;
#elif _WIN32
    for (auto& k : _control_scheme->keys()) {
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

void KeyboardInputReader::changeControlScheme(std::shared_ptr<ControlScheme> control_scheme) {
    this->_control_scheme = std::move(control_scheme);
}

constexpr int kKeyPressed = 0x8000;
bool KeyboardInputReader::keyPressed(int key) {
#ifdef _WIN32
    return GetAsyncKeyState(key) & kKeyPressed;
#elif __linux__
    return false;
#endif
}